/*
# Question: BJ 2493 (https://www.acmicpc.net/problem/2493)
# Rank: Gold4
# Algorithm: Data structure, Stack
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 500000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//const int INF = 1e9;

int N;
stack<pii> st;

void Solution() {
    cin>>N;
    for(int i=0; i<N; i++){
        int h;
        cin>>h;
        while(!st.empty()){
            if(st.top().second>h){
                cout<<st.top().first<<" ";
                break;
            }
            st.pop();
        }
        if(st.empty()) 
            cout<<"0 ";
        st.push({i+1, h});
    }
}

int main() {
    fastio
    Solution();
    return 0;
}