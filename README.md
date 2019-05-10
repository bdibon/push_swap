# push_swap
This project aims to sort a `stack` A of integers, using an other `stack B` and the following set of operations :

- `sa` swaps two integers at the top of `stack A`
- `pa` takes the first element at the top of `stack B` and put it at the top of `stack A`
- `ra` takes the top element of `stack A` and put it at its bottom
- `rra` takes the bottom element of `stack A` and put it at its top

There are analog operations for `stack B`, i.e `sb`, `pb`, `rb` and `rrb`.
Plus operations to perform on both stacks :

- `ss` performs `sa` and `sb`
- `rr` performs `ra` and `rb`
- `rrr` performs `rra` and `rrb`

## HOWTO

### Compile
In the root folder run `make`, it will produce two executables **push_swap** and **checker**.

### Run the program
**push_swap** expects a list of distinct integers as arguments, it will represent `stack A`, then ouput the list of operations it performed to sort the stack.

**checker** expects a list of distinct integers as argumentsm it will respresent `stack A`, and read a list of operations on `stdin`, then check if these operations successfully sorted `stack A`.
