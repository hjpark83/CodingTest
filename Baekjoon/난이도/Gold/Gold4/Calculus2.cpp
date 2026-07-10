/*문제 : https://www.acmicpc.net/problem/24726
  알고리즘 : 수학, 기하학, 미적분학
  티어 : Gold4
*/

#include <iostream>
#include <cmath>
using namespace std;

const double PI=3.141592;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    double CCW=0.0;
    CCW=abs((x1*y2+x2*y3+x3*y1)-(x2*y1+x3*y2+x1*y3))/2;
    
    double CG_X=(x1+x2+x3)/3.0;
    double CG_Y=(y1+y2+y3)/3.0;

    double Rotate_X=2*PI*CG_Y*CCW;
    double Rotate_Y=2*PI*CG_X*CCW;

    cout<<fixed;
    cout.precision(10);
    cout<<Rotate_X<<" "<<Rotate_Y<<'\n';
    return 0;
}