#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    const int numScore=8;
    int Score[numScore];

    for(int i=0;i<8;i++){
        cin>>Score[i];
    }
    int indices[numScore];
    for(int i=0;i<numScore;i++){
        indices[i]=i;
    }

    sort(indices,indices+numScore,[&](int a, int b){
        return Score[a]>Score[b];
    });

    int totalScore=0;
    for(int i=0;i<5;i++){
        totalScore+=Score[indices[i]];
    }
    cout<<totalScore<<endl;

    sort(indices,indices+5);
    for(int i=0;i<5;i++){
        cout<<indices[i]+1<<" ";
    }
    cout<<endl;
    return 0;
}