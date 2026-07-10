/*문제 : https://www.acmicpc.net/problem/9935
  알고리즘 : 자료구조, 문자열, 스택
  티어 : Gold4
*/

#include <iostream>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin>>str;
    string exp;
    cin>>exp;

    string result;

    for(int i=0;i<str.length();i++){
        result+=str[i];
        if (result.length()>=exp.length()&&result.substr(result.length()-exp.length())==exp){
            for (int j = 0; j < exp.length(); j++) {
                result.pop_back();
            }
        }
    }
    if(result.empty()){
        cout<<"FRULA"<<'\n';
    }else{
        cout<<result<<'\n';
    }
    return 0;
}