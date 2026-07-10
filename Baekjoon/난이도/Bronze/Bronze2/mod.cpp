#include <iostream>
using namespace std;

int main(void){
    int num[10],mod[10];
    bool unique[42]={false};
    int count=0;
    for(int i=0;i<10;i++){
        cin>>num[i];
        mod[i]=num[i]%42;
    }
    for(int i=0;i<10;i++){
        if(!unique[mod[i]]){
            unique[mod[i]]=true;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}