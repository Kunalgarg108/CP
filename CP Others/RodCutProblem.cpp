#include<bits/stdc++.h>
using namespace std;

int Solve(vector<int>& length,vector<int>& cost,vector<vector<int>>& dp,int i,int totalLen){
    if(totalLen==0){
        return 0;
    }
    if(i==0){
        if(totalLen>=length[0]){
            return (totalLen/length[0])*cost[0];
        }
        else{
            return 0;
        }
    }
    if(dp[i][totalLen]!=-1){
        return dp[i][totalLen];
    }
    int take=0;
    if(totalLen>=length[i]){
        take=cost[i]+Solve(length,cost,dp,i,totalLen-length[i]);
    }
    int nottake=Solve(length,cost,dp,i-1,totalLen);
    return dp[i][totalLen]=max(take,nottake);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> length(n);
        for(int i=0;i<n;i++){
            cin>>length[i];
        }
        vector<int> cost(n);
        for(int i=0;i<n;i++){
            cin>>cost[i];
        }
        int totalLen=0;
        cin>> totalLen;
        vector<vector<int>> dp(n+1,vector<int> (totalLen+1,-1));
        cout<<Solve(length,cost,dp,n-1,totalLen)<<endl;
    }
}