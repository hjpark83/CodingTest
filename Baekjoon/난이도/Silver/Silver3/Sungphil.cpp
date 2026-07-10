#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void){
    string formula;
    getline(cin,formula);

    stack<int> s;
    for(int i=0;i<formula.length();i++){
        char c=formula[i];

        if(c>='0' && c<='9'){
            s.push(c-'0');
        }else{
            int x,y;
            x=s.top();
            s.pop();
            y=s.top();
            s.pop();

            if(c=='+'){
                s.push(y+x);
            }else if(c=='-'){
                s.push(y-x);
            }else if(c=='*'){
                s.push(y*x);
            }else if (c=='/'){
                s.push(y/x);
            }
        }
    }
    cout<<s.top()<<'\n';
    return 0;
}