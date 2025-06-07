#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int>& arr){
    int n=arr.size();
    int maxi=0;
    int best_max=INT_MIN;
    for(int i=0;i<n;i++){
        maxi+=arr[i];
        if(best_max<maxi){
            best_max=maxi;
        }
        if(maxi<0){
            maxi=0;
        }
    }
    return best_max;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n>0)
            cout<<kadane(arr)<<endl;
        else 
            cout<<"Invalid"<<endl;

    }
}

/*
Input:6
6
1 3 2 4 5 7
5
-2 -4 -5 -8 -6
7
-3 5 -7 2 4 3 -9
1
6
1
-8
0

6
2147483600 12 -15 48 -7 9
*/

/*
Output
22
-2
9
6
-8
Invalid
2147483647
*/