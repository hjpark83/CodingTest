/*
# Question: BJ 1764 (https://www.acmicpc.net/problem/1764)
# Rank: Silver 4
# Algorithm: Data Structure, String, Sorting, Map, Set, Hashing
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

    set<string> S;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        S.insert(name);
    }

    vector<string> result;
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;
        if (S.find(name) != S.end()) {
            result.push_back(name);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (const auto& name : result) {
        cout << name << "\n";
    }

    return 0;
}