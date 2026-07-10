/*
# Question: BJ 11478 (https://www.acmicpc.net/problem/11478)
# Rank: Silver 3
# Algorithm: Data Structure, String, Hashing, Set, Map, Tree
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

    string S;
    cin >> S;
    
    set<string> substrings;
    for (int i = 0; i < S.length(); i++) {
        for (int j = 1; j <= S.length() - i; j++) {
            substrings.insert(S.substr(i, j));
        }
    }
    
    cout << substrings.size() << "\n";
    
    return 0;
}