#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int count=0;
    
    while(N!=0){
        if(N%125==0){
            count+=3;
        }else if(N%25==0){
            count+=2;
        }else if(N%5==0){
            count+=1;
        }
        N--;
    }
    cout<<count<<'\n';
    return 0;
}