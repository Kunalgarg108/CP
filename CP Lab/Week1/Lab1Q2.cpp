#include<bits/stdc++.h>
using namespace std;

int gcdRecursive(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

int gcdIterative(int a,int b){
    while(a!=0){
        int temp=a;
        a=b%a;
        b=temp;
    }
    return b;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int val1=gcdIterative(a,b);
        cout<<abs(val1);
    }
}

/*
Input gcdRecursive:
Test Case:8
2 5
6 18
18 6
20 30
132 1024
0 1
- 4 -4
-18 -6
*/

/*
Output gcdRecursive:
1
6
6
10
4
1
4
6
*/

/*
Input gcdIterative:
Test Case:8
2 5
6 18
18 6
20 30
132 1024
0 1
- 4 -4
-18 -6
*/


/*
Output gcdIterative:
1
6
6
10
4
1
4
6
*/