/*
	1007 Maximum Subsequence Sum ��25 �֣�
	Given a sequence of K integers{ N1  , N2  , ..., NK }.A continuous subsequence is defined to be{ Ni , Ni + 1 , ..., Nj} 
	where 1��i��j��K.The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements.For example, given sequence{ -2, 11, -4, 13, -5, -2 }, its maximum subsequence is{ 11, -4, 13 } with the largest sum being 20.

	Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

	Input Specification :
	Each input file contains one test case.Each case occupies two lines.The first line contains a positive integer K(��10000).The second line contains K numbers, separated by a space.

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
	��Դ��ţ����

	import java.util.Scanner;
	//է��һ�º�����ѣ���������ƺ�Ҫo(n^2),���Ǽ���k�ĸ�����Χ�Լ�nowcoder����ʱ���Ҫ������Ҳ֪���ᳬʱ��
	//��ϸ����һ�£�һ�α����Ļ���ʵֻ��2�������
	//��ǰ��ĺ�<0����ô��ǰ����Ϊstart���¿�ʼһ�����аɣ�
	//��ǰ��ĺ�>=0����������Сij����Ҫ���ŵ��ںţ���
	//  ��ô���жϣ����������ֵ����ܺ�newsum�Ƿ�>�洢�ŵ�֮ǰ��ĳ������ܺ�maxsum��
	//    ���ڵĻ��Ͱ����ݴ洢������Ϊ�µ��ܺ�maxsum=newsum��
	//�����ַ�����ȷ��maxsum�����ģ�
	//
	public class Main {

		public static void main(String[] args) {
			Scanner in = new Scanner(System.in);
			int n = in.nextInt();
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}
			int oldsum = a[0];    //ǰ���������ֵ��ܺ�
			int start = 0;        //���е�һ������
			int maxstart = 0;    //��¼����ܺ�ʱ��Ŀ�ʼ����
			int end = 0;            //������ĩ���֣�ͬʱҲ������ܺ�ʱ�����ĩ���֣�
			int newsum;        //������ǰ���ֵ����ܺ�
			int maxsum = Integer.MIN_VALUE;    //������¼����ܺ�
			for (int i = 1; i < n; i++) {
				if (oldsum < 0) {
					start = a[i];    //��ǰ������Ϊ���е�һ������
					oldsum = 0;    //����֮ǰ���ܺ���0��
				}
				newsum = oldsum + a[i];
				oldsum = newsum;      //��һ�α���ʱ���oldsum������ε�newsum
				if (newsum > maxsum) {      //���²��洢������ʱ�������
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
