#include <iostream>
using namespace std;

int main(void){
    int N,M;
    cin>>N>>M;
    char arr[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=M-1;j>=0;j--){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
    return 0;
}