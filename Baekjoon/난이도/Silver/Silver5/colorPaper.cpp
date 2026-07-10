#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int A[100][100]={0};
    int result=0;

    while(N--){
        int x,y;
        cin>>x>>y;

        for(int i=x-1;i<x+9;i++){
            for(int j=y-1;j<y+9;j++){
                A[i][j]++;
                if(A[i][j]<2){
                    result++;
                }
            }
        }
    }
    cout<<result<<endl;
    return 0;
}