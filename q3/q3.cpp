#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long L, R;
    cin >> L >> R;
    unsigned long long oddCount;
    
    if (L % 2 != 0) {
        oddCount = (R - L) / 2 + 1;
    } else {
        oddCount = (R - L + 1) / 2;
    }
    if (oddCount % 2 != 0)
        cout << "odd" << endl;
    else
        cout << "even" << endl;
    
    return 0;
}