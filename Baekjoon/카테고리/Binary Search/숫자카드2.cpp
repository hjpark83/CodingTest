/*
# Question: BJ 10816 (https://www.acmicpc.net/problem/10816)
# Rank: Silver4
# Algorithm: Data Structure, Binary Search, Sorting, Hashing, Map
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
    
    int N, M, n;
    map<int, int> count;

    cin>>N;
    while(N--){
        cin>>n;
        count[n]++;
    }

    cin>>M;
    while(M--){
        cin >> n;
        auto it = count.find(n);

        if(it != count.end()){
            cout << it->second << ' ';
        }else{
            cout << "0" << ' ';
        }
    }

    return 0;
}