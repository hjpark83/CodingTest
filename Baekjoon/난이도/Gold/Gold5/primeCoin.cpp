/*문제 : https://www.acmicpc.net/problem/16400
  알고리즘 : 수학, DP, 정수론, 소수판정, 에라토스테네스의 체
  티어 : Gold5
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 40001
#define MOD 123456789
using namespace std;

int N;
vector<int> A(MAX+1,1);
vector<int> B;
long long DP[MAX]={0,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    A[0]=A[1]=0;
    for(int i=2;i<=sqrt(MAX);i++){
        if(A[i]==1){
            for(int j=i*i;j<=MAX;j+=i){
                A[j]=0;
            }
        }
    }
    for(int i=2;i<=MAX;i++){
        if(A[i]==1){
            B.push_back(i);
        }
    }
    DP[0]=1;
    for(int i=0;i<B.size();i++){
        for(int j=B[i];j<=N;j++){
            DP[j]+=(DP[j-B[i]])%MOD;
            DP[j]%=MOD;
        }
    }
    cout<<DP[N]<<'\n';
    return 0;
}  