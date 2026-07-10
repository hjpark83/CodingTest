/*
# Question: BJ 16398 (https://www.acmicpc.net/problem/16398)
# Rank: Gold4
# Algorithm: Minimum Spanning Tree, Graph
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int N;
ll result = 0;
int parent[MAX]={0,};
vector<vector<int>> Map;
vector<pair<int,pii>> Edge;

void Input(){
    cin>>N;
    Map.resize(N+1, vector<int>(N+1,0));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>Map[i][j];
            if (i < j){
                Edge.push_back({Map[i][j], {i, j}});
            }
        }
    }
}

int Find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x==y)
        return;
    
    if(x>y)
        parent[x] = y;
    else
        parent[y] = x;
}

bool SameParent(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x==y)
        return true;
    else
        return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();

    for(int i=0; i<=N; i++){
        parent[i] = i;
    }
    sort(Edge.begin(), Edge.end());

    for(int i=0; i<Edge.size(); i++){
        if(!SameParent(Edge[i].second.first, Edge[i].second.second)){
            Union(Edge[i].second.first, Edge[i].second.second);
            result += Edge[i].first;
        }
    }
    cout<<result<<'\n';
    return 0;
}