/*문제 : https://www.acmicpc.net/problem/1253
  알고리즘 : 자료구조, 정렬, 이분탐색, 투 포인터
  티어 : Gold4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    vector<int> A(N,0);

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    int Result=0;

    for(int k=0;k<N;k++){
        long find=A[k];
        int i=0;
        int j=N-1;

        while(i<j){
            if(A[i]+A[j]==find){
                if(i!=k && j!=k){
                    Result++;
                    break;
                }else if(i==k){
                    i++;
                }else if(j==k){
                    j--;
                }
            }else if(A[i]+A[j]<find){
                i++;
            }else if(A[i]+A[j]>find){
                j--;
            }else{
                j--;
            }
        }
    }
    cout<<Result<<'\n';
    return 0;
}