#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;

    int denominator=a*e-b*d;
    int son_x=c*e-b*f;
    int son_y=a*f-c*d;

    cout<<son_x/denominator<<" "<<son_y/denominator<<'\n';
    return 0;
}