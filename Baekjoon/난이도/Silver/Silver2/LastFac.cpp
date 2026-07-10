#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin>>N;

    long long answer=1;
    for(int i=1;i<=N;i++){
        answer*=i;
        answer%=10000000;
        while(answer%10==0){
            answer/=10;
        }
    }
    cout<<answer%10<<'\n';
    return 0;
}