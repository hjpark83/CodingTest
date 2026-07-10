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

    vector<pair<int,int>> A;
    
    int x,y;
    for(int i=0;i<N;i++){
        cin>>x>>y;
        A.push_back({y,x});
    }
    sort(A.begin(),A.end());
    for(int i=0;i<N;i++){
        cout<<A[i].second<<" "<<A[i].first<<'\n';
    }
    return 0;
}