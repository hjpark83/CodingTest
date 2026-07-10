#include <iostream>

#define INF 1e9
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;

    int graph[101][101];

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]=INF;
        }
    }
    
    for(int i=0;i<M;i++){
        int me,frd;
        cin>>me>>frd;
        graph[me][frd]=graph[frd][me]=1;
    }

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i==j)
                    continue;
                else if(graph[i][k]!=0 && graph[k][j]!=0){
                    if(graph[i][j]==0)
                        graph[i][j]=graph[i][k]+graph[k][j];
                    else
                        graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
    }
    
    int result=INF;
    int person;

    for(int i=1;i<=N;i++){
        int sum=0;
        for(int j=1;j<=N;j++)
            sum+=graph[i][j];

        if(result>sum){
            result=sum;
            person=i;
        }
    }
    cout<<person<<'\n';
    return 0;
}