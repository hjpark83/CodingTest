#include <iostream>
#include <vector>
#define MAX 31
using namespace std;

int N;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;

    vector<int> DP(MAX);

    DP[0]=1;
    DP[1]=0;
    DP[2]=3;
    for(int i=3;i<=N;i++){
        if(i%2!=0){
            DP[i]=0; 
        }else{
            for(int j=2;j<=N;j+=2){
                if(j==2){
                    DP[i]=DP[i-j]*3;
                }else if(i>=j){
                    DP[i]+=DP[i-j]*2;
                }
            }
        }
    }
    cout<<DP[N]<<'\n';
    return 0;
}