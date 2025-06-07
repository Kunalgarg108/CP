#include<bits/stdc++.h>
using namespace std;

void Heapify(vector<int>& arr,int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        Heapify(arr,n,largest);
    }
}

void Build_Heap(vector<int>& arr,int n){
    for(int i=n/2;i>=0;i--){
        Heapify(arr,n,i);
    }
} 

int main() {
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<int> arr(n+m);
        vector<int> brr(n);
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }
        for(int j=0;j<n;j++){
            cin>>brr[j];
        }
        Build_Heap(arr,m);
        Build_Heap(brr,n);
        for(int i=0;i<n;i++){
            arr[i+m]=brr[i];
        }
        Build_Heap(arr,m+n);
        for(int i=0;i<m+n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


/*Input
3 3
10 9 8
11 6 5
5 6
4 7 5 1 3
11 23 21 2 6 25
7 7
1 4 7 9 11 14 17
1 4 7 9 11 14 17
7 8
1 3 5 2 7 9 11
13 32 25 43 47 56 41

*/

/*Output
11 9 10 8 6 5
25 23 21 7 6 11 5 1 2 4 3
17 17 7 14 11 4 1 9 14 9 7 1 4 11
56 47 43 41 41 25 13 11 9 7 32 3 1 2
*/