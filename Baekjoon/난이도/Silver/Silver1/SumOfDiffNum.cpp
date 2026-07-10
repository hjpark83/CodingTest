#include <iostream>
#include <vector>

#define MOD 100999;
using namespace std;

int dp[2010][2010]={0};
vector<int> A(21);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int input;
    int max=-1;
    for(int i=1;i<=N;i++){
        cin>>input;
        A[i]=input;
        if(input>max){
            max=input;
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=max;i++){
        dp[0][i]=1;
        dp[i][0]=0;
    }

    for(int i=1;i<=max;i++){
        for(int j=1;j<=max;j++){
            if(i<j){
                dp[i][j]=dp[i][j-1];
            }else{
                dp[i][j]=(dp[i][j-1]+dp[i-j][j-1])%MOD;
            }
        }
    }
    for(int i=1;i<=N;i++){
        int num=A[i];
        cout<<dp[num][num]<<'\n';
    }
    
    return 0;
}