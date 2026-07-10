/*문제 : https://www.acmicpc.net/problem/1990
  알고리즘 : 수학, 정수론, 소수 판정, 에라토스테네스의 체
  티어 : Gold5
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

#define MAX 10000001
using namespace std;

bool S[MAX]={
    false,
};

bool ispalindrome(int n)
{
    string s1=to_string(n);
    string s2=s1;
    reverse(s1.begin(),s1.end());
    if(s1==s2)
        return true;
    else
        return false;
}
bool isPrime(int n){
    for (int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int a,b;
    cin>>a>>b;
    
    if(b>MAX-1){
        b=MAX-1;
    }

    for(int i=2;i<MAX;i++){
        if(ispalindrome(i))
            S[i]=true;
    }

    for(int i=a;i<=b;i++){
        if(S[i] && isPrime(i)){
            cout<<i<<'\n';
        }
    }
    cout<<"-1"<<'\n';
    return 0;
}