#include <iostream>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num,a,b;
    int sum=0;
    cin>>num;

    for(int i=0;i<num;i++){
        cin>>a>>b;
        sum=a+b;
        cout<<"Case #"<<i+1<<": "<<a<<" + "<<b<<" = "<<sum<<"\n";
    }
    return 0;
}
