#include <iostream>
#include <queue>
using namespace std;

int N,K;
bool visited[100001];
void BFS(int x){
    visited[x]=1;
    queue<pair<int,int>> Q;

    Q.push(make_pair(x,0));
    while(!Q.empty()){
        int x=Q.front().first;
        int cnt=Q.front().second;
        Q.pop();

        if(x==K){
            cout<<cnt<<'\n';
            break;
        }

        if(x+1>=0 && x+1<100001){
            if(!visited[x+1]){
                visited[x+1]=true;
                Q.push(make_pair(x+1,cnt+1));
            }
        }
        if(x-1>=0 && x-1<100001){
            if(!visited[x-1]){
                visited[x-1]=true;
                Q.push(make_pair(x-1,cnt+1));
            }
        }
        if(2*x>=0 && 2*x<100001){
            if(!visited[2*x]){
                visited[2*x]=true;
                Q.push(make_pair(2*x,cnt+1));
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
    BFS(N);
    return 0;
}