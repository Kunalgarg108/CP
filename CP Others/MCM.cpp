#include<bits/stdc++.h>
using namespace std;

int Solve(vector<int>& arr,int i,int j,vector<vector<int>>& dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
        int cost=Solve(arr,i,k,dp)+Solve(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
        mn=min(mn,cost);
    }
    return dp[i][j]=mn;
}

int MCM(vector<int>& arr,int n){
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    return Solve(arr,1,n-1,dp);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=MCM(arr,n);
        cout<< ans << endl;
    }
}