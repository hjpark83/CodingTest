#include <iostream>
#include <vector>
using namespace std;

int CPU_N,cnt,infected=0;
vector<int> Network[105];
int virus[105];

void DFS(int v){
    for(int t=0;t<Network[v].size();t++){
        int k=Network[v][t];
        if(virus[k]==0){
            virus[k]=1;
            infected++;
            DFS(k);
        }
    }
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>CPU_N>>cnt;

    for(int i=0;i<cnt;i++){
        int start, end;
        cin>>start>>end;
        Network[start].push_back(end);
        Network[end].push_back(start);
    }

    virus[1]=1;
    DFS(1);
    cout<<infected<<'\n';
    return 0;    
}