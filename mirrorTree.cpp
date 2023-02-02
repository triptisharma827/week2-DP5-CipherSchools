#include <iostream>
using namespace std;

typedef struct treenode {
	int val;
	struct treenode* left;
	struct treenode* right;
} node;


node* createNode(int val)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


void inorder(node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout <<" "<< root->val;
	inorder(root->right);
}


void doMirror(node* root, node** mirror)
{
	if (root == NULL) {
		mirror = NULL;
		return;
	}

	*mirror = createNode(root->val);
	doMirror(root->left, &((*mirror)->right));
	doMirror(root->right, &((*mirror)->left));
}


int main()
{

	node* tree = createNode(5);
	tree->left = createNode(3);
	tree->right = createNode(6);
	tree->left->left = createNode(2);
	tree->left->right = createNode(4);

	cout <<"original tree: "<<endl;
	inorder(tree);
	node* mirror = NULL;
	doMirror(tree, &mirror);

	
	cout <<"mirror tree: ";
	inorder(mirror);

	return 0;
}


