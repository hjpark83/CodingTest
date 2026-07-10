/*
# Question: BJ 2631 (https://www.acmicpc.net/problem/2631)
# Rank: Gold4
# Algorithm: DP
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 201
using namespace std;

int N;
int Child[MAX];
int DP[MAX];

void Input() {
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>Child[i];
    }
}

int main() {
    fastio
    Input();
    
    int ans = 0;
    fill(DP, DP+MAX, 1);
    for(int i=1;i<=N;i++) {
        for(int j=1;j<i;j++) {
            if(Child[j] < Child[i]) {
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
        ans = max(ans, DP[i]);
    }
    cout<<N-ans<<'\n';
    return 0;
}