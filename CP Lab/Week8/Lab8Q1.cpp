#include<bits/stdc++.h>
using namespace std;

int BruteForce(int n){
    int set_bit1=__builtin_popcount(n);
    while(1){
        n++;
        int set_bit2=__builtin_popcount(n);
        if(set_bit1==set_bit2){
            return n;
        }
    }
}

vector<bool> Bit_Set(int n) {
    vector<bool> bits(32, 0); 
    for (int i = 0; i < 32; i++) {
        bits[i] = (n & (1 << i)) != 0;
    }
    return bits;
}

int NextSmallestWithVector(int n) {
    vector<bool> bit1 = Bit_Set(n);
    int i = 0, j = 0;
    while (i < 32 && bit1[i] == 0) 
        i++;
    while (i < 32 && bit1[i] == 1) {
        i++;
        j++;
    }
    if (i == 32) return -1;
    bit1[i] = 1;
    for (int k = 0; k < i; k++) {
        bit1[k] = 0;
    }
    for (int k = 0; k < j - 1; k++) {
        bit1[k] = 1;
    }
    int ans = 0;
    for (int k = 0; k < 32; k++) {
        if (bit1[k]) {
            ans |= (1 << k);
        }
    }

    return ans;
}

int NextSmallest(int n){
    if(n==0){
        return 0;
    }
    int c0=0;
    int c1=0;
    int c=n;
    while(((c&1)==0) && c!=0){
        c0++;
        c=c>>1;
    }
    while((c&1)==1 && c!=0){
        c1++;
        c=c>>1;
    }
    int p=c0+c1;
    n|=(1<<p);
    n&=~((1<<p)-1);
    n|=((1<<(c1-1))-1);
    return n;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // int ans=NextSmallest(n);
        // int ans=BruteForce(n);
        int ans=NextSmallestWithVector(n);
        cout<<ans<<endl;
    }
}

/*
Input:5
5
6
12
24
28
15
0
*/

/*
Output:
6
9
17
33
35
23
0
*/