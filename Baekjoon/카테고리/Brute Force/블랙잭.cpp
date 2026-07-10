/*
# Question: BJ 2798 (https://www.acmicpc.net/problem/2798)
# Rank: Bronze 2
# Algorithm: Brute Force
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//const int INF = 1e9;

int main() {
    fastio

    int N, M;
    cin >> N >> M;

    vector<int> cards(N);
    for(int i=0; i<N; i++){
        cin >> cards[i];
    }
    int ans = 0;
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                int sum = cards[i] + cards[j] + cards[k];
                if(sum <= M){
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}