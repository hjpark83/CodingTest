/*
# Question: BJ 10815 (https://www.acmicpc.net/problem/10815)
# Rank: Silver 5
# Algorithm: Data Structure, Set, Map, Binary Search, Sorting
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
    cin >> N;
    set<int> Cards;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        Cards.insert(num);
    }
    cin >> M;
    for(int i=0; i<M; i++){
        int num;
        cin >> num;

        if(Cards.find(num) != Cards.end()){
            cout << "1 ";
        }else{
            cout << "0 ";
        }
    }
    
    return 0;
}