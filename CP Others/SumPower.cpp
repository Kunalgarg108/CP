//H.W

#include <bits/stdc++.h>
using namespace std;
long SumPower(string s, int n, int k) {
    long ans = 0;
    int changes = 0;
    for (int i = 0; i < k - 1; ++i) {
        if (s[i] != s[i + 1]) {
            ++changes;
        }
    }
    for (int i = k - 1; i < n - 1; ++i) {
        if (s[i] != s[i + 1]) {
            ++changes; 
        }
        ans += changes;
        if (s[i - k + 1] != s[i - k + 2]) {
            --changes; 
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << SumPower(s, n, k) << endl;
    }
}
