/*문제 : https://www.acmicpc.net/problem/2447
  알고리즘 : 분할 정복, 재귀
  티어 : Gold5
*/

#include <iostream>
using namespace std;

void printStar(int i, int j, int num){
    if((i/num)%3==1 && (j/num)%3==1){
        cout<<" ";
    }else{
        if(num/3==0)
            cout<<"*";
        else
            printStar(i,j,num/3);
    }
}
int main(void){
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            printStar(i,j,num);
        }
        cout<<"\n";
    }
    return 0;
}