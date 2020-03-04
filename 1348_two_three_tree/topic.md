# 1348: 108資料結構作業 - Two Three Tree

* Time Limit: 1 Sec
* Memory Limit: 128 MB

## Description

``` markdown
Develop the C++ class TwoThreeTree, which implements a 2-3 tree. You must include function to search, insert and delete.
```

## Input

``` markdown
Input some command.
Input command :

1. insert <number> : Insert number to tree.
2. print : Print tree.
**P.S. all number bigger than 0.**
```

Print Example :  

``` dot
digraph{
    "5 9" -> {"2 4", 6, 10}
}
```

``` markdown
5 9
2 4 / 6 / 10
```

## Output

``` markdown
See the Sample Output.
```

## Sample Input

``` markdown
insert 50
insert 60
insert 70
print
insert 40
insert 30
print
insert 20
insert 10
print
insert 80
insert 90
print
insert 100
print
```

## Sample Output

``` markdown
60
50 / 70
40 60
30 / 50 / 70
40
20 / 60
10 / 30 / 50 / 70
40
20 / 60 80
10 / 30 / 50 / 70 / 90
40
20 / 60 80
10 / 30 / 50 / 70 / 90 100
```
