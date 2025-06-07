//H.W

#include<bits/stdc++.h>
using namespace std;
int kthSmallest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
    for (int i = 0; i < k - 1; ++i) {
        minHeap.pop();
    }
    return minHeap.top();
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<kthSmallest(arr, k)<<endl;
    }
}