//1004 Counting Leaves £¨30 ·Ö£©
//A family hierarchy is usually presented by a pedigree tree.Your job is to count those family members who have no child.
//
//Input Specification :
//Each input file contains one test case.Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M(< N), the number of non - leaf nodes.Then M lines follow, each in the format :
//
//ID K ID[1] ID[2] ... ID[K]
//	where ID is a two - digit number representing a given non - leaf node, K is the number of its children, followed by a sequence of two - digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
//
//		The input ends with N being 0. That case must NOT be processed.
//
//		Output Specification :
//	For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root.The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
//
//		The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child.Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node.Then we should output 0 1 in a line.
//
//		Sample Input :
//	2 1
//		01 1 02
//		Sample Output :
//	0 1
#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int index;
	vector<int> child;
	bool is_leaf;
	Node(int n,bool m):index(n),is_leaf(m){}
};

vector<Node *> all_node;
vector<int> ans;

void walk(int root, int height) {
	if (ans.size() < height) {
		ans.push_back(0);
	}
	if (all_node[root - 1]->is_leaf) {
		ans[height - 1]++;
		return;
	}
	for (int i = 0; i < all_node[root - 1]->child.size();i++) {
		walk(all_node[root - 1]->child[i], height + 1);
	} 
}

int main() {
	int node_num, non_leaf_num;
	int node_index, child_num, one_child;
	cin >> node_num >> non_leaf_num;
	for (int i = 1; i <= node_num; i++) {
		Node * node = new Node(i,true);
		all_node.push_back(node);
	}
	for (int i = 0; i < non_leaf_num; i++) {
		cin >> node_index >> child_num;
		all_node[node_index - 1]->is_leaf = false;
		for (int j = 0; j < child_num; j++) {
			cin >> one_child;
			all_node[node_index - 1]->child.push_back(one_child);
		}
	}
	walk(1, 1);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size()-1) {
			cout << " ";
		}
	}
	system("pause");
}