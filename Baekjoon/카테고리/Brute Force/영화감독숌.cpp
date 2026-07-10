/*
# Question: BJ 1436 (https://www.acmicpc.net/problem/1436)
# Rank: Silver5
# Algorithm:  Brute Force
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
    cin>>N;

    int cnt = 0;
    int num = 666;
    while(true){
        string str = to_string(num);
        if(str.find("666") != string::npos){
            cnt++;
        }
        if(cnt == N){
            cout << num << '\n';
            break;
        }
        num++;
    }

    return 0;
}