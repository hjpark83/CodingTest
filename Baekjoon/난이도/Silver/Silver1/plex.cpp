#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int N;
int Map[26][26];
vector<int> A;
bool visited[26][26]={false};


void BFS(int start_x, int start_y){
    queue<pair<int,int>> Q;
    Q.push(make_pair(start_x,start_y));
    visited[start_x][start_y]=true;

    int cnt=0;

    while(!Q.empty()){
        int x=Q.front().first;
        int y=Q.front().second;
        cnt++;
        Q.pop();

        for(int i=0;i<4;i++){
            int next_x=x+dx[i];
            int next_y=y+dy[i];
            if(next_x>=0 && next_x<N && next_y>=0 && next_y<N){
                if(visited[next_x][next_y]==false && Map[next_x][next_y]==1){
                    Q.push(make_pair(next_x,next_y));
                    visited[next_x][next_y]=true;
                }
            }
        }
    }
    A.push_back(cnt);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    string str;
    for(int i=0;i<N;i++){
        cin>>str;
        for(int j=0;j<N;j++){
            Map[i][j]=str[j]-'0';
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]==false && Map[i][j]==1){
                BFS(i,j);
            }
        }
    }
    sort(A.begin(),A.end());
    cout<<A.size()<<'\n';
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<'\n';
    }
    return 0;
}