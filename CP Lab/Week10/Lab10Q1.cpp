#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> x;
void next_value(int k){
    while(true){
        x[k]=(x[k]+1)%(n+1);
        if(x[k]==0){
            return;
        }
        bool check=true;
        for(int i=0;i<k;i++){
            if(x[i]==x[k] || abs(x[i]-x[k])==abs(i-k)){
                check=false;
                break;
            }
        }
        if(check){
            return;
        }
    }
}

void general_backtrack(int k){
    while(true){
        next_value(k);
        if(x[k]==0){
            return;
        }
        if(k==n-1){
            for(int i=0;i<n;i++){
                cout<<x[i]<<" ";
            }
            cout<<endl;
        }
        else{
            general_backtrack(k+1);
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        x.assign(n,0);
        general_backtrack(0);
    }
}


/*Input:4
4
5
6
3
*/


/*Output
2 4 1 3 
3 1 4 2 
1 3 5 2 4 
1 4 2 5 3 
2 4 1 3 5 
2 5 3 1 4 
3 1 4 2 5 
3 5 2 4 1 
4 1 3 5 2 
4 2 5 3 1 
5 2 4 1 3
5 3 1 4 2
2 4 6 1 3 5 
3 6 2 5 1 4
4 1 5 2 6 3
5 3 1 6 4 2
*/
