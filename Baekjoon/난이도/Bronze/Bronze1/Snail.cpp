#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A,B,V;
    cin>>A>>B>>V;

    int day=(V-B-1)/(A-B)+1;
    cout<<day<<'\n';
    return 0;
}