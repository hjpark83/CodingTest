/*
# Question: BJ 1719 (https://www.acmicpc.net/problem/1719)
# Rank: Gold3
# Algorithm: Graph, Dijkstra, Floyd-Warshall
*/

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 201
using namespace std;
const int INF = 1e9;

int N, M;
vector<vector<int>> Next(MAX, vector<int>(MAX, 0));
vector<vector<int>> Route(MAX, vector<int>(MAX, INF));

void Input() {
    cin>>N>>M;

    for(int i=0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;

        Route[a][b] = c;
        Route[b][a] = c;

        Next[a][b] = b;
        Next[b][a] = a;
    }
}

void FloydWarshall(){
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(Route[i][j] > Route[i][k] + Route[k][j]){
                    Route[i][j] = Route[i][k] + Route[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}

void Print(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j)
                cout<<"- ";
            else
                cout<<Next[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    fastio
    Input();
    FloydWarshall();
    Print();
    return 0;
}