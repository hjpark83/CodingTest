#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    
    vector<int> length(N-1);
    vector<int> price(N);

    for(int i=0;i<N-1;i++){
        cin>>length[i];
    }
    for(int i=0;i<N;i++){
        cin>>price[i];
    }
    long long min_price=price[0];
    long long total=0;

    for(int i=0;i<N-1;i++){
        min_price=min(min_price,(long long)price[i]);
        total+=min_price*length[i];
    }
    cout<<total<<endl;
    return 0;   
}