// 1002 A+B for Polynomials （25 分）
// This time, you are supposed to find A+B where A and B are two polynomials.

// Input Specification:
// Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

// K N​1​​  a​N​1​​  N​2​  a​N​2​​  ... N​K​​  a​N​K​​ where K is the number of nonzero terms in the polynomial, 
// N​i​​  and a​N​i​​ ​​  (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10，0≤N​K​​ <⋯<N​2​​ <N​1​​ ≤1000.

// Output Specification:
// For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

// Sample Input:
// 2 1 2.4 0 3.2
// 2 2 1.5 1 0.5
// Sample Output:
// 3 2 1.5 1 2.9 0 3.2

#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int a_num, b_num;
	queue<pair<int, double>> a_info, b_info, all_info;
	pair<int, double> temp;
	int index;
	double value;
	double temp_second;
	cin >> a_num;
	for (int i = 0; i < a_num; i++) {
		cin >> index >> value;
		a_info.push({ index,value });
	}
	cin >> b_num;
	for (int i = 0; i < b_num; i++) {
		cin >> index >> value;
		b_info.push({ index,value });
	}
	while (true) {
		if (a_info.size() == 0) {
			if (b_info.size() == 0)
				break;
			else {
				all_info.push(b_info.front());
				b_info.pop();
			}
		}
		else if (b_info.size() == 0) {
			all_info.push(a_info.front());
			a_info.pop();
		}
		else {
			if (a_info.front().first > b_info.front().first) {
				all_info.push(a_info.front());
				a_info.pop();
			}
			else if (a_info.front().first < b_info.front().first) {
				all_info.push(b_info.front());
				b_info.pop();
			}
			else {
				temp_second = a_info.front().second + b_info.front().second;
				//���ǿ���0�����
				if (temp_second != 0) {
					temp = { a_info.front().first,temp_second };
					all_info.push(temp);
				}
				a_info.pop();
				b_info.pop();
			}
		}
	}
	int size = all_info.size();
	cout << size;
	for (int i = 0; i <size; i++) {
		cout << " " << all_info.front().first << " " << setiosflags(ios::fixed)<<setprecision(1) << all_info.front().second;
		//ע���ʽ�����
		all_info.pop();
	}
	system("pause");
}