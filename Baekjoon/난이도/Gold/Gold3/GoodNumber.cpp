/*
# Question: BJ 5624 (https://www.acmicpc.net/problem/5624)
# Rank: Gold3
# Algorithm: DP
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 400001
using namespace std;

int N;
vector<int> v;
int DP[MAX];

void Input() {
    cin>>N;
    v.resize(N);
    for(int i=0; i<N; i++){
        cin>>v[i];
    }
}

int main() {
    fastio
    Input();

    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(DP[v[i]-v[j]+200000] != 0){
                ans++;
                break;
            }
        }

        for(int j=0; j<=i; j++){
            DP[v[i]+v[j]+200000] = 1;
        }
    }

    cout<<ans<<'\n';
    return 0;
}