#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<pair<int,int>> Point;

    int x,y;
    for(int i=0;i<N;i++){
        cin>>x>>y;
        Point.push_back({x,y});
    }
    sort(Point.begin(),Point.end());
    for(int i=0;i<N;i++){
        cout<<Point[i].first<<" "<<Point[i].second<<'\n';
    }
    return 0;
    
}