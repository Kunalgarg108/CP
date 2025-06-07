#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};
bool dfs(int v, vector<Node*>& adjlist, vector<bool>& visited, vector<bool>& recStack) {
    visited[v] = true;
    recStack[v] = true;
    
    Node* temp = adjlist[v]; 
    while (temp!=NULL) {
        int neighbor = temp->val;
        if (!visited[neighbor] && dfs(neighbor, adjlist, visited, recStack))
            return true;
        else if (recStack[neighbor]) 
            return true;
        temp = temp->next;
    }
    
    recStack[v] = false;
    return false;
}

bool bfs(int V,vector<Node*>& adjlist){
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        Node* temp=adjlist[i];
        while(temp!=NULL){
            int node_val=temp->val;
            indegree[node_val]++;
            temp=temp->next;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    int count=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;
        Node* temp=adjlist[node];
        while(temp){
            int val=temp->val;
            indegree[val]--;
            if(indegree[val]==0){
                q.push(val);
            }
            temp=temp->next;
        }
    }
    if(count==V){
        return false;
    }
    return true;
}

bool isCycle(int V, vector<Node*>& adjlist) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dfs(i, adjlist, visited, recStack)) 
            return true;
    } 
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V;
        cin >> V;
        vector<Node*> adjlist(V, nullptr); 
        for (int i = 0; i < V; i++) {
            int E;
            cin >> E;
            Node* head = nullptr;
            Node* tail = nullptr;
            for (int j = 0; j < E; j++) {
                int x;
                cin >> x;
                Node* newNode = new Node(x);
                
                if (!head) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
            adjlist[i] = head; 
        }
        cout << (bfs(V, adjlist) ? 1 : 0) << endl;
        cout << (isCycle(V, adjlist) ? 1 : 0) << endl;
    }
    return 0;
}


/*
Input:3
6
1 1
2 2 5
1 3
1 4
2 0 1
0
5
1 1
1 2
1 3
1 4
0
5
1 1
2 3 4
0
1 4
1 2
*/

/*
Output
1 
0
0
*/