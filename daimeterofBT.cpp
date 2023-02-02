#include<bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int h1 = height(root->left);
        int h2 = height(root->right);
        int ans = max(h1,h2)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int d1 = diameterOfBinaryTree(root->left);
        int d2 = diameterOfBinaryTree(root->right);
        int d3 = height(root->left) + height(root->right);
        int ans = max(d1,max(d2,d3));
        return ans;
    }
};


class Solution {
public:
    pair<int,int> findDiameter(TreeNode* root){
        if(root == NULL){
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        pair<int,int> left = findDiameter(root->left);
        pair<int,int> right = findDiameter(root->right);
        int d1 = left.first;
        int d2 = right.first;
        int d3 = left.second + right.second;
        pair<int,int> ans;
        ans.first = max(d1,max(d2,d3));
        ans.second = max(left.second,right.second)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> p = findDiameter(root);
        return p.first;
    }
};