/*문제 : https://www.acmicpc.net/problem/1153
  알고리즘 : 수학, 정수론, 소수 판정, 에라토스테네스의 체
  티어 : Gold3
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N+1,1);
    A[0]=A[1]=0;
    vector<int> B;

    for(int i=2;i<=sqrt(N);i++){
        if(A[i]==1){
            for(int j=i*i;j<=N;j+=i){
                A[j]=0;
            }      
        }
    }
    for(int i=2;i<=N;i++){
        if(A[i]==1){
            B.push_back(i);
        }
    }
    for(int i=0;i<B.size();i++){
        for(int j=i;j<B.size();j++){
            for(int k=j;k<B.size();k++){
                for(int l=k;l<B.size();l++){
                    if(B[i]+B[j]+B[k]+B[l]==N){
                        cout<<B[i]<<" "<<B[j]<<" "<<B[k]<<" "<<B[l]<<"\n";
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << -1 << "\n";
    return 0;
}