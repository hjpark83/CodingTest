#include <iostream>
using namespace std;

int main(void){
    int N,M;
    cin>>N>>M;

    int *num=new int[N];
    for(int i=0;i<N;i++){
        num[i]=0;
    }

    for(int i=0;i<M;i++){
        int start,end,ball;
        cin>>start>>end>>ball;

        for (int j=start-1;j<=end-1;j++){
            num[j]=ball;
        }
    }

    for(int i=0;i<N;i++){
        cout<<num[i]<<" ";
    }

    delete[]num;
    return 0;
}
