#include<bits/stdc++.h>
using namespace std;

vector<int> Find(vector<vector<int>>& arr, int k){
    int n=arr.size();
    int m=arr[0].size();
    int row=0;
    int col=m-1;
    while(row>=0 && col<m){
        if(arr[row][col]==k){
            return {row,col};
        }
        else if(arr[row][col]>k){
            col--;
        }
        else{
            row++;
        }
    }
    return {-1,-1};
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               cin>>arr[i][j];
            }
        }
        vector<int> ans=Find(arr,k);
        cout<< ans[0]<<" "<<ans[1]<<endl;

    }
    return 0;
}