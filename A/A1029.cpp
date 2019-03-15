/*
	1029 Median （25 分)
	Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

	Given two increasing sequences of integers, you are asked to find their median.

	Input Specification:
	Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (≤2×10
	​5
	​​ ) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

	Output Specification:
	For each test case you should output the median of the two given sequences in a line.

	Sample Input:
	4 11 12 13 14
	5 9 10 15 16 17
	Sample Output:
	13
*/

#include<cstdio>

int main(){
  int first_len,second_len,total,temp,first_local=0,count=0;
  scanf("%d",&first_len);
  int * first = new int[first_len];
  for(int i=0;i<first_len;i++){
    scanf("%d",&first[i]);
  } 
  scanf("%d",&second_len);
  total= first_len+second_len;
  for(int i=0;i<second_len;i++){
    scanf("%d",&temp);
    while(first_local<first_len&&first[first_local]<=temp){
      count++;
      if(count == (total+1)/2){
        printf("%d",first[first_local]);
        return 0;
      }
      first_local++;
    }
    count++;
    if(count == (total+1)/2){
      printf("%d",temp);
      return 0;
    }
  }
  while(first_local<first_len){
    count++;
    if(count == (total+1)/2){
      printf("%d",first[first_local]);
      return 0;
    }
    first_local++;
  }
}