#include<bits/stdc++.h>
using namespace std;
vector<int> Stockspan(vector<int> &arr,int n){
    stack<int> st;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=i+1;
        }
        else {
            ans[i]=i-st.top();
        }
        st.push(i);
    }
    return ans;
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
        vector<int> ans=Stockspan(arr,n);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }
}

/*
Input:7
6
1 3 5 7 9 11
5
22 11 10 8 4
7
100 80 85 70 60 75 90
6
55 55 55 55 55 55
4
0 0 0 0
1
5
2
77 55

*/

/*
Output
1 2 3 4 5 6
1 1 1 1 1
1 1 2 1 1 3 6
1 1 1 1 1 1 
1 1 1 1
1
1 1
*/