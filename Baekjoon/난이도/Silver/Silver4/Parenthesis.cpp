#include <iostream>
#include <stack>
using namespace std;

string checkVPS(string input){
    stack<char> S;
    for(int i=0;i<input.size();i++){
        if(input[i]=='('){
            S.push('(');
        }else{
            if(S.empty()){
                return "NO";    
            }
            S.pop();
        }
    }
    if(S.empty()){
        return "YES";
    }else{
        return "NO";
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string ps;
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>ps;
        cout<<checkVPS(ps)<<'\n';
    }
    return 0;
}   