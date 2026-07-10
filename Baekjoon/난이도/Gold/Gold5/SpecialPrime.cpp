#include <iostream>
using namespace std;

int N=0;

bool checked(int N){
    for(int i=2;i*i<=N;i++){
        if(N%i==0){
            return false;
        }
    }
    return true;
}

void DFS(int num, int len){
    if(len==N){
        cout<<num<<'\n';
        return;
    }

    for(int i=1;i<=9;i++){
        if(checked(num*10+i))
            DFS(num*10+i,len+1);
    }
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    DFS(2,1);
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);

    return 0;
}