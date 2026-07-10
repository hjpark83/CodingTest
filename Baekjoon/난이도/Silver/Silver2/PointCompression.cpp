#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<long long> A;
    vector<long long> tmp;

    int x;
    for(int i=0;i<N;i++){
        cin>>x;
        A.push_back(x);
        tmp.push_back(x);
    }
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());

    for(int i=0;i<N;i++){
        cout<<lower_bound(tmp.begin(),tmp.end(),A[i])-tmp.begin()<<" ";
    }
    return 0;
}