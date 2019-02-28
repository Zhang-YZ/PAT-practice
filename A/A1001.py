num = input().split()
a = -1 * int(num[0][1:]) if num[0][0] == "-" else int(num[0])
b = -1 * int(num[1][1:]) if num[1][0] == "-" else int(num[1])
ans = str(a+b)
final_ans = ""
while len(ans) > 3:
    final_ans = ","+ans[-3:]+final_ans
    ans = ans[:-3]
final_ans = ans + final_ans
if final_ans[0]=="-" and final_ans[1] == ",":
    final_ans = "-" + final_ans[2:]
print(final_ans)
