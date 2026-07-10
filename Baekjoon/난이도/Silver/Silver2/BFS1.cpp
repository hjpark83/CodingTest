#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 200000
using namespace std;

vector<int> Graph[MAX];
int check[MAX];

void BFS(int v){
    int visit=1;
    queue<int> Q;
    Q.push(v);
    check[v]=visit++;

    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();
        for(int i=0;i<Graph[cur].size();i++){
            int next=Graph[cur][i];
            if(check[next]==0){
                check[next]=visit++;
                Q.push(next);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,R;
    cin>>N>>M>>R;

    for(int i=1;i<=M;i++){
        int s,e;
        cin>>s>>e;
        Graph[s].push_back(e);
        Graph[e].push_back(s);
    }
    for(int i=1;i<=N;i++){
        sort(Graph[i].begin(), Graph[i].end());
    }
    BFS(R);
    for(int i=1;i<=N;i++){
        cout<<check[i]<<'\n';
    }
    return 0;
}