#include <iostream>
#include <cstdlib>
using namespace std;

int N,K;
int count=0;

void Merge(int* A, int p, int mid, int r, int K){
    int i=p, j=mid+1, t=1;
    int tmp[r+2];
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

    i=p;
    t=1;

    while(i<=r){
        A[i++]=tmp[t++];
        if(++count==K){
            for(int i=0;i<N;i++){
                cout<<A[i]<<" ";
            }
        }
    }
}

void MergeSort(int* A, int p, int r, int K){
    if(p<r){
        int mid=(p+r)/2;
        MergeSort(A,p,mid,K);
        MergeSort(A,mid+1,r,K);
        Merge(A,p,mid,r,K);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;
    int* A=new int[N];

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    MergeSort(A,0,N-1,K);
    if(count<K)
        cout<<-1<<'\n';
    
    delete []A;
    return 0;
}