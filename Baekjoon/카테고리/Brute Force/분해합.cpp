/*
# Question: BJ 2231 (https://www.acmicpc.net/problem/2231)
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

    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        int sum=i;
        int tmp=i;

        while(tmp){
            sum += tmp % 10;
            tmp /=10;
        }

        if(sum == N){
            cout << i << '\n';
            return 0;
        }
    }
    cout << "0\n";
    
    return 0;
}