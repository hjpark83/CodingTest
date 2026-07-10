#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int,string> a, pair<int,string> b){
    if(a.first==b.first){
        return false;
    }else{
        return a.first<b.first;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<pair<int,string>> A;

    int age;
    string name;
    for(int i=0;i<N;i++){
        cin>>age>>name;
        A.push_back(make_pair(age,name));
    }
    stable_sort(A.begin(),A.end(),compare);
    for(int i=0;i<N;i++){
        cout<<A[i].first<<" "<<A[i].second<<'\n';
    }
    return 0;
}