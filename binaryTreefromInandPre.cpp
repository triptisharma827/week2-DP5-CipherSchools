#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* fun(vector<int>& pre , vector<int>& in ,int inS ,int inE ,int preS ,int preE)
    {
        if(inS>inE || preS>preE) return NULL; //base case
        int rootData=pre[preS];
        int i=0;
        for(;i<pre.size();i++)
        {
            if(in[i]==rootData) break; //find where root is in inorder vector
        }
        int leftInOrderStart=inS;  
        int leftInOrderEnd=i-1; 
        int leftPreOrderStart=preS+1;
        int leftPreOrderEnd=leftInOrderEnd+leftPreOrderStart-leftInOrderStart;

        int rightInOrderStart=i+1;
        int rightInOrderEnd=inE;
        int rightPreOrderStart=leftPreOrderEnd+1;
        int rightPreOrderEnd=preE;

        TreeNode* root=new TreeNode(rootData);
        // call recursion for left and right subtree
        root->left=fun(pre,in,leftInOrderStart,leftInOrderEnd,leftPreOrderStart,leftPreOrderEnd);
        root->right=fun(pre,in,rightInOrderStart,rightInOrderEnd,rightPreOrderStart,rightPreOrderEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return fun(preorder,inorder,0,n-1,0,n-1);
    }
};