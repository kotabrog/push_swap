import subprocess
import itertools
import sys
import time
import random

# 引数１:配列の長さ
# 引数２:実行するテストの数
# 引数３：push_swapのパス
# 引数４：checkerのパス

args = sys.argv

num = int(args[1])
rundom_num = int(args[2])
push_swap = args[3]
checker = args[4]

arg_list = []
result_list = []
command_list = []
time_list = []

choice_list = [i + 1 for i in range(num)]
check_list = [random.sample(range(-100000, 100000), num) for _ in range(rundom_num)]
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
mean_list = 0
for n_list, result, command, time in zip(arg_list, result_list, command_list, time_list):
	print(result)
	print('result:', len(command))
	print("time:", time)
	print(n_list)
	print(command)
	max_list = max(max_list, len(command))
	mean_list += len(command)
print('\nmax_len:', max_list)
print('avg_len:', mean_list / rundom_num)
