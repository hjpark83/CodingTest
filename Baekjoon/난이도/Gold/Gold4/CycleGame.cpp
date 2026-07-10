/*
# Question: BJ 20040 (https://www.acmicpc.net/problem/20040)
# Rank: Gold4
# Algorithm: Data Structure, DisjointSet
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1000000
using namespace std;
typedef pair<pair<int, int>,int> piii;

int N, M;
int parent[MAX];
vector<piii> edges;

void Input() {
    cin>>N>>M;
    for(int i=1; i<=M; i++){
        int a, b;
        cin>>a>>b;
        edges.push_back({{a, b}, i});
    }

    for(int i=0; i<N; i++)
        parent[i] = i;
}

int Find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x != y)
        parent[x] = y;
}

bool isCycle(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x == y)
        return true;
    return false;
}

int main() {
    fastio
    Input();
    
    for(int i=0; i<edges.size(); i++){
        int a = edges[i].first.first;
        int b = edges[i].first.second;

        if(isCycle(a, b)){
            cout<<edges[i].second<<"\n";
            return 0;
        }
        Union(a, b);
    }
    cout<<0<<"\n";
    return 0;
}