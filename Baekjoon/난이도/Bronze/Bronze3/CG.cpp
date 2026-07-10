#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int result=1, count=1;

    for(int i=0;i<N;i++){
        result*=2;
    }
    count=(result+1)*(result+1);
    cout<<count<<endl;
    return 0;
}