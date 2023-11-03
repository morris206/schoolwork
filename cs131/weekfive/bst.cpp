#include <iostream>

using namespace std;

struct BSTNode {
	int data;
	BSTNode* right;
	BSTNode* left;
};

BSTNode* NewNode(int data)
{
	BSTNode* new_node = new BSTNode();
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

void Insert(BSTNode** root, int data) {
	if (*root == NULL) {
		*root = NewNode(data);
		cout << "Inserted " << data << endl;
	} else if (data <= (*root)->data) {
		Insert(&(*root)->left, data);
	} else {
		Insert(&(*root)->right, data);
	}
	
}
	
void DeleteNode(BSTNode* root)
{
	if(root == NULL) {
		return;
	}

	DeleteNode(root->left);
	DeleteNode(root->right);
	
	cout << "Deleted " << root->data << endl;
	
	delete root;
}

int main() 
{
	BSTNode* root = NULL;
	Insert(&root, 15);
	Insert(&root, 10);
	Insert(&root, 20);

	cout << "Deleting each node : " << endl;
	DeleteNode(root);
}

