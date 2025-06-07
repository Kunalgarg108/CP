#include<bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int>& arr,int e){
    int l=0;
    int r=arr.size()-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==e){
            return mid;
        }
        if(arr[l]<arr[mid]){
            if(arr[l]<=e && arr[mid]>e){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        else{
            if(arr[mid]<e && arr[r]>=e){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int idx=BinarySearch(arr,e);
        cout<<idx<<endl;
    }
    return 0;
}


/*
Input:9
6 4
1 3 4 6 14 19
7 3
8 1 2 3 4 5 7
6 4
5 8 9 1 2 4
6 5
5 6 7 8 1 3
6 6
5 6 7 9 1 4
6 2
4 5 6 7 2 3
1 3
3
2 5
19 5
2 16
3 16
*/

/*
Output:
2
3
5
0
1
4
0
1
0
*/