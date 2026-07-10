#include <iostream>
using namespace std;

int N,target,sum;
int count=0;

int arr[20];

void DFS(int x, int sum){
    if(x==N){
        return;
    }
    if(sum+arr[x]==target){
        count++;
    }

    DFS(x+1,sum);
    DFS(x+1,sum+arr[x]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>target;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    DFS(0,0);
    cout<<count<<'\n';
    return 0;
}