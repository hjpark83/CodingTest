/*문제 : https://www.acmicpc.net/problem/1976
  알고리즘 : 자료구조, 그래프, disjoint set
  티어 : Gold4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int N,M;

typedef struct DisjointSet{
    int size;
    int *arr;
}DisjointSet;

int Find(DisjointSet *set, int x){
    if(set->arr[x] == x){
        return x;
    }
    return Find(set, set->arr[x]);
}

void Union(DisjointSet *set, int x, int y){
    x = Find(set, x);
    y = Find(set, y);
    if (x < y)
        set->arr[y] = x;
    else
        set->arr[x] = y;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    DisjointSet *set = new DisjointSet;
    set->size = (N+1)*(N+1);
    set->arr = new int[set->size];


    for(int i=1; i<=N; i++){
        set->arr[i] = i;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> set->arr[i*N+j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(set->arr[i*N+j] == 1){
                Union(set, i, j);
            }
        }
    }
    
    int root;
    for (int i=0; i<M; i++){ 
        int x;
        cin>>x;
        if(i==0)
            root=Find(set,x);
        else{
            if(Find(set, root) != Find(set, x)){
                cout << "NO";
                delete set;
                return 0;
            }
        }
    }
    cout << "YES"; // 수정된 부분
    delete set;
    return 0;
}