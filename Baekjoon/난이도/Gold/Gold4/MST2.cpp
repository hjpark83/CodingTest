#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[10001];
int find(int x){
    if(parent[x]==x)
        return x;
    else
        return parent[x]=find(parent[x]);
}
void union_(int x, int y){
    x=find(x);
    y=find(y);

    parent[y]=x;
}
bool sameparent(int x, int y){
    x=find(x);
    y=find(y);

    if(x==y)
        return true;
    else
        return false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E;
    cin>>V>>E;

    vector<pair<int,pair<int,int>>> A;

    for(int i=0;i<E;i++){
        int a,b,c;
        cin>>a>>b>>c;

        A.push_back({c,{a,b}});
    }
    sort(A.begin(),A.end());
    for(int i=0;i<V;i++){
        parent[i]=i;
    }

    int result=0;
    for(int i=0;i<A.size();i++){
        if(!sameparent(A[i].second.first,A[i].second.second)){
            union_(A[i].second.first,A[i].second.second);
            result+=A[i].first;
        }
    }
    cout<<result<<'\n';
    return 0;
}