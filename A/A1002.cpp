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
				//忘记考虑0的情况
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
		//注意格式化输出
		all_info.pop();
	}
	system("pause");
}