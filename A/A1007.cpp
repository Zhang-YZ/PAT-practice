/*
	1007 Maximum Subsequence Sum （25 分）
	Given a sequence of K integers{ N1  , N2  , ..., NK }.A continuous subsequence is defined to be{ Ni , Ni + 1 , ..., Nj} 
	where 1≤i≤j≤K.The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements.For example, given sequence{ -2, 11, -4, 13, -5, -2 }, its maximum subsequence is{ 11, -4, 13 } with the largest sum being 20.

	Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

	Input Specification :
	Each input file contains one test case.Each case occupies two lines.The first line contains a positive integer K(≤10000).The second line contains K numbers, separated by a space.

	Output Specification :
	For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence.The numbers must be separated by one space, but there must be no extra space at the end of a line.In case that the maximum subsequence is not unique, output the one with the smallest indices i and j(as shown by the sample case).If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

	Sample Input :
	10
	- 10 1 2 3 4 - 5 - 23 3 7 - 21
	Sample Output :
	10 1 4
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int number, temp;
	vector<int> sequence;
	cin >> number;
	int temp_max, total_max = 0, start_index = 0, end_index=number-1;
	for (int i = 0; i < number; i++) {
		cin >> temp;
		sequence.push_back(temp);
	}
	bool is_negative = true;
	for (int i = 0; i < number; i++) {
		if (sequence[i] < 0)
			continue;
		else {
			is_negative = false;
		}
		temp_max = 0;
		for (int j = i; j < number; j++) {
			temp_max += sequence[j];
			if (temp_max > total_max || (i==j && temp_max == 0 && total_max ==0)) {
				start_index = i;
				end_index = j;
				total_max = temp_max;
			}
		}
	}
	if (is_negative) {
		cout << 0 << " " << sequence[0] << " " << sequence[number - 1];
	}
	else {
		cout << total_max << " " << sequence[start_index] << " " << sequence[end_index];
	}
	system("pause");
	return 0;
}

/*
	来源：牛客网

	import java.util.Scanner;
	//乍看一下好像很难，暴力求解似乎要o(n^2),但是鉴于k的个数范围以及nowcoder对于时间的要求不用想也知道会超时。
	//仔细分析一下，一次遍历的话其实只有2种情况：
	//①前面的和<0，那么当前数作为start重新开始一个序列吧！
	//②前面的和>=0（由于求最小ij所以要带着等于号），
	//  那么就判断：加上新数字的新总和newsum是否>存储着的之前的某次最大总和maxsum？
	//    大于的话就把数据存储下来作为新的总和maxsum=newsum！
	//用这种方法能确保maxsum是最大的！
	//
	public class Main {

		public static void main(String[] args) {
			Scanner in = new Scanner(System.in);
			int n = in.nextInt();
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}
			int oldsum = a[0];    //前面所有数字的总和
			int start = 0;        //序列第一个数字
			int maxstart = 0;    //记录最大总和时候的开始数字
			int end = 0;            //序列最末数字（同时也是最大总和时候的最末数字）
			int newsum;        //包含当前数字的新总和
			int maxsum = Integer.MIN_VALUE;    //用来记录最大总和
			for (int i = 1; i < n; i++) {
				if (oldsum < 0) {
					start = a[i];    //当前数字作为序列第一个数啦
					oldsum = 0;    //所以之前的总和清0咯
				}
				newsum = oldsum + a[i];
				oldsum = newsum;      //下一次遍历时候的oldsum就是这次的newsum
				if (newsum > maxsum) {      //更新并存储下最大和时候的数据
					maxsum = newsum;
					end = a[i];
					maxstart = start;
				}
			}if (maxsum < 0) {
				System.out.println(0 + " " + a[0] + " " + a[n - 1]);
			}
			else
				System.out.println(maxsum + " " + maxstart + " " + end);
		}

	}
*/
