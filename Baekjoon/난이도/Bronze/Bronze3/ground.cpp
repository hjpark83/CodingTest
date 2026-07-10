#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<pair<int,int>> A;

    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        A.push_back({x,y});
    }

    int maxX=A[0].first;
    int minX=A[0].first;
    int maxY=A[0].second;
    int minY=A[0].second;

    for(int i=0;i<N;i++){
        if(A[i].first>maxX){
            maxX=A[i].first;
        }
        if(A[i].first<minX){
            minX=A[i].first;
        }
        if(A[i].second>maxY){
            maxY=A[i].second;
        }
        if(A[i].second<minY){
            minY=A[i].second;
        }
    }
    int diffX=maxX-minX;
    int diffY=maxY-minY;
    int result=diffX*diffY;

    cout<<result<<'\n';
    return 0;
}