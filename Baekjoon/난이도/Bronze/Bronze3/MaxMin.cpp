#include <iostream>
using namespace std;

int main(void){
    int N;
    cin>>N;
    int* Num=new int[N];

    for(int i=0;i<N;i++){
        cin>>Num[i];
    }

    int Max=Num[0];
    int Min=Num[0];

    for(int i=0;i<N;i++){
        if(Num[i]>Max)
            Max=Num[i];
        if(Num[i]<Min)
            Min=Num[i];
    }
    cout<<Min<<" "<<Max<<"\n";
    delete []Num;
    return 0;
}