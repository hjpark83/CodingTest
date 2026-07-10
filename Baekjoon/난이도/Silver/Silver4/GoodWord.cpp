#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int count=0;
    string str;
    stack<char> S;

    while(N--){
        cin>>str;
        for(int i=0;i<str.length();i++){
            if(S.empty()){
                S.push(str[i]);
            }else{
                if(S.top()==str[i]){
                    S.pop();
                }else{
                    S.push(str[i]);
                }
            }
        }
        if(S.empty()){
            count++;
        }
    }
    cout<<count<<'\n';
    return 0;
}