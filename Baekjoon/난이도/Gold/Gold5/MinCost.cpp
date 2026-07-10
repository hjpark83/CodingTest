/*문제 : https://www.acmicpc.net/problem/1916
  알고리즘 : 그래프, 다익스트라
  티어 : Gold5
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001
#define INF 1e9

vector<pair<int,int>> A[MAX];
int start,destination;
int Distance[MAX];

void Dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    Distance[start]=0;

    while(!pq.empty()){
        int cost=-pq.top().first;
        int now=pq.top().second;
        pq.pop();

        if(Distance[now]<cost)
            continue;

        for(int i=0;i<A[now].size();i++){
            int next=A[now][i].first;
            int nCost=cost+A[now][i].second;
            if(Distance[next]>nCost){
                Distance[next]=nCost;
                pq.push(make_pair(-nCost,next));
            }
        }
    }
    cout<<Distance[destination]<<'\n';
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;

    for(int i=0;i<M;i++){
        int from,to,cost;
        cin>>from>>to>>cost;
        A[from].push_back(make_pair(to,cost));
    }
    cin>>start>>destination;
    for(int i=1;i<=N;i++){
        Distance[i]=INF;
    }
    Dijkstra(start);
    return 0;
}