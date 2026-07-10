/*문제 : https://www.acmicpc.net/problem/11003
  알고리즘 : Data Structure, priority queue, deque
  티어 : Platinum5
*/
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

int N, L;
vector<pair<int,int>> v; // value, index
deque<pair<int,int>> dq; // value, index

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>L;

    for(int i=0; i<N; i++){
        int x;
        cin>>x;
        v.push_back(make_pair(x,i));
    }

    for(int i=0; i<N; i++){
        while(!dq.empty() && dq.front().second<=i-L)
            dq.pop_front();
        while(!dq.empty() && dq.back().first>v[i].first)
            dq.pop_back();
        dq.push_back(v[i]);
        cout<<dq.front().first<<" ";
    }
}