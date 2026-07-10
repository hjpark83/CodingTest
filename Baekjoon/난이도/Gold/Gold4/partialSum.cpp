/*문제 : https://www.acmicpc.net/problem/1806
  알고리즘 : 누적 합, 투 포인터
  티어 : Gold4
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,S;
    cin>>N>>S;
    
    vector<int> A(N);

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int min_count=N+1;
    int start=0, end=0;
    int sum=0;

    while(end<N){
        sum+=A[end];

        while(sum>=S){
            min_count=min(min_count,end-start+1);
            sum-=A[start];
            start++;
        }
        end++;
    }
    if(min_count>N){
        cout<<0<<'\n';
    }else{
        cout<<min_count<<'\n';
    }
    return 0;
}