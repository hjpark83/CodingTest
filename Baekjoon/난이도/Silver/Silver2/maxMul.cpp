#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S,K;
    cin>>S>>K;

    long long int result=0;
    if(S%K==0){
        result=pow((S/K),K);
    }else{
        result=pow(S/K,K-S%K)*pow(S/K+1,S%K);
    }
    cout<<result<<'\n';
    return 0;
}