/*문제 : https://www.acmicpc.net/problem/1456
  알고리즘 : 정수론, 소수 판정, 에라토스테네스의 체
  티어 : Gold5
*/
#include <iostream>
#include <vector>
#define MAX 10000001
using namespace std;
typedef long long ll;

ll A,B,cnt=0;
bool isPrime[MAX];
vector<int> primeVec;

void Eratostenes(){
    for(int i=2;i<MAX;i++){
        isPrime[i]=true;
    }
    for(int i=2;i*i<=MAX;i++){
		if(isPrime[i]){
            for(int j=i*i;j<MAX;j+=i){
                isPrime[j]=false;
            }
        }
	}  
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>A>>B;
    Eratostenes();
    for(int i=2;i<=MAX;i++){
        if(isPrime[i]) {
            ll num=i;
            while(num<=B/i){
                if(A<=num*i) 
                    cnt++;
                num*=i;
            }
        }
    }
    cout<<cnt<<'\n';
    return 0;
}