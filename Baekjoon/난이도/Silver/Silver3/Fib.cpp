#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;

    int* arr;
    while(T--){
        int num;
        cin>>num;
        if(num<2){
            if(num==0)
                cout<<"1 0"<<'\n';
            else
                cout<<"0 1"<<'\n';
        }else{
            arr=new int[41];
            arr[0]=1,arr[1]=1;
            for(int i=2;i<num;i++){
                arr[i]=arr[i-1]+arr[i-2];
            }
            cout<<arr[num-2]<<" "<<arr[num-1]<<'\n';
        }
    }
    return 0;
}