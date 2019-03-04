/*
	1049 Counting Ones （30 分）
	The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

	Input Specification:
	Each input file contains one test case which gives the positive N (≤2
	​30
	​​ ).

	Output Specification:
	For each test case, print the number of 1's in one line.

	Sample Input:
	12
	Sample Output:
	5
*/

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main() {
	string number;
	cin >> number;
	int length = number.length(), ans=0, count = 0;
	int now_num, old_number = 0, temp;
	for (int i = 0; i < length; i++) {
		temp = pow(10, i);
		now_num = int(number[length - i - 1]) - 48;
		if (now_num == 1) {
			ans += count + old_number + 1;
		}
		if (now_num > 1 && now_num < 10) {
			ans += count * (now_num)+pow(10, i);
		}
		old_number += now_num * pow(10, i);
		count = count * 10 + pow(10, i);
	}
	cout << ans;
	system("pause");
}
