#include<bits/stdc++.h>
using namespace std;
int minProduct(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int negativeCount = 0;
    int zeroCount = 0;
    int product = 1;
    int largestNegative = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) {
            zeroCount++;
            continue;
        }

        if (arr[i] < 0) {
            negativeCount++;
            largestNegative = max(largestNegative, arr[i]);
        }

        product *= arr[i];
    }
    if (negativeCount == 0 && zeroCount == 0) {
        return arr[0]; 
    }
    if (zeroCount == n || (zeroCount > 0 && negativeCount == 0)) {
        return 0;
    }
    if (negativeCount % 2 == 0) {
        product /= largestNegative;
    }

    return product;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout << minProduct(arr) << endl;
    }
    return 0;
}

/*
Input:7
1 2 3 5
-1 -2 -3 -4
1 0 2 -3
0 0 0
3
-7
-1 -4 -7 2 4 -8
*/

/*
Output:
1
-24
-6
0
3
-7
-1792
*/