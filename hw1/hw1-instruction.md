# HW1

* Starting kit: https://repl.it/@engr120/engr120-fall2020-hw-start
* Complete `hw1.c`
* Submit `hw1.c` ONLY on Gradescope

## Testing on Repl.it

When you log in https://repl.it/@engr120/engr120-fall2020-hw-start , you are in
the folder above the `hw1` folder. To know which folder you are in, type `pwd`
in the console to the right. `pwd` means `print working directory`.

```
> pwd
/home/runner/engr120-fall2020-hw-start
```

To get into `hw1`, type `cd hw1`. `cd` stands for "change directory", `cd hw1`
means let's change current directory to `hw1`.

```
> cd hw1
```

To run the test, both the style check and tests, type `make`

```
> make
./checker hw1.c
./main


===Begin TESTING===

FAILED  add(0, 0) should be -1, your answer is 0
FAILED  add(3, 4) should be -1, your answer is 7
FAILED  add(-14, 4) should be -1, your answer is -10
FAILED  range_sum(1, 4) should be -1, your answer is 10
FAILED  range_sum(11, 16) should be -1, your answer is 81
FAILED  range_sum(4, 1) should be -1, your answer is 0
FAILED  range_sum(-4, -3) should be -1, your answer is -7
FAILED  square_sum(1, 1) should be -1, your answer is 1
FAILED  square_sum(1, 0) should be -1, your answer is 0
FAILED  square_sum(5, 8) should be -1, your answer is 174
FAILED  square_sum(-4, -2) should be -1, your answer is 29
FAILED  square_sum(-2, -4) should be -1, your answer is 0
FAILED  fare(3.2, 4.5) should be -1.000000, your answer is 19.400000
FAILED  fare(1.7, 2.2) should be -1.000000, your answer is 8.740000
FAILED  fare(0.5, 3.3) should be -1.000000, your answer is 6.650000
>
```
