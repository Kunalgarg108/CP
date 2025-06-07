#include<bits/stdc++.h>
using namespace std;

int MinCoin(vector<int>& arr,vector<vector<int>>& dp,int i,int k){
    if(k==0){
        return 0;
    }
    if(i==0){
        if(k%arr[0]==0){
            return k/arr[0];
        }
        else{
            return 1e9;
        }
    }
    if(dp[i][k]!=-1){
        return dp[i][k];
    }
    int take=1e9;
    if(k>=arr[i]){
        take=1+MinCoin(arr,dp,i,k-arr[i]);
    }
    int nottake=MinCoin(arr,dp,i-1,k);
    return dp[i][k]=min(take,nottake);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int k;
        cin>>k;
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        int ans=MinCoin(arr,dp,n-1,k);
        if(ans>=1e9){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}