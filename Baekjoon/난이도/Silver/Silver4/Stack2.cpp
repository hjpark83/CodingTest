#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    stack<int> myStack;

    while(N--){
        int num,element;
        cin>>num;
        switch(num){
            case 1:
                cin>>element;
                myStack.push(element);
                break;
            case 2:
                if(myStack.empty()){
                    cout<<"-1"<<'\n';
                }else{
                    cout<<myStack.top()<<'\n';
                    myStack.pop(); 
                }
                break;
            case 3:
                cout<<myStack.size()<<'\n';
                break;
            case 4:
                cout<<(myStack.empty()?1:0)<<'\n';
                break;
            case 5:
                cout<<(myStack.empty()?-1:myStack.top())<<'\n';
                break;
        }
    } 
    return 0;
}