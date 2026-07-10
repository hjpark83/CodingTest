#include <iostream>
using namespace std;

int main(void){
    int count;
    cin>>count;
    
    double* price=new double[count];
    double* discounted=new double[count];
    const double discount=0.8;

    for(int i=0;i<count;i++){
        cin>>price[i];
        discounted[i]=price[i]*discount;
    }
    for(int i=0;i<count;i++){
        printf("$%.2f\n",discounted[i]);
    }
    delete []discounted;
    delete []price;
    return 0;
}