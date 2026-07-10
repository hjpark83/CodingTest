/*
# Question: BJ 22988 (https://www.acmicpc.net/problem/22988)
# Rank: Gold2
# Algorithm: Greedy, Sorting, Two pointers
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001
using namespace std;
typedef long long ll;

ll N, X, ans;
vector<ll> C;

void Input(){
    cin>>N>>X;
    C.resize(N);
    for(int i=0; i<N; i++){
        cin>>C[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();

    sort(C.begin(), C.end());
    
    ll left = 0, right = N-1, remain=0;
    while(C[right]>=X && right>=0){
        right--;
        ans++;
    }
    while(left<=right){
        if(left<right && C[right]+C[left]>=(X+1)/2){
            right--;
            left++;
            ans++;
        }else{
            left++;
            remain++;
        }
    }
    cout<<ans+remain/3<<'\n';
    return 0;
}