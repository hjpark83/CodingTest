/*문제 : https://www.acmicpc.net/problem/13398
  알고리즘 : DP
  티어 : Gold5
*/
#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int N;
int DP[MAX][2];
int arr[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    DP[0][0]=arr[0];
    DP[0][1]=arr[0];
    int result=arr[0];

    for(int i=1;i<N;i++){
        DP[i][0]=max(DP[i-1][0]+arr[i],arr[i]);
        DP[i][1]=max(DP[i-1][0],DP[i-1][1]+arr[i]);
        result=max(result,max(DP[i][0],DP[i][1]));
    }
    cout<<result<<'\n';
    return 0;
}