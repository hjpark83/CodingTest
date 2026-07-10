#include <iostream>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b;
    int sum=0;

    while(1){
        cin>>a>>b;
        sum=a+b;
        if(a==0 && b==0){
            break;
        }
        cout<<sum<<"\n";
    }
    return 0;
}