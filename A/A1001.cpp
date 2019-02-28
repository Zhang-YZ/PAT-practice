#include <iostream>
#include <string>
using namespace std;

int main(){
  long a, b;
  cin>>a>>b;
  string ans = to_string(a+b);
  string final_ans = "";
  int length = ans.length();
  for(int i = 1;i<=length;i++){
    final_ans = ans[length-i]+final_ans;
    if(i%3 == 0 && i !=length){
      final_ans = ","+final_ans;
    }
  }
  cout<<final_ans;
  return 0;
}