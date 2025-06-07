#include<bits/stdc++.h>
using namespace std;

bool Getchange(vector<int>& arr){
    int n=arr.size();
    if(arr[0]==10 || arr[0]==20){
        return false;
    }
    int count5=0;
    int count10=0;
    int count20=0;
    for(int i=0;i<n;i++){
        if(arr[i]==5){
            count5++;
        }
        if(arr[i]==10){
            count5--;
            count10++;
            if(count5<0){
                return false;
            }
        }
        if(arr[i]==20){
            if(count5>=1 && count10>=1){
                count5--;
                count10--;
            }
            else if(count5>=3){
                count5-=3;
            }
            else{
                return false;
            }
            count20++;
        }
    }
    return true;
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
        bool ans=Getchange(arr);
        cout<<ans<<endl;
    }
    return 0;
}


/*Input:8
5
5 5 5 10 20
4
10 5 5 5
5
20 5 5 5 10
7
5 5 20 5 5 10 5
6
5 5 5 5 5 5
4
10 20 10 20
7
5 5 5 5 5 20 10
8
5 5 5 10 5 5 20 5
*/

/*Output
1
0
0
0
1
0
1
1
*/