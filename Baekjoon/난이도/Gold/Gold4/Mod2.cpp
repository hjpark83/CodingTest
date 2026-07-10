#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll Mod(ll x){
    ll count=0;
    while(x%2==0){
        x/=2;
        count++;
    }
    return count;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll A,B;
    cin>>A>>B;

    ll result=0;
    for(ll i=A;i<=B;i++){
        result+=(1LL<<Mod(i));
    }

    cout<<result<<'\n';
}