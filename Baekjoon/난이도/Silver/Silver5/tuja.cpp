#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H,Y;
    cin>>H>>Y;

    vector<int> dp(Y+1,0);
    dp[0]=H;

    for(int year=1;year<=Y;year++){
        int optionA=static_cast<int>(dp[year-1]*1.05);
        dp[year]=optionA;
        if(year>=3){
            int optionB=static_cast<int>(dp[year-3]*1.2);
            dp[year]=max(dp[year],optionB);
        }
        if(year>=5){
            int optionC=static_cast<int>(dp[year-5]*1.35);
            dp[year]=max(dp[year],optionC);
        }
    }
    cout<<dp[Y]<<'\n';
    return 0;
}