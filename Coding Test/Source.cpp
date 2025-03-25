#include <iostream>

using namespace std;

struct Node
{
	char data;
	Node* left;
	Node* right;

	Node(char parent)
	{
		data = parent;
		left = right = nullptr;
	}
};

void insert(Node*& root, char parent, char left, char right)
{
	if (root == nullptr) {
		root = new Node(parent);
	}

	if (root->data == parent) {
		if (left != '.') root->left = new Node(left);
		if (right != '.') root->right = new Node(right);
	}
	else {
		if (root->left) insert(root->left, parent, left, right);
		if (root->right) insert(root->right, parent, left, right);
	}
}

void preorder(Node* root) {
	if (root) {
		cout << root->data;
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {
	Node* root = nullptr;

	int N;
	cin >> N;

	char parent, left, right;

	for (int i = 0; i < N; i++) {
		cin >> parent >> left >> right;
		insert(root, parent, left, right);
	}
}