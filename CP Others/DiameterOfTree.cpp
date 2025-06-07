#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = right = nullptr;
    }
};

Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;
    Node* root = new Node(val);
    int l,r;
    cin >>l;
    if(l){
        root->left=buildTree();
    }
    cin >>r;
    if(r){
        root->right=buildTree();
    }
    return root;
}
int diameter = 0;

int height(Node* root) {
    if (root==nullptr) 
        return 0;
    int left=height(root->left);
    int right=height(root->right);
    diameter = max(diameter,left + right);
    return max(left,right) + 1;
}

int main() {
    Node* root = buildTree();  
    height(root);
    return 0;
}
