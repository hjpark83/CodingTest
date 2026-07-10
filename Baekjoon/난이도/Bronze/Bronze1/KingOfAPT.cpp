#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;

    int cnt[101][15];
    
    while(T--){    
        int k,n;
        cin>>k>>n;

        for(int i=0;i<=k;i++){
            for(int j=1;j<=n;j++){
                if(i==0){
                    cnt[0][j]=j;
                }else if(j==1){
                    cnt[i][1]=1;
                }else{
                    cnt[i][j]=cnt[i][j-1]+cnt[i-1][j];
                }
            }
        }
        cout<<cnt[k][n]<<'\n';
    }  
    return 0;
}