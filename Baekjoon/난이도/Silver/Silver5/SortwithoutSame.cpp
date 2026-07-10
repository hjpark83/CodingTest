#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& A, int p, int mid, int r){
    int i=p, j=mid+1, t=0;
    int tmp[r-p+1];

    while(i<=mid && j<=r){
        if(A[i]<=A[j]){
            tmp[t++]=A[i++];
        }else{
            tmp[t++]=A[j++];
        }
    }
    while(i<=mid){
        tmp[t++]=A[i++];
    }
    while(j<=r){
        tmp[t++]=A[j++];
    }

    for(int k=p,t=0;k<=r;k++,t++){
        A[k]=tmp[t];
    }
}
void MergeSort(vector<int>& A, int p, int r){
    if(p<r){
        int mid=(p+r)/2;
        MergeSort(A,p,mid);
        MergeSort(A,mid+1,r);
        Merge(A,p,mid,r);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N,0);

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    MergeSort(A,0,N-1);
    for(int i=0;i<N;i++){
        if(A[i]==A[i+1])
            continue;
        cout<<A[i]<<" ";
    }
    return 0;
}