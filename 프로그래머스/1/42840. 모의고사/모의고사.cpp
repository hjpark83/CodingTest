#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int supo1[5] = {1,2,3,4,5};
    int supo2[8] = {2,1,2,3,2,4,2,5};
    int supo3[10] = {3,3,1,1,2,2,4,4,5,5};
    int score[3] = {0,0,0};
    int maxScore = 0;
    
    for(int i=0; i<answers.size(); i++){
        if(supo1[i%5]==answers[i])
            score[0]++;
        if(supo2[i%8]==answers[i])
            score[1]++;
        if(supo3[i%10]==answers[i])
            score[2]++;
    }
    
    maxScore = max({score[0], score[1], score[2]});
    if(score[0] == maxScore)
        answer.push_back(1);
    if(score[1] == maxScore)
        answer.push_back(2);
    if(score[2] == maxScore)
        answer.push_back(3);
    
    sort(answer.begin(), answer.end());
    
    return answer;
}