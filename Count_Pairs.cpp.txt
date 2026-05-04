#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 1;
int omega[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < MAXN; i++){
        if(omega[i] == 0){           
            for(int j = i; j < MAXN; j += i){
                omega[j]++;
            }
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (1 << omega[n]) << "\n";
    }
    return 0;
}