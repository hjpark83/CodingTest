#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    cin>>x;
    vector<int> count(x+1);

    for(int i=2;i<=x;i++){
        count[i]=count[i-1]+1;
        if(i%3==0){
            count[i]=min(count[i],count[i/3]+1);
        }
        if(i%2==0){
            count[i]=min(count[i],count[i/2]+1);
        }
    }
    cout<<count[x]<<endl;
    return 0;
}