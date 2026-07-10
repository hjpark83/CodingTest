#include <iostream>
#include <vector>
#include <cmath>

#define MAX_NUM 100000
using namespace std;

vector<long long> SegTree(4*MAX_NUM);
vector<long long> arr(MAX_NUM);

void init(int node, int start, int end){
    if(start==end){
        SegTree[node]=arr[start];
        return;
    }        

    int mid=(start+end)/2;
    init(2*node,start,mid);
    init(2*node+1,mid+1,end);
    SegTree[node]=SegTree[2*node]+SegTree[2*node+1];
}
void update(int n, int start, int end, int idx, int diff){
    if(start<=idx && idx<=end){
        SegTree[n]+=diff;
    }else{
        return;
    }

    if(start==end)
        return;
    int mid=(start+end)/2;

    update(2*n,start,mid,idx,diff);
    update(2*n+1,mid+1,end,idx,diff);
}
long long sum(int l, int r, int node, int start, int end){
    if(l<=start && end<=r){
        return SegTree[node];
    }else if(r<start || end<=l){
        return 0;
    }

    int mid=(l+r)/2;
    return sum(l,r,2*node,start,mid)+sum(l,r,2*node+1,mid+1,end);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,K;
    cin>>N>>M>>K;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    init(1,1,N);

    for(int i=0;i<(M+K);i++){
        long a,s,e;
        cin>>a>>s>>e;

        if(a==1){
            int diff=e-arr[s];
            arr[s]=e;
            update(1,1,N,s,diff);
        }else if(a==2){
            cout<<sum(s,e,1,1,N)<<'\n';
        }
    }
    return 0;
}