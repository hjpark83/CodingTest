#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> A;
    bool isPalin=false;

    for(int i=0;;i++){
        int num;
        cin>>num;

        if(num==0){
            break;
        }
        A.push_back(num);
    }
    for(int i=0;i<A.size();i++){
        string numStr=to_string(A[i]);
        int numDigit=numStr.length();
        bool isPalin=true;
        for(int j=0;j<numDigit/2;j++) {
            if(numStr[j]!=numStr[numDigit-j-1]){
                isPalin=false;
                break;
            }
        }
        if(isPalin){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}