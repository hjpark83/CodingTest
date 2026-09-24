#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    vector<pair<string, int>> tgt;
    for(int i = 0; i < want.size(); i++){
        tgt.push_back({want[i], number[i]});
    }
    
    for(int i = 0; i <= discount.size() - 10; i++){
        vector<pair<string, int>> temp_tgt = tgt;
        
        for(int j = i; j < i + 10; j++){
            string currentItem = discount[j];
            
            for(int k = 0; k < temp_tgt.size(); k++){
                if(temp_tgt[k].first == currentItem 
                   && temp_tgt[k].second > 0){
                    temp_tgt[k].second--;
                    break;
                }
            }
        } 
        
        bool isSuccess = true;
        for(int k = 0; k < temp_tgt.size(); k++){
            if(temp_tgt[k].second > 0){
                isSuccess = false;
                break;
            }
        }
        
        if(isSuccess) {
            answer++;
        }
    }
    
    return answer;
}