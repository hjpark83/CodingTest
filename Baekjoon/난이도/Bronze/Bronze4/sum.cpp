#include <iostream>
#include <string>
using namespace std;

int main(void){
    int count;
    string s;
    cin>>count;
    cin>>s;
    int sum=0;
    for(int i=0;i<count;i++){
        sum+=s[i]-'0';
    }
    cout<<sum<<endl;
    return 0;
}