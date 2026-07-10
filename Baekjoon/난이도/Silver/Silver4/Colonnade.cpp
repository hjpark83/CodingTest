#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int N;
int gap=0;
int cnt=0;

int A[MAX];
int dist[MAX];

int GCD(int x, int y){
    if(y==0){
        return x;
    }else{
        return GCD(y,x%y);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    sort(A,A+N); // 거리 순으로 정렬

    for(int i=0;i<N-1;i++){
        dist[i]=A[i+1]-A[i];
    }

    gap=dist[0];
    for(int i=0;i<N-1;i++){
        gap=GCD(gap,dist[i]);
    }

    for(int i=0;i<N-1;i++){
        cnt+=(dist[i]/gap)-1;
    }
    cout<<cnt<<'\n';
    return 0;    
}