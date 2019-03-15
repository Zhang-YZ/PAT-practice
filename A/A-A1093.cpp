/*
	1093 Count PAT's （25 分)
	The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.

	Now given any string, you are supposed to tell the number of PAT's contained in the string.

	Input Specification:
	Each input file contains one test case. For each case, there is only one line giving a string of no more than 10
	​5
	​​  characters containing only P, A, or T.

	Output Specification:
	For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.

	Sample Input:
	APPAPT
	Sample Output:
	2
*/

#include<iostream>
using namespace std;
int main() {
	int count1 = 0, count2 = 0, ans = 0;
	char ch = cin.get();
	while (ch != '\n') {
		switch (ch) {
		case 'P':
			count2 = (count2 + 1) % 1000000007;
			break;
		case 'A':
			count1 = (count1 + count2) % 1000000007;
			break;
		case 'T':
			ans = (count1 + ans) % 1000000007;
			break;
		}
		ch = cin.get();
	}
	cout << ans;
}