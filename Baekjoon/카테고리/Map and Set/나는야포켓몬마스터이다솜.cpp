/*
# Question: BJ (https://www.acmicpc.net/problem/)
# Rank: 
# Algorithm: 
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

    string name;

    map<int, string> S;
    map<string, int> T;
    for (int i = 0; i < N; i++) {
        cin >> name;
        S.insert({i + 1, name});
        T.insert({name, i + 1});
    }

    for (int i = 0; i < M; i++) {      
        string input;
        cin >> input;

        if (isdigit(input[0])) { // 번호인 경우 이름을 출력
            int num = stoi(input);
            cout << S.find(num)->second << "\n";
        } else { // 이름인 경우 번호를 출력
            cout << T.find(input)->second << "\n";
        }
    }
    return 0;
}