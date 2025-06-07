#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void dfs(TreeNode* root , int k , vector<vector<int>> &ans , vector<int> &temp , int sum)
{
    if(root == NULL){
        return;
    }
    sum += root->val;
    temp.push_back(root->val);
    if(sum == k)
    {
        ans.push_back(temp);
    }
    dfs(root->left , k , ans , temp , sum);
    dfs(root->right , k , ans , temp , sum);

    temp.pop_back();
}

void checkpaths(TreeNode* root , int k , vector<vector<int>> &ans)
{
    vector<int> temp;
    int sum = 0;
    dfs(root , k , ans , temp ,sum);
}

TreeNode* input(TreeNode * root)
{
    int check;
    cin >> check;
    if(check == 1)
    {
        int data;
        cin >> data;
        TreeNode* newnode = new TreeNode(data);
        root = newnode;  
    }
    if(check == 0)
    {
        root = NULL;
        return root;
    }
    root->left = input(root->left);
    root->right = input(root->right);
    return root;
}

void preorder(TreeNode* root)
{
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void print(vector<vector<int>> &ans)
{
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        TreeNode* node = input(NULL);
        int k;
        cin >>k;
        vector<vector<int>> ans;
        preorder(node);
        cout << endl;
        checkpaths(node , k , ans);
        print(ans);
        cout << endl;
    }
}


/*
Input:2
1 5
1 3
0
0
1 2
0
0
8
1 1
1 2
0
0
1 3
0
0
10
*/

/*
Output:
5 3 2 
5 3 
1 2 3 
-1
*/


