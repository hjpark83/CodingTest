#include <iostream>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string origin;
    set<string> S1;

    for (int i = 0; i < N; i++) {
        cin >> origin;
        S1.insert(origin);
    }

    int count = 0;
    for (int i = 0; i < M; i++) {
        cin >> origin;
        if (S1.find(origin) != S1.end()) {
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
