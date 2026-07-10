/*문제 : https://www.acmicpc.net/problem/14938
  알고리즘 : 그래프, 다익스트라, 플로이드-워셜
  티어 : Gold4
*/

#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,R;
    cin>>N>>M>>R;

    int mDistance[101][101];
    int max_len[101];

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j)
                mDistance[i][j]=0;
            else
                mDistance[i][j]=INF;
        }
    }

    vector<int> Item(N+1);
    for(int i=1;i<=N;i++){
        cin>>Item[i];
    }

    for(int i=1;i<=R;i++){
        int Start,End,Length;
        cin>>Start>>End>>Length;

        mDistance[Start][End]=Length;
        mDistance[End][Start]=Length;
    }

    int result=0;
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(mDistance[i][j]>mDistance[i][k]+mDistance[k][j]){
                    mDistance[i][j]=mDistance[i][k]+mDistance[k][j];
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
		max_len[i]=Item[i];
		for(int j=1;j<=N;j++){
			if(mDistance[i][j]<=M && i!=j){
				max_len[i]+=Item[j];
			}
		}
		result=max(result,max_len[i]);
	}
    cout<<result<<'\n';
    return 0;
}