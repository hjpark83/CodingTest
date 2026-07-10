#include <iostream>
using namespace std;

int main(void){
    int hour, minute, time;
    cin>>hour>>minute;
    cin>>time;

    hour+=time/60;
    minute+=time%60;
    if(minute>=60){
        hour++;
        minute-=60;
    }
    if(hour>=24){
        hour-=24;
    }
    cout<<hour<<" "<<minute<<endl;
    return 0;
}