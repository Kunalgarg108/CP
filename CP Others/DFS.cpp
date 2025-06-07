#include<bits/stdc++.h>
using namespace std;
struct Node {
    int vertex;
    Node* next;
    Node(int v) : vertex(v), next(nullptr) {}
};

void dfshelper(int v, vector<Node*>& adjlist, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    Node* temp = adjlist[v];
    while (temp) {
        if (!visited[temp->vertex])
            dfshelper(temp->vertex, adjlist, visited);
        temp = temp->next;
    }
}

void dfs(int start, vector<Node*>& adjlist, int V) {
    vector<bool> visited(V, false);
    dfshelper(start, adjlist, visited);
    cout << endl;
}

int main() {
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

    int start;
    cin >> start;
    cout << start << ": ";
    dfs(start, adjlist, V);

    return 0;
}
