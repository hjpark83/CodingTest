/*
# Question: BJ 1202 (https://www.acmicpc.net/problem/1202)
# Rank: Gold2
# Algorithm: Greedy, Data structure, Sorting, Priority Queue
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, K, ans;
vector<pll> Jewelry;
vector<ll> Bag;
multiset<ll> ms; // set과 동일하지만 multiset은 중복을 허용해줌

void Input(){
    cin>>N>>K;
    
    Jewelry.resize(N);
    Bag.resize(K);

    for(auto& i : Jewelry){
        cin>>i.first>>i.second;
    }
    for(auto& i : Bag){
        cin>>i;
    }
}

bool cmp(pll a, pll b){
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Input();

    sort(Jewelry.begin(), Jewelry.end(), cmp);
    sort(Bag.begin(), Bag.end(), greater<ll>());

    ll idx = 0;
    for(int i=0; i<Jewelry.size(); i++){
        if(idx >= Bag.size()){ // Bag이 다 찼을 때
            ms.insert(Jewelry[i].second); // 가방에 넣을 수 있는 보석들을 넣는다.
            ms.erase(ms.begin()); // 가장 작은 보석을 빼준다.
        }else{
            ms.insert(Jewelry[i].second); // 가방에 넣을 수 있는 보석들을 넣는다.

            if(Bag[idx] >= Jewelry[i].first){ // 가방에 넣을 수 있는 보석이라면
                idx++; // 다음 가방으로 넘어간다.
            }else{
                ms.erase(ms.begin()); // 가장 작은 보석을 빼준다.
            }
        }
    }

    for(auto i:ms)
        ans += i;

    cout<<ans<<'\n';
    return 0;
}