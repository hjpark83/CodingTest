#include <iostream>
using namespace std;

int N;
int cnt=0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=1;i*i<=N;i++){
        cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}