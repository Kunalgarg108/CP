#include<bits/stdc++.h>
using namespace std;

vector<int> Solve(vector<int>& arr,int n){
    int m=arr.size();
    int xorr=0;
    for(int i=0;i<m;i++){
        xorr^=arr[i];
    }
    for(int i=0;i<=n;i++){
        xorr^=i;
    }
    int set_bit=xorr & ~(xorr-1);
    int x=0,y=0;
    for(int i=0;i<m;i++){
        if(arr[i] & set_bit){
            x^=arr[i];
        }else{
            y^=arr[i];
        }
    }
    for(int i=0;i<=n;i++){
        if(i & set_bit){
            x^=i;
        }else{
            y^=i;
        }
    }
    return {x,y};
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n+2);
        for(int i=0;i<n+2;i++){
            cin>>arr[i];
        }
        vector<int> ans=Solve(arr,n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
        cout<<endl;
    }
}


/*Input
5
1 3 2 4 5 2 3
7
1 5 4 3 2 6 1 7 7
2
1 2 2 1
5
1 2 4 4 5 5 3
5
2 3 1 2 1 4 5
*/

/*
Output:
1 5
5 6
0 0
1 3
3 5
*/