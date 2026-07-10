#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool is_prime(long long num) {
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    long long num;
    for (int i = 0; i < N; i++) {
        cin >> num;

        while (!is_prime(num)) {
            num++;
        }

        cout << num << '\n';
    }

    return 0;
}