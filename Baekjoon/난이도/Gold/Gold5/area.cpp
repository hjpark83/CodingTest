/*문제 : https://www.acmicpc.net/problem/2166
  알고리즘 : 기하학
  티어 : Gold5
*/

#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    long x[100000],y[100000];

    for(int i=0;i<N;i++){
        cin>>x[i]>>y[i];
    }
    x[N]=x[0];
    y[N]=y[0];
    double result=0;

    for(int i=0;i<=N;i++){
        result+=((x[i]*y[i+1])-(x[i+1]*y[i]));
    }
    cout<<fixed;    
    cout.precision(1);
    cout<<abs(result)/2.0<<endl;
    return 0;
}