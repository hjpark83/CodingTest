/*
# Question: BJ 3015 (https://www.acmicpc.net/problem/3015)
# Rank: Platinum5
# Algorithm: Data Structure, Stack
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

stack<pii> s;

int main() {
    fastio
    int N;
    cin>>N;

    ll ans = 0;
    while(N--){
        int h, cnt = 1;
        cin>>h;

        while(!s.empty() && s.top().first <= h){
            ans+=s.top().second;
            if(s.top().first == h)
                cnt+=s.top().second;
            s.pop();
        }
        if(!s.empty()) 
            ans++;
        s.push({h, cnt});
    }
    cout<<ans<<'\n';
    
    return 0;
}