#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int a,b;
    cin>>a>>b;
    long long int result=a*b/gcd(a,b);
    cout<<result<<'\n';
    return 0;
}