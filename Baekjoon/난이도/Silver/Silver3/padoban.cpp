#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int T;
long long DP[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;
    long long ans[T];

    DP[1]=1;
    DP[2]=1;
    DP[3]=1;
    DP[4]=2;
    DP[5]=2;

    for(int t=0;t<T;t++){
        cin>>ans[t];
        for(int i=6;i<MAX;i++){
            DP[i]=DP[i-1]+DP[i-5];
        }
        cout<<DP[ans[t]]<<'\n';
    }
    return 0;
}