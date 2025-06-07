#include<bits/stdc++.h>
using namespace std;

int Prefix_Max(vector<pair<int,int>>& arr,int n){
    vector<int> vec(n+1,0);
    int m=arr.size();
    for(int i=0;i<m;i++){
        vec[arr[i].first]++;
        vec[arr[i].second+1]--;
    }
    for(int i=1;i<=n;i++){
        vec[i]=vec[i]+vec[i-1];
    }
    int maxi=*max_element(vec.begin(),vec.end());
    return maxi*100;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> arr;
        int a,b;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            //Cases like a>b or a<0 or b<0 are ignore
            if(a>b || a<0 || b<0){
                exit(0);
            }
            arr.push_back({a,b});
        }
        cout<<Prefix_Max(arr,n)<<endl;
    }
}


/*
Input:5
6 3
2 5
1 3
1 4
4 3
1 2
2 3
0 3
1 2
0 0
0 0
9 4
1 2
3 4
5 6
7 8
5 0

*/

/*
Output
300
300
200
100
0
*/