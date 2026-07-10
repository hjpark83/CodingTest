#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(const string& str){
    stack <char> S;
    for(char c:str){
        if(c=='('||c=='['){
            S.push(c);
        }else if(c==')'||c==']'){
            if(S.empty())
                return false;
            char top=S.top();
            S.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return S.empty();
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string words;
    while(true){
        getline(cin,words);
        if(words=="."){
            break;
        }
        bool balanced=isBalanced(words);
        cout<<(balanced?"yes":"no")<<'\n';
    }
    return 0;
}