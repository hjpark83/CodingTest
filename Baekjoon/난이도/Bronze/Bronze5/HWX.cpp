#include <iostream>
using namespace std;

int main(void) {
    int num[30];
    
    for (int i=0;i<28;i++) {
        cin>>num[i];
    }
    bool exist[31]={false};

    for (int i=0;i<28;i++) {
        exist[num[i]]=true;
    }

    for (int i=1;i<=30;i++) {
        if(!exist[i]){
            cout<<i<<endl;
        }
    }
    return 0;
}
