#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    queue<int> myQueue;
    while(N--){
        char command[10];
        int num;

        cin>>command;
        if(strcmp(command,"push")==0){
            cin>>num;
            myQueue.push(num);
        }else if(strcmp(command,"pop")==0){
            if(myQueue.empty()){
                cout<<"-1"<<'\n';
            }else{
                cout<<myQueue.front()<<'\n';
                myQueue.pop();
            }
        }else if(strcmp(command,"size")==0){
            cout<<myQueue.size()<<'\n';
        }else if(strcmp(command,"empty")==0){
            cout<<(myQueue.empty()?1:0)<<'\n';
        }else if(strcmp(command,"front")==0){
            if(myQueue.empty()){
                cout<<"-1"<<'\n';
            }else{
                cout<<myQueue.front()<<'\n';
            }
        }else if(strcmp(command,"back")==0){
            if(myQueue.empty()){
                cout<<"-1"<<'\n';
            }else{
                cout<<myQueue.back()<<'\n';
            }
        }
    }
    return 0;
}