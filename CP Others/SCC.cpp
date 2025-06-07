#include<bits/stdc++.h>
using namespace std;

void dfs1(int v,vector<vector<int>>& adj,vector<bool>& visited,stack<int>& st) {
    visited[v] = true;
    for(auto u:adj[v]) {
        if(!visited[u])
            dfs1(u, adj, visited, st);
    }
    st.push(v);
}

void dfs2(int v,vector<vector<int>>& transpose,vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";
    for(auto u:transpose[v]) {
        if(!visited[u])
            dfs2(u, transpose, visited);
    }
}

void SCC(int n, int m) {
    vector<vector<int>> adj(n);
    vector<vector<int>> transpose(n);
    vector<bool> visited(n, false);
    stack<int> st;
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 0;i < n;i++) {
        if(!visited[i])
            dfs1(i, adj, visited, st);
    }
    for(int i = 0;i < n;i++) {
        for(auto u:adj[i]) {
            transpose[u].push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    while(!st.empty()) {
        int v = st.top();
        st.pop();
        if(!visited[v]) {
            dfs2(v, transpose, visited);
            cout << endl;
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        SCC(n, m);
    }
    return 0;
}
