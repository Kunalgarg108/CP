#include<bits/stdc++.h>
using namespace std;
struct Node {
    int vertex;
    Node* next;
    Node(int v) : vertex(v), next(nullptr) {}
};

void bfs(int start, vector<Node*>& adjlist, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        Node* temp = adjlist[v];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = true;
                q.push(temp->vertex);
            }
            temp = temp->next;
        }
    }
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
    bfs(start, adjlist, V);

    return 0;
}
