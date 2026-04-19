
#include <bits/stdc++.h>
using namespace std;

string solve(int n, vector<int>& a) {
    sort(a.begin(), a.end(), greater<int>());
    
    long long alexSum = 0, bobSum = 0;
    int turn = 0;
    
    set<int> alexUsed, bobUsed;
    for (int i = 0; i < n; i++) {
        if (turn == 0) {
            if (!alexUsed.count(a[i])) {
                alexUsed.insert(a[i]);
                alexSum += a[i];
                turn = 1;
            }
        } else {
            if (!bobUsed.count(a[i])) {
                bobUsed.insert(a[i]);
                bobSum += a[i];
                turn = 0;
            }
        }
    }
    
    return alexSum > bobSum ? "Alex" : "Bob";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(n, a) << "\n";
    }
    return 0;
}