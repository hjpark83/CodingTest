#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b;
    cin>>a>>b;

    cout<<gcd(a,b)<<" "<<a*b/gcd(a,b)<<endl;
    return 0;
}