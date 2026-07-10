#include <iostream>
#include <string>
#include <stack>
using namespace std;

namespace VALUE{
    enum{
        H=1, C=12, O=16
    };
}
int main(void){
    string ChemVal;
    cin>>ChemVal;

    int answer=0;
    stack<int> S;

    for(char c: ChemVal){
        if(c=='('){
            S.push(-1);
        }else if(c==')'){
            int num=0;
            while(S.top()!=-1){
                num+=S.top();
                S.pop();
            }
            S.pop();
            S.push(num);
        }else if(c>='2' && c<='9'){
            int val=c-'0';
            int prev=S.top();
            S.pop();
            S.push(val*prev);
        }else{
            if(c=='H'){
                S.push(VALUE::H);
            }else if(c=='C'){
                S.push(VALUE::C);
            }else if(c=='O'){
                S.push(VALUE::O);
            }
        }
    }
    while(!S.empty()){
        answer+=S.top();
        S.pop();
    }

    cout<<answer<<endl;
    return 0;
}