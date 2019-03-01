//1005 Spell It Right £¨20 ·Ö£©
//Given a non - negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.
//
//Input Specification :
//Each input file contains one test case.Each case occupies one line which contains an N(¡Ü10
//	100
//).
//
//Output Specification :
//For each test case, output in one line the digits of the sum in English words.There must be one space between two consecutive words, but no extra space at the end of a line.
//
//Sample Input :
//12345
//Sample Output :
//one five

#include<iostream>
#include<string>
using namespace std;

string mirror(int a) {
	switch (a) {
	case 0:
		return "zero";
	case 1:
		return "one";
	case 2:
		return "two";
	case 3:
		return "three";
	case 4:
		return "four";
	case 5:
		return "five";
	case 6:
		return "six";
	case 7:
		return "seven";
	case 8:
		return "eight";
	case 9:
		return "nine";
	}
}

int main() {
	string input, output="";
	cin >> input;
	int ans=0;
	for (auto i : input) {
		ans += int(i)-48;
	}
	if (ans == 0) {
		cout << "zero";
		return 0;
	}
	int radi = 1;
	while (ans / radi > 0) {
		if (output == "") {
			output = mirror(ans / radi % 10);
		}
		else {
			output = mirror(ans / radi % 10)+ " "+output;
		}
		radi *= 10;
	}
	cout << output;
	system("pause");
	return 0;
}