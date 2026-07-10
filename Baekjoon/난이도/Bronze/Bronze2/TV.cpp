#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int D,H,W;
    cin>>D>>H>>W;

    double ratio = sqrt(D * D / (H * H + W * W));

    int real_height = round(ratio * H);
    int real_width = round(ratio * W);

    cout << real_height << " " << real_width;

    return 0;
}