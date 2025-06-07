#include <bits/stdc++.h>
using namespace std;

int MedianofMeadians(int p, int r, vector<int> &arr)
{
    if (arr.size() == 1){
        return arr[0];
    }
    vector<int> temp;
    for (int i = p; i <= r; i = i + 5)
    {
        if (i + 5 < arr.size())
        {
            sort(arr.begin() + i, arr.begin() + i + 5);
        }
        else
        {
            sort(arr.begin() + i, arr.end());
        }
        int j = min(i + 5, r);
        int median = i + (j - i) / 2;
        temp.push_back(arr[median]);
    }
    return MedianofMeadians(0, temp.size() - 1, temp);
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
        cout<<MedianofMeadians(0,n-1,arr)<<endl;
    }
    return 0;

}

/*Input:5
11
1 3 2 7 6 5 4 12 11 10 9
6
1 2 3 4 5 6
7
7 6 5 4 3 2 1
5
4 2 3 7 6
26
1 3 2 5 4 7 6 88 78 43 12 15 22 31 21 28 65 45 56 53 29 58 60 63 69 199
*/

/*
Output
9
3
1
4
43
*/