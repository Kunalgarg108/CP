#include<bits/stdc++.h>
using namespace std;
vector<int> HeapSort(vector<int> &arr,int n,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    int j=0;
    vector<int> ans(n);
    for(int i=k;i<n;i++){
        int node=pq.top();
        pq.pop();
        ans[j++]=node;
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        int node=pq.top();
        pq.pop();
        ans[j++]=node;
    }
    return ans;
}

void merge(int p,int q,int r, vector<int> & arr){
    int n1=q-p+1;
    int n2=r-q;
    vector<int>l(n1+1);
    vector<int>b(n2+1);

    for(int i=0;i<n1;i++){
        l[i]=arr[p+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[q+1+i];
    }
    l[n1]=INT_MAX;
    b[n2]=INT_MAX;
    int i=0;
    int j=0;
    for(int k=p;k<=r;k++){
        if(l[i]<=b[j]){
            arr[k]=l[i];
            i=i+1;
        }
        else{
            arr[k]=b[j];
            j=j+1; 
        }
    }
}

void mergesort(int p,int r,vector<int> & arr){
    if(p<r){
        int q=(p+r)/2;
        mergesort(p,q,arr);
        mergesort(q+1,r,arr);
        merge(p,q,r,arr);
    }
}


vector<int> MergeSort(int n,int k, vector<int> &arr){
    int start=0;
    while(start<n){
        int end=min(start+2*k-1,n-1);
        mergesort(start,end,arr);
        start+=k;
    }
    return arr;
}



int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> ans;
        ans=MergeSort(n,k,arr);
        // ans=HeapSort(arr,n,k);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }
}

/*
Input:
6 3
3 2 1 6 5 4
8 3
1 2 3 4 5 6 7 8
8 3
1 2 3 4 6 7 5 8
4 2
3 1 2 4
10 5
10 9 8 7 6 5 4 3 2 1
7 3
5 5 5 5 5 5 5
*/

/*
Output
1 2 3 4 5 6
1 2 3 4 5 6 7 8
1 2 3 4 5 6 7 8
1 2 3 4
1 2 3 4 5 6 7 8 9 10
5 5 5 5 5 5 5
*/