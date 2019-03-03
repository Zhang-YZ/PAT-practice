/*
	1009 Product of Polynomials （25 分）
	This time, you are supposed to find A×B where A and B are two polynomials.

	Input Specification:
	Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:
	K N​1​​  a​N​1​​​​  aN​2​​  a​N​2​​​​  ... N​K​​  a​N​K  where K is the number of nonzero terms in the polynomial, 
	N​i​​  and a​N​i​​​​  (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10, 0≤N​K​​ <⋯<N​2​​ <N​1​​ ≤1000.

	Output Specification:
	For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

	Sample Input:
	2 1 2.4 0 3.2
	2 2 1.5 1 0.5
	Sample Output:
	3 3 3.6 2 6.0 1 1.6
*/

#include<iostream>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;
typedef pair<int, double> item;

double trans(double a) {
	int b = 100 * a;
	if (b > 0) {
		if (b % 10 > 4) {
			b = b / 10 + 1;
		}
		else {
			b = b / 10;
		}
	}
	else {
		b = -1 * b;
		if (b % 10 > 5) {
			b = b / 10 + 1;
		}
		else {
			b = b / 10;
		}
		b = -1 * b;
	}
	return double(b) / 10;
}

int main() {
	vector<item>a_items, b_items;
	item temp_a, temp_b;
	int a_num, b_num, temp_int;
	double temp_double;
	map<int, double, greater<int>> ans;
	cin >> a_num;
	for (int i = 0; i < a_num; i++) {
		cin >> temp_int >> temp_double;
		a_items.push_back({ temp_int,temp_double });
	}
	cin >> b_num;
	for (int i = 0; i < b_num; i++) {
		cin >> temp_int >> temp_double;
		b_items.push_back({ temp_int,temp_double });
	}
	for (int i = 0; i < a_num; i++) {
		temp_a = a_items[i];
		for (int j = 0; j < b_num; j++) {
			temp_b = b_items[j];
			temp_int = temp_a.first + temp_b.first;
			temp_double = trans(temp_a.second*temp_b.second);
			if (temp_double == 0) {
				continue;
			}
			if (ans.find(temp_int) != ans.end()) {
				ans[temp_int] = ans[temp_int] + temp_double;

			}
			else {
				ans.insert({ temp_int,temp_double });
			}
		}
	}
	int size = ans.size();
	cout << size;
	for (auto i : ans) {
		cout << " " << i.first << " " << setiosflags(ios::fixed) << setprecision(1) << i.second;
	}
	return 0;
}
