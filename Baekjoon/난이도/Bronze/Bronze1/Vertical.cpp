#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> words(5);
    for (int i = 0; i < 5; i++) {
        cin >> words[i];
    }

    int maxLength = 0;
    for (const string& word : words) {
        int length = word.length();
        if (length > maxLength) {
            maxLength = length;
        }
    }

    string verticalReading;
    for (int i = 0; i < maxLength; i++) {
        for (const string& word : words) {
            if (i < word.length()) {
                verticalReading += word[i];
            }
        }
    }

    cout << verticalReading << endl;

    return 0;
}
