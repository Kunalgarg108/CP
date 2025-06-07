#include<bits/stdc++.h>
using namespace std;

vector<int> Sieve(int n){
    vector<int> PrimeNumber(n+1,1);
    PrimeNumber[0]=0;
    PrimeNumber[1]=0;
    for(int i=2;i*i<=n;i++){
        if(PrimeNumber[i]==1){
            for(int j=i*i;j<=n;j=j+i){
                PrimeNumber[j]=0;
            }
        }
    }
    return PrimeNumber;
}

int main()
{
    int t;
    cin>>t;
    vector<int> PrimeNumber=Sieve(1000000);
    while(t--){
        int m,n;
        cin>>m;
        cin>>n;
        if(n<0){
            continue;
        }
        else if(n<m){
            continue;
        }
        else 
        {
            for(int i=m;i<=n;i++){
                if(PrimeNumber[i]==1){
                    cout<<i<<" ";
                }
            }
        }
    }

}


/* 
Input:
Test Cases:8
2 10
1 50
13 107
5 3
5 5
8 8
-8 37
-177 -132
*/

/*
Output:
2 3 5 7
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 
13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107

5

2 3 5 7 11 13 17 19 23 29 31 37 

*/