#include <iostream>
#include <deque>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    deque<int> DQ;

    while(N--){
        int command, num;
        cin>>command;
        switch(command){
            case 1:
                cin>>num;
                DQ.push_front(num);
                break;
            case 2:
                cin>>num;
                DQ.push_back(num);
                break;
            case 3:
                if(DQ.empty()){
                    cout<<"-1"<<'\n';
                }else{
                    cout<<DQ.front()<<'\n';
                    DQ.pop_front();
                }
                break;
            case 4:
                if(DQ.empty()){
                    cout<<"-1"<<'\n';
                }else{
                    cout<<DQ.back()<<'\n';
                    DQ.pop_back();
                }
                break;
            case 5:
                cout<<DQ.size()<<'\n';
                break;
            case 6:
                cout<<(DQ.empty()?1:0)<<'\n';
                break;
            case 7:
                if(DQ.empty()){
                    cout<<"-1"<<'\n';
                }else{
                    cout<<DQ.front()<<'\n';
                }
                break;
            case 8:
                if(DQ.empty()){
                    cout<<"-1"<<'\n';
                }else{
                    cout<<DQ.back()<<'\n';
                }
                break;
        }
    }
    return 0;
}