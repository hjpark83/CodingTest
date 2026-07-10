/*문제 : https://www.acmicpc.net/problem/9024
  알고리즘 : 정렬, 이분탐색, 투 포인터
  티어 : Gold5
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_NUM 200000000

using namespace std;

int FindAnswer(vector<int>& A, int K){
    int closest=abs(MAX_NUM-K);
    int left=0, right=A.size()-1;
    int count=0;

    while(left<right){
        int currentSum=A[left]+A[right];
        if(abs(currentSum-K)<closest){
            closest=abs(currentSum-K);
            count=1;
        }else if(abs(currentSum-K)==closest){
            count++;
        }

        if(currentSum<K){
            left++;
        }else{
            right--;
        }
    }
    return count;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    while(N--){
        int S,K;
        cin>>S>>K;

        vector<int> A(S,0);
        for(int i=0;i<S;i++){
            cin>>A[i];
        }
        sort(A.begin(),A.end());

        int result=FindAnswer(A,K);
        cout<<result<<'\n';
        A.clear();
    }
    return 0;
}