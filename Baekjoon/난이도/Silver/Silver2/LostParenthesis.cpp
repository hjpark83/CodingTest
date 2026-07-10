#include <iostream>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string tmp="";
    string equation;
    cin>>equation;

    int result=0;
    bool isMinus=false;

    for(int i=0;i<=equation.size();i++){
        if(equation[i]=='+' || equation[i]=='-' || equation[i]=='\0'){
            if(isMinus){
                result-=stoi(tmp);
            }else{
                result+=stoi(tmp);
            }
            tmp=""; 
            /* 연산자를 만나기 전까지 연속된 숫자를 저장 후 
            result에 정수 값으로 더해준 뒤 다음 숫자를 받기 위해 초기화*/
            if(equation[i]== '-'){
                isMinus=true;
            }
        }else{
            tmp+=equation[i];
        }
    }
    cout<<result<<endl;
    return 0;
}