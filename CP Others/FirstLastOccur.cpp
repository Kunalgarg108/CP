#include<bits/stdc++.h>
using namespace std;

int first(vector<int>& arr,int x) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while(low <= high) {
        int mid = low +(high - low)/2;
        if(arr[mid] == x) {
            ans=mid;
            high=mid - 1;
        }
        else if(arr[mid] < x) {
            low=mid + 1;
        }
        else {
            high=mid - 1;
        }
    }
    return ans;
}
int last(vector<int>& arr,int x) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while(low <= high) {
        int mid = low +(high - low)/2;
        if(arr[mid] == x) {
            ans=mid;
            low=mid + 1; 
        }
        else if(arr[mid] < x) {
            low=mid + 1;
        }
        else {
            high=mid - 1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for(int i=0; i<n; i++) 
            cin >> arr[i];
        int f =first(arr, x);
        int l =last(arr, x);
        cout<<f<<" "<<l<<endl;
    }
    return 0;
}
