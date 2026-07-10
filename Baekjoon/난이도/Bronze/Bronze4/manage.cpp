#include <iostream>
#include <ctype.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    string str;
    for(int i=0;i<N;i++){
        cin>>str;
        for(int j=0;j<str.length();j++){
            if(isupper(str[j])){
               str[j]=tolower(str[j]);
            }
        }
        cout<<str<<'\n';
    }
    return 0;
}