# push_swap

## Overview

Fast sorting algorithm using two stacks.

## Requirement

- bash
- python3.8 (If you want to use a tester)

## Usage

```
git clone ...
cd push_swap
make
```

After executing the above, two programs push_swap and checker will be created.
Then you can use it as follows.

```
# Push_swap with an array as an argument and let it output a sort command.
> ./push_swap 2 4 1 5 3
pb
sa
pb
rrr
pa
pa

# Then give the output to the checker to check if the answer is correct.
> ./checker 2 4 1 5 3
pb
sa
pb
rrr
pa
pa
ctrl+D
OK

# You can test it immediately by connecting push_swap and checker as follows.
> ARG="2 4 1 5 3"; ./push_swap $ARG | ./checker &ARG
OK

# Also, output the number of moves that were sorted as follows.
> ARG="2 4 1 5 3"; ./push_swap $ARG | wc -l
6
```

## Tester

There are four testers, which can be used for different purposes.

### test_all.py

Test for all possible patterns in an array of the length of the given values
and output the percentage of correct answers and the time taken.

```
> cd tester
> python3 test_all.py 5 ../push_swap ../checker
time: 4.975323599763215
time mean: 0.04146102999802679
time max: 0.9165209999773651
total: 120
KO_num: 0
Error_num: 0
```

### test_all_print.py

Test with all possible patterns in an array of the length of the given values,
and output all results and steps to text.txt

```
> cd tester
> python3 test_all_print.py 5 ../push_swap ../checker > text.txt
```

### test_random.py

Randomly test the second argument with an array of the length of the first argument's value.

```
> cd tester
> python3 test_random.py 5 10 ../push_swap ../checker
time: 0.28707949980162084
time mean: 0.028707949980162083
time max: 0.14814339997246861
total: 10
KO_num: 0
Error_num: 0
```

### test_random_print.py

Test for the second argument randomly with an array of the length of the first argument's value,
and output all results and steps to text.txt

```
> cd tester
> python3 test_random_print.py 5 10 ../push_swap ../checker > text.txt
```

## Description

This project will generate two programs.

1. push_swap: Output the procedure to sort the given array.
2. checker: Verify that the push_swap procedure is correct.

However, there are limitations on how the sorting is done.

1. Use two stacks and sort using a limited number of methods.
2. The arguments you give must not be duplicated.
3. Only INT_MIN to INT_MAX numbers are supported.
4. The length of the array is a realistic length.

The following 11 types of procedures can be used (the first stack with an array is a).

- sa: Swap the first two elements of a
- sb: Swap the first two elements of b
- ss: Do sa and sb at the same time
- pa: Transfer the first element of b as the first element of a
- pb: Transfer the first element of a as the first element of b
- ra: Bring the first element of a to the back of the line and advance the whole line by one
- rb: Bring the first element of b to the back of the line and advance the whole line by one
- rr: Do ra and rb at the same time
- rra: Bring the last element of a to the beginning and advance the whole thing back one.
- rrb: Bring the last element of b to the beginning and advance the whole thing back one.
- rrr: Do rra and rrb at the same time

The performance of this push_swap is as follows

- len 5 : max 8
- len 100: max 698, average 644 (2000 tests)
- len 500: max 4923, average 4781 (2000 tests)
- len 1000: max 11154, average 10999 (500 tests)
- len 10000: max 159663, average 159093 (100 tests)

## Sorting Algorithm

- <= 5 : Breadth-first search (bfs)
- \> 5 : Similar to quick sort (Please refer to the reference URL)

## Reference

- [syamashi's push_swap](https://note.com/syamashi/n/n602158ffc662)

## Author

[twitter](https://twitter.com/Kotabrog)

## Licence

[MIT](https://github.com/kotabrog/push_swap/blob/main/LICENSE)
