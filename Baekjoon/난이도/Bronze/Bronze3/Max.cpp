#include <iostream>
using namespace std;

int main(void){
    int num;
    int maxIndex=0;
    int max=0;
    for(int i=1;i<=9;i++){
        cin>>num;
        if(num>max){
            max=num;
            maxIndex=i;
        }
    }
    cout<<max<<endl;
    cout<<maxIndex<<endl;
    return 0;
}