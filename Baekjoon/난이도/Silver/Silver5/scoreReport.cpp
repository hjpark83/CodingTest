#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, minA, minB, result, min;
    cin>>N;
    min=1000000000;

    long long X[100];
    long long Y[100];

    for(int i=0;i<N;i++){
        cin>>X[i]>>Y[i];
    }
    for(int a=1;a<=100;a++){
        for(int b=1;b<=100;b++){
            result=0;
            for(int i=0;i<N;i++){
                result+=(Y[i]-(a*X[i]+b))*(Y[i]-(a*X[i]+b));
            }
            if(result<min){
                min=result;
                minA=a;
                minB=b;
            }
        }
    }
    cout<<minA<<" "<<minB<<endl;
    return 0;
}