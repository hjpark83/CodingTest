#include <iostream>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    getline(cin,str);
    bool inWord=false;
    int count=0;

    for(char c:str){
        if(c!=' '){
            inWord=true;
        }else{
            if(inWord){
                count++;
                inWord=false;
            }
        }
    }
    if(inWord){
        count++;
    }
    cout<<count<<'\n';
    return 0;
}