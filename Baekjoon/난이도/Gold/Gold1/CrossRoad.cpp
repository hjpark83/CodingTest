/*
# Question: BJ 24042 (https://www.acmicpc.net/problem/24042)
# Rank: Gold1
# Algorithm: Graph, Dijkstra, Shortest Path
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 100001
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

int N, M;
vector<vector<pil>> Area;
vector<ll> dist;

void Input() {
    cin>>N>>M;
    Area.resize(N+1);
    dist.resize(N+1, 1e18);
    for(int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        Area[a].push_back({b, i});
        Area[b].push_back({a, i});
    }
}

void Dijkstra(){
    priority_queue<pli> pq;
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        ll cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(auto &i : Area[cur]){
            int nextNode = i.first;
            ll nextCost = cost;
            if (i.second - cost < 0){
                nextCost += ((i.second - cost) % M + M) % M;
            }else{
                nextCost += (i.second - cost) % M;
            }
            nextCost += 1;
            /* 기존 cost + 주기만큼 기다려야하는 경우 고려 + 이동 시간
            ex) 1->6인 경우 (6-1)+1을 해야 기다리는 시간 + 이동시간(1)이 성립함 */
            if(dist[nextNode] > nextCost){
                dist[nextNode] = nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
    }
    cout<<dist[N];
}

int main() {
    fastio
    Input();
    Dijkstra();

    return 0;
}