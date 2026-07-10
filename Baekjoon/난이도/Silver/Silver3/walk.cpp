#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

lli X,Y,W,S;
lli result=0;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>X>>Y>>W>>S;

    if(Y>X){
        if(2*W>S){
            if(S>W){
                result+=(X*S+(Y-X)*W);
            }else{
                if((X+Y)%2==1 && X!=Y){
                    result+=((Y-1)*S+W);
                }else{
                    result+=Y*S;
                }
            }
        }else{
            result+=((X+Y)*W);
        }
    }else{
        if(2*W>S){
            if(S>W){
                result+=(Y*S+(X-Y)*W);
            }else{
                if((X+Y)%2==1 && X!=Y){
                    result+=((X-1)*S+W);
                }else{
                    result+=X*S;
                }
            }
        }else{
            result+=((X+Y)*W);
        }
    }
    cout<<result<<'\n';
    return 0;
}