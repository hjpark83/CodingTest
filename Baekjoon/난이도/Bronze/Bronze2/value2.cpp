#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> A(5,0);
    int sum=0;
    int avg=0;

    for(int i=0;i<5;i++){
        cin>>A[i];
        sum+=A[i];
    }
    avg=sum/5;
    sort(A.begin(),A.end());
    int mid=A[2];

    cout<<avg<<'\n';
    cout<<mid<<'\n';

    return 0;
}