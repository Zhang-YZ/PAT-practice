/*
	1066 Root of AVL Tree （25 分)
	An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.

	Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.
	Input Specification:
	Each input file contains one test case. For each case, the first line contains a positive integer N (≤20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

	Output Specification:
	For each test case, print the root of the resulting AVL tree in one line.

	Sample Input 1:
	5
	88 70 61 96 120
	Sample Output 1:
	70
	Sample Input 2:
	7
	88 70 61 96 120 90 65
	Sample Output 2:
88
*/

#include<iostream>
using namespace std;

struct Node {
	int value;
	int height;
	Node * left_child;
	Node * right_child;
};

class AVL_Tree {
private:
	Node * root;
	int get_height(Node * temp_root);
	int judge(Node * temp_root);
	Node * roate(Node * temp_root);
public:
	AVL_Tree(int root_value) {
		this->root = new Node();
		root->height = 1;
		root->value = root_value;
		root->left_child = nullptr;
		root->right_child = nullptr;
	}
	Node * insert(Node * temp_root, int num);
	int get_root() {
		return root->value;
	}
	void walk(Node * temp_root);
};

void AVL_Tree::walk(Node * temp_root) {
	if (!temp_root) {
		temp_root = this->root;
	}
	if (temp_root->left_child) {
		walk(temp_root->left_child);
	}
	cout << temp_root->value << "   height:" << temp_root->height << endl;
	if (temp_root->right_child) {
		walk(temp_root->right_child);
	}
}

int AVL_Tree::get_height(Node * temp_root) {
	if (!temp_root->left_child) {
		if (!temp_root->right_child) {
			return 1;
		}
		return temp_root->right_child->height+1;
	}
	else if (!temp_root->right_child) {
		return temp_root->left_child->height+1;
	}
	else {
		int left = temp_root->left_child->height;
		int right = temp_root->right_child->height;
		return left > right ? left+1 : right+1;
	}
}

int AVL_Tree::judge(Node * temp_root) {
	if (!temp_root->left_child) {
		return -1 * temp_root->right_child->height;
	}
	else if (!temp_root->right_child) {
		return temp_root->left_child->height;
	}
	else {
		return temp_root->left_child->height - temp_root->right_child->height;
	}
}

Node * AVL_Tree::roate(Node * temp_root) {
	int a = judge(temp_root);
	Node * old_temp_root;
	if (a > 0) {
		old_temp_root = temp_root->left_child;
		if (!old_temp_root->right_child) {
			temp_root->left_child = nullptr;
		}
		else {
			temp_root->left_child = old_temp_root->right_child;
		}
		old_temp_root->right_child = temp_root;
	}
	else {
		old_temp_root = temp_root->right_child;
		if (!old_temp_root->left_child) {
			temp_root->right_child = nullptr;
		}
		else {
			temp_root->right_child = old_temp_root->left_child;
		}
		old_temp_root->left_child = temp_root;
	}
	temp_root->height = get_height(temp_root);
	old_temp_root->height = get_height(old_temp_root);
	return old_temp_root;
}

Node * AVL_Tree::insert(Node * temp_root, int num) {
	if (!temp_root) {
		temp_root = this->root;
	}
	if (temp_root->value >= num) {
		if (!temp_root->left_child) {
			Node * new_node = new Node();
			new_node->height = 1;
			new_node->value = num;
			new_node->left_child = nullptr;
			new_node->right_child = nullptr;
			temp_root->left_child = new_node;
			temp_root->height = get_height(temp_root);
		}
		else {
			temp_root->left_child = insert(temp_root->left_child, num);
			temp_root->height = get_height(temp_root);
		}
	}
	else {
		if (!temp_root->right_child) {
			Node * new_node = new Node();
			new_node->height = 1;
			new_node->value = num;
			new_node->left_child = nullptr;
			new_node->right_child = nullptr;
			temp_root->right_child = new_node;
			temp_root->height = get_height(temp_root);
		}
		else {
			temp_root->right_child = insert(temp_root->right_child, num);
			temp_root->height = get_height(temp_root);
		}
	}
 	int flag = judge(temp_root);
	if (flag == 2) {
		if (!temp_root->left_child->right_child);
		else if (!temp_root->left_child->left_child) {
			temp_root->left_child = roate(temp_root->left_child);
		}
		else if (temp_root->left_child->left_child->height < temp_root->left_child->right_child->height) {
			temp_root->left_child = roate(temp_root->left_child);
		}
		if (temp_root == this->root) {
			this->root = roate(temp_root);
			return nullptr;
		}
		return roate(temp_root);
	}
	else if (flag == -2) {
		if (!temp_root->right_child->left_child);
		else if (!temp_root->right_child->right_child) {
			temp_root->right_child = roate(temp_root->right_child);
		}
		else if (temp_root->right_child->left_child->height > temp_root->right_child->right_child->height) {
			temp_root->right_child = roate(temp_root->right_child);
		}
		if (temp_root == this->root) {
			this->root = roate(temp_root);
			return nullptr;
		}
		return roate(temp_root);
	}
	else {
		return temp_root;
	}
}

int main() {
	int node_number;
	cin >> node_number;
	int now;
	cin >> now;
	AVL_Tree mytree(now);
	for (int i = 1; i < node_number; i++) {
		cin >> now;
		mytree.insert(nullptr, now);
		/*mytree.walk(nullptr);
		cout << endl;*/
	}
	cout << mytree.get_root();
}