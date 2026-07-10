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

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    a*=d;
    c*=b;
    a+=c;
    b*=d;

    int G=gcd(a,b);
    cout<<a/G<<" "<<b/G<<'\n';
    return 0;
}