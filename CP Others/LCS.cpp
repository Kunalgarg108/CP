#include<bits/stdc++.h>
using namespace std;

int Solve(string s1,string s2,int i,int j,vector<vector<int>>& dp){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int take=0;
    if(s1[i-1]==s2[j-1]){
        take=1+Solve(s1,s2,i-1,j-1,dp);
    }
    int nottake=max(Solve(s1,s2,i-1,j,dp),Solve(s1,s2,i,j-1,dp));
    return dp[i][j]=max(take,nottake);
}

int LCS1(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
    int ans=Solve(s1,s2,n,m,dp);
    return ans;
}

int main(){
    int t;
    cin>> t;
    while(t--){
        string s1,s2;
        cin>> s1 >> s2;
        int ans= LCS1(s1,s2);
        cout << ans << endl;
    }
}