#include<iostream>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;
typedef pair<int, double> item;


int main() {
	vector<item>a_items, b_items;
	item temp_a, temp_b;
	int a_num, b_num, temp_int;
	double temp_double;
	map<int, double,greater<int>> ans;
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
			temp_int = temp_a.first+temp_b.first;
			temp_double = temp_a.second*temp_b.second;
			if (temp_double == 0) {
				continue;
			}
			if (ans.find(temp_int)!=ans.end()) {
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
		cout << " "<<i.first << " " <<setiosflags(ios::fixed)<<setprecision(1)<< i.second;
	}
	system("pause");
	return 0;
}