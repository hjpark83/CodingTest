/*문제 : https://www.acmicpc.net/problem/2014
  알고리즘 : 수학, 자료구조, 우선순위 큐, 정수론
  티어 : Gold1
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

map<ll, bool> check;
vector<ll> num;
priority_queue<ll,vector<ll>,greater<ll>> pq;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K,N;
    cin>>K>>N;

    for(int i=0;i<K;i++){
        ll x;
        cin>>x;
        num.push_back(x);
    }

    pq.push(1);
    check[1]=true;
    ll max_val=0;

    while(N--){
        ll now=pq.top();
        pq.pop();

        for(auto i:num){
            ll next=now*i;
            if(check.count(next))
                continue;

            if(pq.size()>N){
                if(max_val<=next)
                    continue;
            }
            pq.push(next);
            max_val=max(max_val,next);
            check[next]=true;
        }
    }
    cout<<pq.top();
    return 0;
}