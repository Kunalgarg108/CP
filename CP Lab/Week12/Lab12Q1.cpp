#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                          vector<int>& inorder, int inStart, int inEnd,
                          unordered_map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;
    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);
    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart;
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                 inorder, inStart, inRoot - 1, inMap);
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                  inorder, inRoot + 1, inEnd, inMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;
    return buildTreeHelper(preorder, 0, preorder.size() - 1,
                           inorder, 0, inorder.size() - 1, inMap);
}

void printPostorder(TreeNode* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

bool Checkinorder(TreeNode* root, vector<int>& inorder, int& i) {
    if (root == NULL)
        return true;

    if (!Checkinorder(root->left, inorder, i)) return false;
    if (i >= inorder.size() || root->val != inorder[i]) return false;
    i++;
    if (!Checkinorder(root->right, inorder, i)) return false;

    return true;
}

bool Checkpreorder(TreeNode* root, vector<int>& preorder, int& i) {
    if (root == NULL)
        return true;

    if (i >= preorder.size() || root->val != preorder[i]) return false;
    i++;
    if (!Checkpreorder(root->left, preorder, i)) return false;
    if (!Checkpreorder(root->right, preorder, i)) return false;

    return true;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> preorder(n), inorder(n);
        for (int i = 0; i < n; i++) cin >> preorder[i];
        for (int i = 0; i < n; i++) cin >> inorder[i];
        TreeNode* root = buildTree(preorder, inorder);
        int i = 0;
        bool check = Checkinorder(root, inorder, i);
        if (!check || i != n) { 
            cout << -1 << endl;
            continue;
        }
        i = 0;
        check = Checkpreorder(root, preorder, i);
        if (!check || i != n) {
            cout << -1 << endl;
            continue;
        }
        printPostorder(root);
        cout << endl;
    }
    return 0;
}


/*
Input:4
3
10 8 7
8 10 7
11
10 5 12 2 1 14 11 16 8 6 9
2 12 1 5 11 14 16 10 6 8 9
4
10 8 7 6
7 8 6 10
6
10 12 2 1 22 3
10 1 2 22 12 3 
*/

/*
Output:
8 7 10
2 1 12 11 16 14 5 6 9 8 10
7 6 8 10
1 22 2 3 12 10
*/