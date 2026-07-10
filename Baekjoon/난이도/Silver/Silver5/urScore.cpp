#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

namespace SCORE{
    const map<string,double> points{
        {"A+",4.5},{"A0",4.0},{"B+",3.5},{"B0",3.0},{"C+",2.5},{"C0",2.0},{"D+",1.5},{"D0",1.0},{"F",0.0}
    };
};

double grade_to_point(const string& grade){
    auto it=SCORE::points.find(grade);
    if(it!=SCORE::points.end()){
        return it->second;
    }
    return 0.0;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<tuple<string,double,string>> A;
    
    int credit=0;
    double total=0.0;
    for(int i=0;i<20;i++){
        string subject,grade;
        double score;
        cin>>subject>>score>>grade;

        A.emplace_back(subject,score,grade);
        if(grade!="P"){
            total+=grade_to_point(grade)*score;
            credit+=score;
        }
    }

    cout.precision(6);
    cout<<fixed<<total/credit<<endl;
    return 0;
}