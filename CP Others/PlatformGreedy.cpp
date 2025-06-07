#include<bits/stdc++.h>
using namespace std;

int findMinPlatforms(vector<int>& arrival, vector<int>& departure) {
    int n = arrival.size();
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int platforms = 0, maxPlatforms = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        } else {
            platforms--;
            j++;
        }
    }

    return maxPlatforms;
}

int main() {
    int n;
    cin >> n;
    vector<int> arrival(n), departure(n);

    for (int i = 0; i < n; ++i)
        cin >> arrival[i];
    for (int i = 0; i < n; ++i)
        cin >> departure[i];

    cout << findMinPlatforms(arrival, departure) << endl;
    return 0;
}
