/*문제 : https://www.acmicpc.net/problem/1300
  알고리즘 : 이분탐색
  티어 : Gold1
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin>>N>>K;

    int start=1, end=K;
    int result=0;

    while(1){
        if(start>end){
            break;
        }
        int mid=(start+end)/2;

        int count=0;
        for(int i=1;i<=N;i++){
            count+=min(N,mid/i);
        }
        if(count>=K){
            result=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    
    cout<<result<<'\n';
    return 0;
}