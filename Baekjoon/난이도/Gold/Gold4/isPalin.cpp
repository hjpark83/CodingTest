/*문제 : https://www.acmicpc.net/problem/10942
  알고리즘 : 다이나믹 프로그래밍
  티어 : Gold4
*/

#include <iostream>
using namespace std;

int N,M;;
int A[2001];
bool Palin[2001][2001]={false,};

void isPalin(int N){
    for(int i=1;i<=N;i++){
        Palin[i][i]=true;
    } // 한 자리 숫자는 모두 palindrome
    for(int i=1;i<=N-1;i++){
        if(A[i]==A[i+1])
            Palin[i][i+1]=true;
    } // 한 숫자가 연속으로 2번 나온 경우
    for(int i=N-1;i>=1;i--){
        for(int j=i+2;j<=N;j++){
            if(A[i]==A[j] && Palin[i+1][j-1]==true){
                Palin[i][j]=true;
            }
        }
    } // 나머지 경우
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    cin>>M;
    isPalin(N);
    for(int i=0;i<M;i++){
        int start, end;
        cin>>start>>end;
        cout<<Palin[start][end]<<'\n';
    }
    return 0;
}