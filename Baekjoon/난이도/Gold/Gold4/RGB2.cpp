/*문제 : https://www.acmicpc.net/problem/17404
  알고리즘 : DP
  티어 : Gold4
*/

#include <iostream>
#include <algorithm>

#define MAX_NUM 999999999
using namespace std;

int house[1001][3];
int cost[1001][3];
int result=MAX_NUM;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    house[0][0]=0;
    house[0][1]=0;
    house[0][2]=0;

    for(int i=1;i<=N;i++){
        cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
    }
    for(int k=0;k<3;k++){
        for(int i=0;i<3;i++){
            if(i==k)
                house[1][i]=cost[1][i];
            else
                house[1][i]=MAX_NUM;
        }
        for(int i=2;i<=N;i++){
            house[i][0]=min(house[i-1][1],house[i-1][2])+cost[i][0];
            house[i][1]=min(house[i-1][0],house[i-1][2])+cost[i][1];
            house[i][2]=min(house[i-1][0],house[i-1][1])+cost[i][2];
        }

        for(int i=0;i<3;i++){
            if(i==k)
                continue;
            else    
                result=min(result,house[N][i]);
        }
    }
    cout<<result<<'\n';
    return 0;
}