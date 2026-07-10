/*문제 : https://www.acmicpc.net/problem/1922
  알고리즘 : Minimum Spanning Tree, Kruskal
  티어 : Gold4
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
using namespace std;

int N,M;
int result=0;
int Parent[MAX];
vector<pair<int,pair<int,int>>> Edge;

int Find(int x){
    if(Parent[x]==x)
        return x;
    else
        return Parent[x]=Find(Parent[x]);
}

void Union(int x, int y){
    x=Find(x);
    y=Find(y);
    
    if(x!=y)
        Parent[y]=x;
}

bool SameParent(int x, int y){
    x=Find(x);
    y=Find(y);

    if(x==y)
        return true;
    else
        return false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Edge.push_back(make_pair(c,make_pair(a,b)));
    }

    sort(Edge.begin(), Edge.end());
    for(int i=1;i<=N;i++){
        Parent[i]=i;
    }
    for(int i=0;i<M;i++){
        if(!SameParent(Edge[i].second.first, Edge[i].second.second)){
            Union(Edge[i].second.first, Edge[i].second.second);
            result+=Edge[i].first;
        }
    }
    cout<<result<<'\n';
    return 0;
}