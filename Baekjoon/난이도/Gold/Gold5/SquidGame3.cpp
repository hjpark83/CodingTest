/*문제 : https://www.acmicpc.net/problem/13549
  알고리즘 : 그래프, BFS, 다익스트라
  티어 : Gold5
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N,K;
bool visited[100001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void BFS(int start, int destination){
    pq.push({0,start});
    
    while(!pq.empty()){
        int t=pq.top().first;
        int x=pq.top().second;
        pq.pop();

        visited[x]=1;
        if(x==K){
            cout<<t<<'\n';
            break;
        }

        if(x+1<100001 && !visited[x+1]){
            pq.push(make_pair(t+1,x+1));
        }
        if(x-1>=0 && !visited[x-1]){
            pq.push(make_pair(t+1,x-1));
        }
        if(x*2<100001 && !visited[x*2]){
            pq.push(make_pair(t,x*2));
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;
    BFS(N,K);
    return 0;
}