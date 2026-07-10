#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A,B;
    cin>>A>>B;

    vector<int> V;
    for(int i=1;i<1000;i++){
        for(int j=0;j<i;j++){
           V.push_back(i);
        }
    }
    int sum=0;
    for(int i=A-1;i<B;i++){
        sum+=V[i];
        // cout<<V[i]<<" ";
    }
    cout<<sum<<endl;
    return 0;
}