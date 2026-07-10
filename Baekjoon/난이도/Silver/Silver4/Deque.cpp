#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    deque<int> Q;

    while(N--){
        string command;
        int num;

        cin>>command;
        if(command=="push_back"){
            cin>>num;
            Q.push_back(num);
        }else if(command=="push_front"){
            cin>>num;
            Q.push_front(num);
        }else if(command=="pop_front"){
            if(Q.empty()){
                cout<<"-1"<<'\n';
            }else{
                cout<<Q.front()<<'\n';
                Q.pop_front();
            }
        }else if(command=="pop_back"){
            if(Q.empty()){
                cout<<"-1"<<'\n';
            }else{
                cout<<Q.back()<<'\n';
                Q.pop_back();
            }
        }else if(command=="size"){
            cout<<Q.size()<<'\n';
        }else if(command=="empty"){
            cout<<(Q.empty()?1:0)<<'\n';
        }else if(command=="front"){
            if(Q.empty()){
                cout<<"-1"<<'\n';
            }else{
                cout<<  Q.front()<<'\n';
            }
        }else if(command=="back"){
            if(Q.empty()){
                cout<<"-1"<<'\n';
            }else{
                cout<<Q.back()<<'\n';
            }
        }
    }
    return 0;
}