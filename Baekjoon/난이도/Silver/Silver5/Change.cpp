#include <iostream>
#define MAX_NUM 100000
using namespace std;

typedef long long ll;

int DP[MAX_NUM];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int sum=0;
    if(n==1 || n==3){
        cout<<"-1"<<'\n';
        return 0;
    }
    if((n%5)%2==0){
        sum=n/5+n%5/2;
    }else{
        sum=n/5+(n%5+5)/2-1;
    }    
    cout<<sum<<'\n';
    return 0;
}
