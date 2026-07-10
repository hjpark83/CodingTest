#include <iostream>

#define MAX_NUM 51
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M,K;
    int total=0;
    double result=0;
    cin>>M;
    int Color[MAX_NUM];

    for(int i=0;i<M;i++){
        cin>>Color[i];
        total+=Color[i];
    }
    cin>>K;

    for(int i=0;i<M;i++){
        double cnt=1.0;
        if(Color[i]<K){
            continue;
        }
        for(int j=0;j<K;j++){
            cnt*=(double)(Color[i]-j)/(total-j);
        }
        result+=cnt;
    }
    cout<<fixed;
	cout.precision(15);
    cout<<result<<'\n';
    return 0;
}