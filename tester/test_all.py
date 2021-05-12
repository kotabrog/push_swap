import subprocess
import itertools
import sys
import time

# 引数１:配列の長さ
# 引数２：push_swapのパス
# 引数３：checkerのパス

args = sys.argv

num = int(args[1])
push_swap = args[2]
checker = args[3]

choice_list = [i + 1 for i in range(num)]
check_list = itertools.permutations(choice_list, num)
total_num = 0
KO_num = 0
KO_list = []
Error_num = 0
Error_list = []
time_list = []
for x in check_list:
	arg = " ".join(map(str, x))
	run_str = "{1} {0} | {2} {0}".format(arg, push_swap, checker)
	start_time = time.perf_counter()
	output = subprocess.run(run_str, shell=True, check=False, stderr=subprocess.STDOUT, stdout=subprocess.PIPE).stdout.decode()
	time_list.append(time.perf_counter() - start_time)
	if output == "KO\n":
		KO_num += 1
		KO_list.append(x)
	elif output != "OK\n":
		Error_num += 1
		Error_list.append(x)
	total_num += 1

print("time:", sum(time_list))
print("time mean:", sum(time_list) / total_num)
print("time max:", max(time_list))
print('total:', total_num)
print('KO_num:', KO_num)
if KO_num:
	print(KO_list)
print('Error_num:', Error_num)
if Error_num:
	print(Error_list)
