#include <iostream>
using namespace std;

int main(int argc,char *argv[]){
    int a,b;
    int sum=0;

    while(!(cin>>a>>b).eof()){
        sum=a+b;
        cout<<sum<<"\n";
    }
    return 0;
}