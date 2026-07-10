/*문제 : https://www.acmicpc.net/problem/12851
  알고리즘 : 그래프, BFS 
  티어 : Gold4
*/

#include <iostream>
#include <queue>
using namespace std;

int N,K;
bool visited[100001];
int cnt[100001];
int ways[100001];

void BFS(int x){
    visited[x]=true;
    queue<int> Q;

    Q.push(x);
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();

        if(x==K){
            cout<<cnt[x]<<'\n';
            cout<<ways[x]<<'\n';
            break;
        }

        if(x+1>=0 && x+1<100001){
            if(!visited[x+1]){
                visited[x+1]=true;
                Q.push(x+1);
                cnt[x+1]=cnt[x]+1;
                ways[x+1]=ways[x];
            }else if(cnt[x+1]==cnt[x]+1){
                ways[x+1]+=ways[x];
            }
        }
        if(x-1>=0 && x-1<100001){
            if(!visited[x-1]){
                visited[x-1]=true;
                Q.push(x-1);
                cnt[x-1]=cnt[x]+1;
                ways[x-1]=ways[x];
            }else if(cnt[x-1]==cnt[x]+1){
                ways[x-1]+=ways[x];
            }
        }
        if(2*x>=0 && 2*x<100001){
            if(!visited[2*x]){
                visited[2*x]=true;
                Q.push(2*x);
                cnt[2*x]=cnt[x]+1;
                ways[2*x]=ways[x];
            }else if(cnt[2*x]==cnt[x]+1){
                ways[2*x]+=ways[x];
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;
    visited[N]=true;
    cnt[N]=0;
    ways[N]=1;
    BFS(N);
    return 0;
}