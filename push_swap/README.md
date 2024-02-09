# Push swap

This project is about sorting algorithms.
My program calculates and displays on the standard output the smallest program that sorts the integers received as arguments, based on the push swap language instructions.

## The rules

You have 2 stacks named a and b.

• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

**ss**: sa and sb at the same time.

**pa** (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

**pb** (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

**ra** (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

**rb** (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

**rr** : ra and rb at the same time.

**rra** (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

**rrb** (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

**rrr** : rra and rrb at the same time.

## My approach

After looking into radix sort and other sorting algorithms, I finally decided to use the Turk algorithm, as described in this Medium [article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

I first started by parsing and validating the data, the sorting algorithms for small stacks, then implemented my own version of the Turk algorithm, adding some improvements.

My algorithms was highly effective as it used a very small amount of instructions, and got the maximum score, based on the number of instructions.

## Testing

./push_swap 2 1 3 6 5 8

sa
pb
pb
pb
sa
pa
pa
pa

./push_swap 0 one 2 3

Error

A binary is also provided for testing.

ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6

$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
