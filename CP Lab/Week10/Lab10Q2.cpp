#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode {
    int vertex, key;
};

class MinHeap {
public:
    vector<MinHeapNode> heap;
    vector<int> pos;
    int size;

    MinHeap(int V) {
        size = V;
        heap.resize(V);
        pos.resize(V);
    }

    void swapNodes(int i, int j) {
        swap(heap[i], heap[j]);
        pos[heap[i].vertex] = i;
        pos[heap[j].vertex] = j;
    }

    void heapify(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1, right = 2 * idx + 2;

        if (left < size && heap[left].key < heap[smallest].key)
            smallest = left;
        if (right < size && heap[right].key < heap[smallest].key)
            smallest = right;
        
        if (smallest != idx) {
            swapNodes(idx, smallest);
            heapify(smallest);
        }
    }

    MinHeapNode extractMin() {
        if (size == 0) return {-1, -1};
        MinHeapNode root = heap[0];
        heap[0] = heap[size - 1];
        pos[heap[0].vertex] = 0;
        size--;
        heapify(0);
        return root;
    }

    void decreaseKey(int v, int key) {
        int i = pos[v];
        heap[i].key = key;
        while (i > 0 && heap[i].key < heap[(i - 1) / 2].key) {
            swapNodes(i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }

    bool isInHeap(int v) {
        return pos[v] < size;
    }
};

void primMST(vector<vector<pair<int, int>>> &graph, int V) {
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    MinHeap minHeap(V);

    for (int v = 0; v < V; v++) {
        minHeap.heap[v] = {v, key[v]};
        minHeap.pos[v] = v;
    }

    key[0] = 0;
    minHeap.decreaseKey(0, 0);

    while (minHeap.size > 0) {
        MinHeapNode minNode = minHeap.extractMin();
        int u = minNode.vertex;
        inMST[u] = true;
        for (auto &[v, weight] : graph[u]) {
            if (!inMST[v] && minHeap.isInHeap(v) && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                minHeap.decreaseKey(v, weight);
            }
        }
    }
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " " << key[i] << endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int V;
        cin>>V;
        vector<vector<pair<int, int>>> graph(V);
        int E;
        cin>>E;
        for(int i=0;i<E;i++){
            int node;
            int adjnode;
            int wt;
            cin>>node>>adjnode>>wt;
            graph[node].push_back({adjnode,wt});
        }
        primMST(graph, V);
    }
    return 0;
}


/*
Input:
3
3
0 1 1
1 2 2
0 2 3
4 
5
0 1 1
1 2 1
2 3 1
3 0 1
*/

/*
Output:a
0 - 1   1
1 - 2   2
0 - 1   1
1 - 2   1
2 - 3   1
*/