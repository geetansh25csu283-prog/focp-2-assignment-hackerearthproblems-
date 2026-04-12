#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool canTurnOff(int l, int n, int k, const string& bulbs) {
    int operations = 0;
    int i = 0;
    while (i < n) {
        if (bulbs[i] == '1') {
            operations++;
            if (operations > k) return false;
        
            i += l;
        } else {
            i++;
        }
    }
    return true;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    string bulbs;
    cin >> bulbs;

    int low = 1, high = n;
    int ans = n;

    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canTurnOff(mid, n, k, bulbs)) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }

    cout << ans << endl;

    return 0;
}