#include <iostream>
using namespace std;

bool isPalin(string str){
    int start=0,end=str.length()-1;
    while(start<end){
        if(str[start]!=str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin>>str;

    int len=str.length();

    int count=0;
    for(int i=0;i<len/2;i++){
        if(str[i]==str[len-i-1]){
            count=len;
        }else if(str[i]==str[len/2+i]){
            count=len+1;
        }
    }
    for(int i=0;i<len;i++){
        string tmp=str.substr(i,len-i);
        if(isPalin(tmp)){
            count=str.length()+i;
            break;
        }
    }
    cout<<count<<'\n';
    return 0;
}