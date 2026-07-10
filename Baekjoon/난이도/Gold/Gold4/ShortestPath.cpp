/*문제 : https://www.acmicpc.net/problem/1753
  알고리즘 : 그래프 이론, Dijkstra, 최단 경로
  티어 : Gold4
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 20005
#define INF 1e9
using namespace std;

vector<pair<int,int>> node[MAX];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int val[MAX];

int V,E,start;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V>>E;
    cin>>start;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        node[u].push_back(make_pair(v,w));
    }

    for(int i=1;i<=V;i++){
        val[i]=INF;
    }
    val[start]=0;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int x=pq.top().first;
        int y=pq.top().second;
        pq.pop();

        for(int i=0;i<node[y].size();i++){
            int V=node[y][i].first;
            int W=node[y][i].second;

            if(x+W<val[V]){
                val[V]=x+W;
                pq.push(make_pair(x+W,V));
            }
        }
    }
    for(int i=1;i<=V;i++){
        if(val[i]==INF){
            cout<<"INF"<<'\n';
        }else{
            cout<<val[i]<<'\n';
        }
    }
    return 0;
}