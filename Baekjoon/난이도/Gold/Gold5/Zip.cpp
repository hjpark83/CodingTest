/*문제 : https://www.acmicpc.net/problem/1717
  알고리즘 : 자료구조, 분리 집합
  티어 : Gold5
*/

#include <iostream>
#include <vector>
using namespace std;

static vector<int> parent;
int find(int x){
    if(x==parent[x]){
        return x;
    }else{
        return parent[x]=find(parent[x]);
    }
}
void unionFunc(int x, int y){
    x=find(x);
    y=find(y);

    if(x!=y){
        parent[y]=x;
    }
}
bool checkSame(int x, int y){
    x=find(x);
    y=find(y);

    if(x==y){
        return true;
    }
    return false;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;
    
    parent.resize(N+1);
    
    for(int i=0;i<=N;i++){
        parent[i]=i;    
    }
    for(int i=0;i<M;i++){
        int question,a,b;
        cin>>question>>a>>b;

        if(question==0){
            unionFunc(a,b);
        }else{
            if(checkSame(a,b)){
                cout<<"YES"<<'\n';
            }else{
                cout<<"NO"<<'\n';
            }
        }
    }
}