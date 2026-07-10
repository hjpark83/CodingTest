/*문제 : https://www.acmicpc.net/problem/1197
  알고리즘 : 그래프, 최소 스패닝 트리
  티어 : Gold4
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[10001];
int find(int x){
    if(parent[x]==x){
        return x; // x의 부모가 x와 같으면 x가 부모이므로 x반환
    }else{
        return parent[x]=find(parent[x]); // 아니면 x의 부모를 x의 부모를 통해서 다시 찾음
    }
}

void union_(int x, int y){
    x=find(x);
    y=find(y);

    parent[y]=x;
} // y의 부모 =x

bool sameparent(int x, int y){
    x=find(x);
    y=find(y);
    
    if(x==y)
        return true; // x의 부모와 y의 부모가 같으면 true
    else
        return false; // 다르면 false
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E;
    cin>>V>>E;

    vector<pair<int,pair<int,int>>> A;

    for(int i=0;i<E;i++){
        int start,end,cost;
        cin>>start>>end>>cost;
        A.push_back({cost,{start,end}});
    }
    sort(A.begin(),A.end());
    for(int i=0;i<V;i++){
        parent[i]=i;
    }

    int result=0;
    for(int i=0;i<A.size();i++){
        if(!sameparent(A[i].second.first,A[i].second.second)){
            union_(A[i].second.first,A[i].second.second);
            result+=A[i].first;
        } // start랑 end가 같은 부모가 아니라면 두개를 합치고 가중치를 더해줌
    }
    cout<<result;
    return 0;
}