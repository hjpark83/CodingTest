/*문제 : https://www.acmicpc.net/problem/11779
  알고리즘 : 그래프 이론, 최단 경로, Dijkstre
  티어 : Gold3
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
#define INF 1e9
using namespace std;

int N,M,x,y,z;

vector<pair<int,int>> A[MAX];
vector<int> arr;
int route[MAX];
int dist[MAX];

void Dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start]=0;
    pq.push({0, start});

    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        if(dist[cur]<cost)
            continue;

        for(int i=0;i<A[cur].size();i++){
            int next=A[cur][i].first;
            int nextcost=cost+A[cur][i].second;

            if(nextcost<dist[next]){
                route[next]=cur;
                dist[next]=nextcost;
                pq.push({dist[next],next});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i=0;i<M;i++){
        cin>>x>>y>>z;
        A[x].push_back({y,z});
    }

    int start,end;
    cin>>start>>end;

    fill(dist,dist+N+1, INF);
    Dijkstra(start);

    int idx=end;
    while(1){
        if(route[idx]==0){
            arr.push_back(start);
            break;
        }
        arr.push_back(idx);
        idx=route[idx];
    }

    reverse(arr.begin(),arr.end());

    cout<<dist[end]<<'\n';
    cout<<arr.size()<<'\n';
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}