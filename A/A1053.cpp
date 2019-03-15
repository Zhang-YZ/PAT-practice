/*
	1053 Path of Equal Weight （30 分）
	Given a non-empty tree with root R, and with weight W​i​​  assigned to each tree node T​i​​ . The weight of a path from R to L is defined to be the sum of the weights of all the nodes along the path from R to any leaf node L.
	Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number. For example, let's consider the tree showed in the following figure: for each node, the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node. Suppose that the given number is 24, then there exists 4 different paths which have the same given weight: {10 5 2 7}, {10 4 10}, {10 3 3 6 2} and {10 3 3 6 2}, which correspond to the red edges in the figure.
	   
	Input Specification:
	Each input file contains one test case. Each case starts with a line containing 0<N≤100, the number of nodes in a tree, M (<N), the number of non-leaf nodes, and 0<S<2
	​30​​ , the given weight number. The next line contains N positive numbers where W​i​​  (<1000) corresponds to the tree node T​i​​ . Then M lines follow, each in the format:
	ID K ID[1] ID[2] ... ID[K]
	where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 00.

	Output Specification:
	For each test case, print all the paths with weight S in non-increasing order. Each path occupies a line with printed weights from the root to the leaf in order. All the numbers must be separated by a space with no extra space at the end of the line.
	Note: sequence {A1​​ ,A​2​ ,⋯,A​n} is said to be greater than sequence {B​1​​ ,B​2​​ ,⋯,B​m} if there exists 1≤k<min{n,m} such that A​i​​ =B​i​​  for i=1,⋯,k, and A​k+1​​ >B​k+1​​ .

	Sample Input:
	20 9 24
	10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
	00 4 01 02 03 04
	02 1 05
	04 2 06 07
	03 3 11 12 13
	06 1 09
	07 2 08 10
	16 1 15
	13 3 14 16 17
	17 2 18 19
	Sample Output:
	10 5 2 7
	10 4 10
	10 3 3 6 2
	10 3 3 6 2

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node;
Node** all_node;
int target;
vector<vector<int>> ans;

class Node {
public:
	int weight;
	bool is_leaf;
	int child_num;
	int* children;
	Node(int wei, bool leaf) {
		this->weight = wei;
		this->is_leaf = leaf;
	}
};

void traversal(vector<int> a, int temp_sum, int temp_root) {
	if (all_node[temp_root]->is_leaf) {
		if (temp_sum + all_node[temp_root]->weight == target) {
			a.push_back(all_node[temp_root]->weight);
			ans.push_back(a);
		}
		return;
	}
	int now_temp_sum = temp_sum + all_node[temp_root]->weight;
	if (now_temp_sum > target) {
		return;
	}
	vector<int> now_a = a;
	now_a.push_back(all_node[temp_root]->weight);
	for (int i = 0; i < all_node[temp_root]->child_num; i++) {
		traversal(now_a, now_temp_sum, all_node[temp_root]->children[i]);
	}
}

bool compare(vector<int> a, vector<int> b) {
	int a_length = a.size(), b_length = b.size();
	for (int i = 0; i < a_length&&i < b_length; i++) {
		if (a[i] > b[i]) {
			return true;
		}
		else if (a[i] == b[i]) {
			continue;
		}
		else {
			return false;
		}
	}
	return false;
}

int main() {
	int node_number, inner_number, temp, temp1;
	cin >> node_number >> inner_number >> target;
	all_node = new Node*[node_number];
	for (int i = 0; i < node_number; i++) {
		cin >> temp;
		all_node[i] = new Node(temp, true);
	}
	for (int i = 0; i < inner_number; i++) {
		cin >> temp >> temp1;
		all_node[temp]->is_leaf = false;
		all_node[temp]->child_num = temp1;
		all_node[temp]->children = new int[temp1];
		for (int j = 0; j < temp1; j++) {
			cin >> all_node[temp]->children[j];
		}
	}
	vector<int> begin;
	traversal(begin, 0, 0);
	sort(ans.begin(), ans.end(), compare);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j];
			if (j != ans[i].size() - 1) {
				cout << " ";
			}
		}
		if (i != ans.size() - 1) {
			cout << endl;
		}
	}
	system("pause");
}