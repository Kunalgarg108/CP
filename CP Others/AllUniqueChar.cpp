#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        unordered_map<char,int> mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        bool check=true;
        for(auto it:mp){
            if(it.second>1){
                check=false;
                break;
            }
        }
        if(check){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}