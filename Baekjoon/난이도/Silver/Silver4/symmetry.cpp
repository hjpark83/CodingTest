#include <iostream>
#include <unordered_set>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cntA, cntB;
    cin>>cntA>>cntB;

    unordered_set<int> A,B;

    int num;
    for(int i=0;i<cntA;i++){
        cin>>num;
        A.insert(num);
    }
    for(int j=0;j<cntB;j++){
        cin>>num;
        B.insert(num);
    }

    int symDiffcnt=0;

    for(int num:A){
        if(B.find(num)==B.end()){
            symDiffcnt++;
        }
    }
    for(int num:B){
        if(A.find(num)==A.end()){
            symDiffcnt++;
        }
    }
    cout<<symDiffcnt<<'\n';
    return 0;
}