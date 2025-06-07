#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum1(vector<int>& arr, int x) {
    vector<pair<int, int>> indexedArr; 
    for (int i = 0; i < arr.size(); i++) {
        indexedArr.push_back({arr[i], i});
    }
    sort(indexedArr.begin(), indexedArr.end());
    int low = 0;
    int high = arr.size() - 1;
    while (low < high) {
        int sum = indexedArr[low].first + indexedArr[high].first;
        if (sum == x) {
            return {indexedArr[low].second, indexedArr[high].second}; 
        } else if (sum < x) {
            low++;
        } else {
            high--;
        }
    }
    return {}; 
}

vector<int> twoSum2(vector<int>& arr, int target) {
    unordered_map<int, int> mp; 
    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i}; 
        }
        mp[arr[i]] = i; 
    }
    return {}; 
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> result = twoSum2(arr, x);
        if (!result.empty()) {
            cout<<result[0] <<" "<< result[1]<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
}

/* 
Input:
Test Cases:6
5 9
2 7 11 15 1
4 10
1 2 3 4
6 8
1 3 4 4 5 3
1 5
5
5 -1
-2 -3 4 1 2
4 0
0 0 3 7
*/

/*
Output:
0 1
-1
1 4
-1
0 3
0 1
*/