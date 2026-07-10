#include <iostream>
#include <cstring>
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
        char command[10];
        int number;

        cin>>command;
        if(strcmp(command,"push")==0){
            cin>>number;
            myStack.push(number);
        }else if(strcmp(command,"pop")==0){
            if(myStack.empty()){
                cout<<"-1"<<'\n';
            }else{
                cout<<myStack.top()<<'\n';
                myStack.pop();
            }
        }else if(strcmp(command,"top")==0){
            if(myStack.empty()){
                cout<<"-1"<<'\n';
            }else{
                cout<<myStack.top()<<'\n';
            }
        }else if(strcmp(command,"size")==0){
            cout<<myStack.size()<<'\n';
        }else if(strcmp(command,"empty")==0){
            cout<<(myStack.empty()?"1":"0")<<'\n';
        }
    }
    return 0;
}