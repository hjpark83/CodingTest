/*문제 : https://www.acmicpc.net/problem/11780
  알고리즘 : 그래프, 플로이드 워셜
  티어 : Gold2
*/

#include <iostream>
#include <vector>

#define MAX 110
#define INF 1e9
using namespace std;

int N,M;
int Cost[MAX][MAX];
int Route[MAX][MAX];
vector<int> V;

void Floyd_Warshall(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i==j)
                    continue;
                if(Cost[i][j]>Cost[i][k]+Cost[k][j]){
                    Cost[i][j]=Cost[i][k]+Cost[k][j];
                    Route[i][j]=k;
                }
            }
        }
    }
}

void Find_Route(int s, int e){
    if(Route[s][e]==0){
        V.push_back(s);
        V.push_back(e);
        return;
    }
    Find_Route(s, Route[s][e]);
    V.pop_back();
    Find_Route(Route[s][e], e);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            Cost[i][j]=INF;
        }
    }

    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Cost[a][b]=min(Cost[a][b],c);
    }

    Floyd_Warshall();

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(Cost[i][j]==INF)
                cout<<"0"<<" ";
            else
                cout<<Cost[i][j]<<" ";
        }
        cout<<'\n';
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(Cost[i][j]==INF)
                cout<<0;
            else{
                V.clear();
                Find_Route(i,j);
                cout<<V.size()<<" ";
                for(int k=0;k<V.size();k++){
                    cout<<V[k]<<" ";
                }
            }
            cout<<'\n';
        }
    }
    return 0;
}