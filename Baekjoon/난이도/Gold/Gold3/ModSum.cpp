/*문제 : https://www.acmicpc.net/problem/10986
  알고리즘 : 수학, 누적합
  티어 : Gold3
*/

#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int N,M;
int cnt=0;
vector<long long> arr(MAX);
vector<long long> Sum;
vector<long long> modNum(1001);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    arr.resize(N);
    Sum.resize(N+1,0);

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=N;i++){
        Sum[i]=(Sum[i-1]+arr[i-1])%M;
        modNum[Sum[i]]++;
    }

    long long cnt=modNum[0];
    for(int i=0;i<M;i++){
        cnt+=((modNum[i]*(modNum[i]-1))/2);
    }
    cout<<cnt<<'\n';
    return 0;
}