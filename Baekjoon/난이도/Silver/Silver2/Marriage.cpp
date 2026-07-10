#include <iostream>
#include <queue>
#define MAX 501
using namespace std;

int N, M, cnt=0;
int Graph[MAX][MAX]={0};
bool visited[MAX]={false,};
int depth[MAX]={0};
queue<int> Q;

void BFS(int num){
    Q.push(num);
    visited[num]=true;
    while(!Q.empty()){
        int Cur=Q.front();
        Q.pop();

        for(int i=1;i<=N;i++){
            int Next=Graph[Cur][i];
            if(visited[i] || Graph[Cur][i]==0){
                continue;
            }
            Q.push(i);
            visited[i]=true;
            depth[i]=depth[Cur]+1;
            if(depth[i]>2){
                continue;
            }
            cnt++;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    cin>>M;

    for(int i=1;i<=M;i++){
        int a,b;
        cin>>a>>b;
        Graph[a][b]=1;
        Graph[b][a]=1;
    }
    BFS(1);
    cout<<cnt<<'\n';
    return 0;
}