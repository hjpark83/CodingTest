#include <iostream>
using namespace std;

int main(void){
    int month,day;
    cin>>month;
    cin>>day;
    if(month<1||month>12||day<1||day>31){
        return 0;
    }
    if(month<=2&&day<18||month==1){
        cout<<"Before"<<endl;
    }else if(month==2&&day==18){
        cout<<"Special"<<endl;
    }else{
        cout<<"After"<<endl;
    }
    return 0;
}