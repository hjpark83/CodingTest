/*문제 : https://www.acmicpc.net/problem/2252
  알고리즘 : 그래프, 위상 정렬
  티어 : Gold3
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;

    vector<vector<int>> A;
    vector<int> Indegree;
    A.resize(N+1);
    Indegree.resize(N+1);

    for(int i=0;i<M;i++){
        int S,E;
        cin>>S>>E;
        A[S].push_back(E);
        Indegree[E]++;
    }
    queue<int> queue;

    for(int i=1;i<=N;i++){
        if(Indegree[i]==0){
            queue.push(i);
        }
    }
    while(!queue.empty()){
        int now=queue.front();
        queue.pop();

        cout<<now<<" ";
        for(int next:A[now]){
            Indegree[next]--;
            if(Indegree[next]==0){
                queue.push(next);
            }
        }
    }
}