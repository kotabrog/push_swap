import subprocess
import itertools
import sys
import time

# 引数１: 配列の長さ
# 引数２：push_swapのパス
# 引数３：checkerのパス

args = sys.argv

num = int(args[1])
push_swap = args[2]
checker = args[3]

arg_list = []
result_list = []
command_list = []
time_list = []

choice_list = [i + 1 for i in range(num)]
check_list = itertools.permutations(choice_list, num)
for x in check_list:
	arg = " ".join(map(str, x))
	run_str = "{1} {0} | {2} {0}".format(arg, push_swap, checker)
	command_run_str = "{1} {0}".format(arg, push_swap)
	start_time = time.perf_counter()
	output = subprocess.run(run_str, shell=True, check=False, stderr=subprocess.STDOUT, stdout=subprocess.PIPE).stdout.decode()
	time_list.append(time.perf_counter() - start_time)
	result_list.append(output[:-1])
	arg_list.append(arg)
	output = subprocess.run(command_run_str, shell=True, check=False, stderr=subprocess.STDOUT, stdout=subprocess.PIPE).stdout.decode()
	command_list.append(output.split('\n')[:-1])

max_list = 0
for n_list, result, command, time in zip(arg_list, result_list, command_list, time_list):
	print(result)
	print("time:", time)
	print(n_list)
	print(command)
	max_list = max(max_list, len(command))
print('\nmax_len:', max_list)
