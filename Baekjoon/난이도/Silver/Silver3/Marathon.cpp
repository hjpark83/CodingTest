#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int dist(vector<int> a, vector<int> b){
    return abs(a[0]-b[0])+abs(a[1]-b[1]);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<vector<int>> Point(N,vector<int>(2,0));
    vector<int> Dist(N);

    for(int i=0;i<N;i++){
        cin>>Point[i][0]>>Point[i][1];
    }

    int total=0;
    for(int i=0;i<N-1;i++){
        Dist[i]=dist(Point[i],Point[i+1]);
        total+=Dist[i];
    }
    int M=0;
    for(int i=0;i<N-2;i++){
        int skip=dist(Point[i],Point[i+2]);
        M=max(M,Dist[i]+Dist[i+1]-skip);
    }
    cout<<total-M<<'\n';
}