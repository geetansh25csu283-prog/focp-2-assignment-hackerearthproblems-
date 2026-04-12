#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000000;

int prime_counts[MAXN + 1];


void sieve() {
    for (int i = 2; i <= MAXN; ++i) {
        if (prime_counts[i] == 0) { 
            for (int j = i; j <= MAXN; j += i) {
                prime_counts[j]++;
            }
        }
    }
}


long long powerOfTwo(int k) {
    return 1LL << k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if (N == 1) {
            cout << 1 << "\n";
        } else {
            cout << powerOfTwo(prime_counts[N]) << "\n";
        }
    }
    return 0;
}