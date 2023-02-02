#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
bool printPath (Node* root, int sum)
{
    // base case
    if (sum == 0 && root == nullptr) {
        return true;
    }
 
    // base case
    if (root == nullptr) {
        return false;
    }
 
    bool left = printPath(root->left, sum - root->data);
    bool right = false;
        
    if (!left) {
        right = printPath(root->right, sum - root->data);
    }
 
    if (left || right) {
        cout << root->data << " ";
    }
 
    return left || right;
}
 
int getRootToLeafSum(Node* root)
{
    // base case: tree is empty
    if (root == nullptr) {
        return INT_MIN;
    }
 
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }
 
    int left = getRootToLeafSum(root->left);
 
    int right = getRootToLeafSum(root->right);
 
    return (left > right? left : right) + root->data;
}
 
void findMaxSumPath(Node* root)
{
    int sum = getRootToLeafSum(root);
    cout << "The Maximum sum is " << sum << endl;
    cout << "The Maximum sum path is ";
 
    printPath(root, sum);
}
 
int main()
{
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(8);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(10);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(9);
    root->right->right->right = new Node(5);
 
    findMaxSumPath(root);
 
    return 0;
}
