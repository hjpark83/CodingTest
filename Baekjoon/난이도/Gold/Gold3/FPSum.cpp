#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if(n<=1) 
        return false;
    if(n<=3) 
        return true;
    if(n%2==0 || n%3==0) 
        return false;
    for(int i=5; i*i<=n; i+=6){
        if(n%i==0 || n%(i+2)==0) 
            return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int N;
        cin >> N;

        if (cin.eof())
            break;

        vector<int> primes;

        for (int i = 2; i <= N; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }

        vector<vector<int>> combinations;

        int size = primes.size();

        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                for (int k = j; k < size; k++) {
                    for (int l = k; l < size; l++) {
                        if (primes[i] + primes[j] + primes[k] + primes[l] == N) {
                            combinations.push_back({primes[i], primes[j], primes[k], primes[l]});
                        }
                    }
                }
            }
        }

        if (combinations.empty()) {
            cout << "Impossible." << "\n";
        } else {
            for (const vector<int>& comb : combinations) {
                for (int i = 0; i < 4; i++) {
                    cout << comb[i] << " ";
                }
                cout << "\n";
            }
        }
    }
    
    return 0;
}
