#include <iostream>
using namespace std;

double CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    double result=0;
    result=(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3);

    return result;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    int x1,y1,x2,y2,x3,y3,x4,y4;
    for(int i=0;i<N;i++){
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        double result1=CCW(x1,y1,x2,y2,x3,y3);
        double result2=CCW(x1,y1,x2,y2,x4,y4);


        cout<<fixed;
        cout.precision(2);

        double Point_X, Point_Y;
        if(result1*result2<0){
            Point_X=(double)((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4))/(double)((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));
            Point_Y=(double)((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4))/(double)((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));

            cout<<"POINT "<<Point_X<<" "<<Point_Y<<'\n';
        }else if(result1==0 && result2==0){
            if(max(x1,x2)>=min(x3,x4) && max(x3,x4)>=min(x1,x2) && max(y1,y2)>=min(y3,y4) && max(y3,y4)>=min(y1,y2)){
                cout<<"POINT "<<fixed<<x1<<" "<<fixed<<y1<<'\n';
            }else{
                cout<<"LINE"<<'\n';
            }
        }else if(result1*result2>0){
            cout<<"NONE"<<'\n';
        }
    }
    return 0;
}