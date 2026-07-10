/*문제 : https://www.acmicpc.net/problem/1956
  알고리즘 : 그래프, 플로이드-워셜
  티어 : Gold4
*/

#include <iostream>
#include <vector>

#define INF 100000000
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E;
    cin>>V>>E;

    int mDistance[401][401]={0,};
    int start,end,length;

    for(int i=0;i<E;i++){    
        cin>>start>>end>>length;
        mDistance[start][end]=length;
    }
    
    for(int k=1;k<=V;k++){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                if(mDistance[i][k] && mDistance[k][j]){
                    if(mDistance[i][j]!=0)
                        mDistance[i][j]=min(mDistance[i][j],mDistance[i][k]+mDistance[k][j]);
                    else
                        mDistance[i][j]=mDistance[i][k]+mDistance[k][j];
                }
            }
        }
    }

    int answer=INF;
    int isCycle=0;
    for(int i=1;i<=V;i++){
        if(mDistance[i][i]!=0){
            answer=min(answer,mDistance[i][i]);
            isCycle=1;
        }
    }

    if(isCycle==0)
        cout<<"-1"<<'\n';
    else
        cout<<answer<<'\n';
    return 0;
}
