#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    int count=1, start_index=1, end_index=1, sum=1;

    while(end_index!=N){
        if(sum==N){
            count++;
            end_index++;
            sum+=end_index;
        }else if(sum>N){
            sum-=start_index;
            start_index++;
        }else if(sum<N){
            end_index++;
            sum+=end_index;
        }
    }
    cout<<count<<'\n';
    return 0;
}