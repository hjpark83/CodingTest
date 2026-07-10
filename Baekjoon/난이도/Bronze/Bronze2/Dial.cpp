#include <iostream>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    getline(cin,str);

    int dist=0;
    int sum=0;
    for(char c: str){
        if(c>='A' && c<='C'){
            dist=3;
        }else if(c>='D' && c<='F'){
            dist=4;
        }else if(c>='G' && c<='I'){
            dist=5;
        }else if(c>='J' && c<='L'){
            dist=6;
        }else if(c>='M' && c<='O'){
            dist=7;
        }else if(c>='P' && c<='S'){
            dist=8;
        }else if(c>='T' && c<='V'){
            dist=9;
        }else if(c>='W' && c<='Z'){
            dist=10;
        }
        sum+=dist;
    }
    cout<<sum<<'\n';
    return 0;
}