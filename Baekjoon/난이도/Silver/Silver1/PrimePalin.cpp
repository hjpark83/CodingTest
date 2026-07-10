#include <iostream>
#include <vector>
#include <string>
#include <cmath>
const int MAX_NUM=1100000;

using namespace std;

bool isPalin(int n){
    string numStr=to_string(n);
    int left=0;
    int right=numStr.length()-1;

    while(left<=right){
        if(numStr[left]!=numStr[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    
    vector<int> A(MAX_NUM+1,1);
    A[0]=A[1]=0;

    for(int i=2;i<=sqrt(MAX_NUM);i++){
        if(A[i]==1){
            for(int j=i*i;j<=MAX_NUM;j+=i){
                A[j]=0;
            }
        }
    }
    int target=N;

    while(true){
        if(target>MAX_NUM){
            break;
        }
        if(A[target]==1 && isPalin(target)){
            cout<<target<<'\n';
            break;
        }
        target++;
    }

    return 0;
}