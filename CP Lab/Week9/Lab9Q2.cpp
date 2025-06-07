#include <bits/stdc++.h>
using namespace std;
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};
void printHuffmanCodes(Node* root, string code = "") {
    if (root==NULL) return;
    if (!root->left && !root->right) {
        cout << root->ch << ": " << code << endl;
        return;
    }
    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

Node* buildHuffmanCodes(vector<char>& chars, vector<int>& freqs) {
    int n = chars.size();
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    for (int i = 0; i < n; ++i) {
        minHeap.push(new Node(chars[i], freqs[i]));
    }
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }
    Node* root = minHeap.top();
    return root;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<char> chars(n);
        vector<int> freqs(n);
        if(n==1){
            cout<<-1<<endl;
        }
        else{
            for (int i = 0; i < n; ++i) cin >> chars[i];
            for (int i = 0; i < n; ++i) cin >> freqs[i];
            Node* root=buildHuffmanCodes(chars, freqs);
            printHuffmanCodes(root);
        }
    }
    return 0;
}


/*
Input:4
5
a e r d g
1 3 5 10 20
5
a s d f g
1 2 4 3 6
2
a e
1 2
1
a
6
*/

/*
Output:
a: 0000
e: 0001
r: 001
d: 01
g: 1
f: 00
a: 010
s: 011
d: 10
g: 11
a: 0
e: 1
-1
*/

