/*
	1020 Tree Traversals （25 分)
	Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

	Input Specification:
	Each input file contains one test case. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

	Output Specification:
	For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

	Sample Input:
	7
	2 3 1 5 7 6 4
	1 2 3 4 5 6 7
	Sample Output:
	4 1 6 3 5 7 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> Node;
vector<Node> tree;
vector<int> post_order;
vector<int> in_order;


int find(vector<int> &a, int b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b) {
			return i;
		}
	}
	return -1;
}

bool compare(Node a,Node b) {
	return a.first < b.first;
}

void insert(int location, int post_begin, int post_end, int in_begin, int in_end) {
	int temp_root_value = post_order[post_end];
	Node temp_root(location, temp_root_value);
	tree.push_back(temp_root);
	int middle = find(in_order, temp_root_value);
	int left_len = middle - in_begin;
	int right_len = in_end - middle;
	if (left_len) {
		insert(2 * location + 1, post_begin, post_begin+left_len-1,in_begin, middle - 1);
	}
	if (right_len) {
		insert(2 * location + 2, post_begin+left_len, post_end-1, middle + 1,in_end);
	}
}


int main() {
	int node_num;
	cin >> node_num;
	int temp;
	for (int i = 0; i < node_num; i++) {
		cin >> temp;
		post_order.push_back(temp);
	}
	for (int i = 0; i < node_num; i++) {
		cin >> temp;
		in_order.push_back(temp);
	}
	insert(0, 0, node_num - 1, 0, node_num - 1);
	sort(tree.begin(), tree.end(), compare);
	for (int i = 0; i < node_num; i++) {
		cout << tree[i].second;
		if (i != node_num - 1) {
			cout << " ";
		}
	}
}