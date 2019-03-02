/*
	1043 Is It a Binary Search Tree （25 分）
	A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

	The left subtree of a node contains only nodes with keys less than the node's key.
	The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
	Both the left and right subtrees must also be binary search trees.
	If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.

	Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.

	Input Specification:
	Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.

	Output Specification:
	For each test case, first print in a line YES if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or NO if not. Then if the answer is YES, print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

	Sample Input 1:
	7
	8 6 5 7 10 8 11
	Sample Output 1:
	YES
	5 7 6 8 11 10 8
	Sample Input 2:
	7
	8 10 11 8 6 7 5
	Sample Output 2:
	YES
	11 8 10 7 5 6 8
	Sample Input 3:
	7
	8 6 8 5 10 9 11
	Sample Output 3:
	NO
*/
#include<iostream>
#include<vector>
using namespace std;
bool flag = true;

class Node {
public:
	int value;
	Node* left, *right;
	Node(int n) {
		this->value = n;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class Tree {
	Node * root;
	Node * in_insert(Node* temp_root,int num);
	void in_pre_traversal(Node* temp_root, vector<int>& pre);
	void in_post_traversal(Node* temp_root, vector<int>& post);
public:
	Tree() { this->root = nullptr; };
	void insert(int num) { this->root = in_insert(this->root, num); };
	void pre_traversal(vector<int>& pre) { in_pre_traversal(this->root, pre); };
	void post_traversal(vector<int>& post) { in_post_traversal(this->root, post); };
};

Node* Tree::in_insert(Node* temp_root, int num) {
	if (!temp_root) {
		temp_root = new Node(num);
		return temp_root;
	}
	if (num < temp_root->value) {
		temp_root->left = in_insert(temp_root->left, num);
	}
	else {
		temp_root->right = in_insert(temp_root->right, num);
	}
	return temp_root;
}

void Tree::in_pre_traversal(Node* temp_root, vector<int>& pre) {
	if (!temp_root) {
		return;
	}
	else {
		pre.push_back(temp_root->value);
		if (flag) {
			in_pre_traversal(temp_root->left, pre);
			in_pre_traversal(temp_root->right, pre);
		}
		else {
			in_pre_traversal(temp_root->right, pre);
			in_pre_traversal(temp_root->left, pre);
		}
	}
}

void Tree::in_post_traversal(Node* temp_root, vector<int>& post) {
	if (!temp_root) {
		return;
	}
	else {
		if (flag) {
			in_post_traversal(temp_root->left, post);
			in_post_traversal(temp_root->right, post);
		}
		else {
			in_post_traversal(temp_root->right, post);
			in_post_traversal(temp_root->left, post);
		}
		post.push_back(temp_root->value);
	}
}

int main() {
	int node_num, one_node;
	cin >> node_num;
	vector<int> given_pre_node, act_pre_node, post_node;
	for (int i = 0; i < node_num; i++) {
		cin >> one_node;
		given_pre_node.push_back(one_node);
	}
	if (node_num > 1) {
		if (given_pre_node[0] <= given_pre_node[1]) {
			flag = false;
		}
	}
	Tree mytree;
	for (int i = 0; i < node_num; i++) {
		mytree.insert(given_pre_node[i]);
	}
	mytree.pre_traversal(act_pre_node);
	for (int i = 0; i < node_num; i++) {
		if (act_pre_node[i] != given_pre_node[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES" << endl;
	mytree.post_traversal(post_node);
	for (int i = 0; i < node_num; i++) {
		cout << post_node[i];
		if (i != node_num - 1) {
			cout << " ";
		}
	}
	system("pause");
	return 0;
}