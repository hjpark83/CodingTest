#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> Score(N);
    for(int i=0;i<N;i++){
        cin>>Score[i];
    }

    int result=0;
    if(Score[0]>Score[2])
        result+=abs(Score[0]-Score[2])*508;
    else
        result+=abs(Score[0]-Score[2])*108;

    if(Score[1]>Score[3])
        result+=abs(Score[1]-Score[3])*212;
    else
        result+=abs(Score[1]-Score[3])*305;

    if(N==5){
        result+=Score[4]*707;
    }

    cout<<result*4763<<'\n';
    return 0;
}