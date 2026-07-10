#include <iostream>
#include <math.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int left=1,right=N;
    while(1){
        int mid=(left+right)/2;
        if(mid*mid==N){
            cout<<mid<<'\n';
            break;
        }else if(mid*mid>N){
            right=mid-1;
        }else if(mid*mid<N){
            left=mid+1;
        }
    }
    return 0;
}