#include <iostream>
#include <vector>
#include <cmath>

void leastSquares(double x[],double y[],int n,double& a,double& b){
    long double sum_x=0.0,sum_y=0.0,sum_xy=0.0,sum_x2=0.0,sum_y2=0.0;

    for (int i=0;i<n;i++){
        sum_x+=x[i];
        sum_y+=y[i];
        sum_xy+=x[i]*y[i];
        sum_x2+=x[i]*x[i];
    }

    double denominator=(n*sum_x2)-(sum_x*sum_x);
    a=static_cast<double>((n*sum_xy)-(sum_x*sum_y))/denominator;
    b=static_cast<double>(sum_y-(a*sum_x))/n;
}
int main(void){
    int num;
    std::cin>>num;
    std::vector<double> x(num,0);
    std::vector<double> y(num,0);

    for (int i=0;i<num;i++){
        std::cin>>x[i]>>y[i];
    }
    double a,b;
    leastSquares(x.data(),y.data(),num,a,b);
    std::cout<<round(a)<<" "<<round(b)<<std::endl;

    return 0;
}