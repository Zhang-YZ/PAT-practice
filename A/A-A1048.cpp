/*
	1048 Find Coins （25 分）
	Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 10^
	​5​​  coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.

	Input Specification:
	Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (≤10​^5​​ , the total number of coins) and M (≤10^​3​​ , the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.

	Output Specification:
	For each test case, print in one line the two face values V​1​​  and V​2​​  (separated by a space) such that V​1​​ +V​2​​ =M and V​1​​ ≤V​2​​ . If such a solution is not unique, output the one with the smallest V​1​​ . If there is no solution, output No Solution instead.

	Sample Input 1:
	8 15
	1 2 8 7 2 4 11 15
	Sample Output 1:
	4 11
	Sample Input 2:
	7 14
	1 8 7 2 4 11 15
	Sample Output 2:
	No Solution
*/

//没有使用sort前会有超时

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	vector<int> coins;
//	int number, value, temp, ans1, ans2;
//	bool flag = true;
//	cin >> number >> value;
//	ans1 = value;
//	ans2 = value;
//	for (int i = 0; i < number; i++) {
//		cin >> temp;
//		coins.push_back(temp);
//	}
//	sort(coins.begin(), coins.end());
//	for (int i = 0; i < number; i++) {
//		if (coins[i] >= value) {
//			break;
//		}
//		if (i > 0 && coins[i] == coins[i - 1]) {
//			continue;
//		}
//		for (int j = i + 1; j < number; j++) {
//			if (coins[i] + coins[j] == value) {
//				if (ans1 < coins[i] && ans1 < coins[j]) {
//					continue;
//				}
//				if (coins[i] <= coins[j]) {
//					ans1 = coins[i];
//					ans2 = coins[j];
//				}
//				else {
//					ans1 = coins[j];
//					ans2 = coins[i];
//				}
//				flag = false;
//			}
//		}
//	}
//	if (flag) {
//		cout << "No Solution";
//		return 0;
//	}
//	cout << ans1 << " " << ans2;
//	return 0;
//}


//双指针解决问题
#include<cstdio>
#include<algorithm>

int main() {
	int number, value, temp;
	scanf("%d%d", &number,&value);
	if (number == 1) {
		printf("No Solution");
		return 0;
	}
	int * arr = new int[number];
	int ans1 = 0, ans2 = number - 1;
	for (int i = 0; i < number; i++) {
		scanf("%d", &arr[i]);
	}
	std::sort(arr, arr + number);
	temp = arr[ans1] + arr[ans2];
	while (value != temp) {
		if (value < temp) {
			ans2--;
		}
		else {
			ans1++;
		}
		if (ans2 == ans1) {
			break;
		}
		temp = arr[ans1] + arr[ans2];
	}
	if (value == temp) {
		printf("%d %d", arr[ans1], arr[ans2]);
	}
	else {
		printf("No Solution");
	}
	scanf("%d", &temp);
	return 0;
}
