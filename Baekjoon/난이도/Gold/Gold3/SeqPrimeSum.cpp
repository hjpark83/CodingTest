/*문제 : https://www.acmicpc.net/problem/1644
  알고리즘 : 수학, 정수론, 투 포인터, 소수 판정, 에라토스테네스의 체
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

    vector<bool> A(N+1,1);
    vector<int> B;

    A[0]=A[1]=0;

    for(int i=2;i<=sqrt(N);i++){
        if(A[i]==0){
            continue;
        }
        for(int j=i*i;j<=N;j+=i){
            A[j]=0;
        }
    }
    for(int i=2;i<=N;i++){
        if(A[i]==1){
            B.push_back(i);
        }
    }

    int sum=0;
    int count=0;
    int right=0, left=0;
    while(1){
        if(sum<N){
            if(right>=B.size()){
                break;
            }
            sum+=B[right];
            right++;
        }else if(sum>N){
            sum-=B[left];
            left++;
        }else if(sum==N){
            count++;
            if(right>=B.size()){
                break;
            }
            sum+=B[right];
            right++;
        }
    }
    cout<<count<<'\n';
    return 0;
}