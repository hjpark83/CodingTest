#include <iostream>
using namespace std;

int reverseNum(int num){
    int reverse=0;
    while(num>0){
        int digit=num%10; //숫자의 마지막 숫자 추출 (734 -> 4)
        reverse=reverse*10+digit; // 역방향 업데이트
        num/=10; // 마지막 자리 제거 (734 -> 73)
    } //루프 반복하면서 뒤에서부터 한자리씩 reverse에 저장
    return reverse;
}
int main(void){
    int a,b;
    cin>>a>>b;
    int c=reverseNum(a);
    int d=reverseNum(b);
    if(c>d)
        cout<<c<<endl;
    else
        cout<<d<<endl;
    return 0;
}