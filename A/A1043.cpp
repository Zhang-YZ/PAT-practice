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