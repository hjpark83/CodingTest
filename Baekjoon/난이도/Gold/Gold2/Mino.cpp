/*문제 : https://www.acmicpc.net/problem/1507
  알고리즘 : Graph, Floyd-Warshall
  티어 : Gold2
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dist[21][21];
bool check[21][21];

void FloydWarshall(){
    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){              
                if (i == k || j == k || i == j) 
                    continue;
                
                if (dist[i][j] == dist[i][k] + dist[k][j]){ 
                    // i->j로 가는 최단경로가 i->k->j로 가는 최단경로와 같다면
                    check[i][j] = true;
                }else if (dist[i][j] > dist[i][k] + dist[k][j]){ 
                    // i->j로 가는 최단경로가 i->k->j로 가는 최단경로보다 크다면
                    cout<<-1<<'\n';
                    exit(0);
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>dist[i][j];
        }
    }

    FloydWarshall();

    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!check[i][j]){ 
                // i->j로 가는 최단경로가 i->k->j로 가는 최단경로와 같지 않다면
                ans += dist[i][j];
            }
        }
    }
    cout<<ans/2<<'\n'; // 중복되는 경우를 제외하기 위해 2로 나눔
    return 0;
}