#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int B,S,D;
    cin>>B>>S>>D;
    
    vector<int> burger(B,0);
    vector<int> side(S,0);
    vector<int> drink(D,0);

    vector<int> SetMenu;
    vector<int> Individual;

    int total=0;

    for(int i=0;i<B;i++){
        cin>>burger[i];
        total+=burger[i];
    }
    for(int i=0;i<S;i++){
        cin>>side[i];
        total+=side[i];
    }
    for(int i=0;i<D;i++){
        cin>>drink[i];
        total+=drink[i];
    }

    sort(burger.begin(), burger.end(),greater<int>());
    sort(side.begin(), side.end(),greater<int>());
    sort(drink.begin(), drink.end(),greater<int>());

    int min_sets = min({B, S, D});

    for (int i = 0; i < min_sets; i++) {
        int setPrice=(burger[i] + side[i] + drink[i]) * 0.9;
        SetMenu.push_back(setPrice);
    }

    for (int i = min_sets; i < B; i++) {
        Individual.push_back(burger[i]);
    }
    for (int i = min_sets; i < S; i++) {
        Individual.push_back(side[i]);
    }
    for (int i = min_sets; i < D; i++) {
        Individual.push_back(drink[i]);
    }

    int setTotal=0;
    for(int price:SetMenu){
        setTotal+=price;
    }
    for(int idv:Individual){
        setTotal+=idv;
    }
    cout<<total<<'\n'<<setTotal<<'\n';
    return 0;
}