/*문제 : https://www.acmicpc.net/problem/22940
  알고리즘 : Math, Linear Algebra, 가우스 소거법
  티어 : Platinum5
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    vector<vector<double>> Coef(N,vector<double>(N+1));
    // ax + by = c
    for(int i=0; i<N; i++){
        for(int j=0; j<N+1; j++){
            cin>>Coef[i][j];
        }
    }

    // 가우스 소거법
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            double temp = Coef[j][i]; // i행 바로 아래의 행을 임시로 저장
            for(int k=0; k<N+1; k++){
                if(Coef[i][i]==0) 
                    continue;
                else
                    Coef[j][k]-=Coef[i][k]*temp/Coef[i][i]; // i행을 이용하여 j행을 소거
            }
        }
    }

    // 해 구하기
    vector<double> ans(N);
    for(int i=N-1; i>=0; i--){
        double temp = Coef[i][N];
        for(int j=N-1; j>i; j--){
            temp -= Coef[i][j]*ans[j]; // 이미 구한 해를 이용하여 계산
        }
        if(Coef[i][i]==0)
            continue;
        else
            ans[i] = temp/Coef[i][i]; // 계수로 나누어 해를 구함
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}