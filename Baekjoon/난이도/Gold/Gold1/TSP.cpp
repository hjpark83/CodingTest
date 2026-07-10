/*문제 : https://www.acmicpc.net/problem/2098
  알고리즘 : 비트마스킹, DP
  티어 : Gold1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N,E;
int cost[16][16];
int DP[16][1<<16];

int TSP(int now, int visited){
    if(visited==E){
        if(cost[now][0]>0)
            return cost[now][0];
        return INF;
    } 
    // 모든 노드를 방문했는데 현재 노드에서 0번으로 가는 경로가 있다면 최소 비용 반환
    if(DP[now][visited]!=0)
        return DP[now][visited];
    DP[now][visited]=INF;

    for(int i=0;i<N;i++){
        if(cost[now][i]==0)
            continue;
        if(visited & (1<<i))
            continue;
        int temp=TSP(i,visited | 1<<i);
        DP[now][visited]=min(DP[now][visited],cost[now][i]+temp);
    }
    return DP[now][visited];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    E=(1<<N)-1;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>cost[i][j];
        }
    }
    cout<<TSP(0,1)<<'\n';
    return 0;
}