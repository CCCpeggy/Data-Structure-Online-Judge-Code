# 1345: 108資料結構作業 - Dynamic Hashing

* Time Limit: 1 Sec
* Memory Limit: 128 MB

## Description

``` text

Design a dynamic hash table that uses a directory.

To be specific, your design should include these commands.

*  put key: Insert a key into the hash table and print the index of directory of the hash table. If the bucket is full, you must resize the hash table and new directory size is twice the old directory size.

*  get index: Print a set of the bucket. If the bucket is empty, you must print “The bucket is empty.” If the index is out of range, you must print “Out of range”.

*  exit: Exit the program.

 

Note :

*  The size of directory depends on the number of bits of h(k, p) used to index into the directory. For example, when h(k, 2) is used, the directory size is .

*  Default p is 2.

*  Every bucket size is 2.

*  Every key is composed of two characters. First character is only from A to D. Second character is only from 0 to 7.

*  The hash function h(k) will transform keys into the 6-bit non-negative integer and we use h(k, p) to denote the integer formed by the p least significant bits of h(k). For example, h(A0, 1) = 0, h(A1, 3) = 1, h(B1, 4) = 1001 = 9, and h(C1, 6) = 110001 = 49.
```

Table 1 example of h(k)
|k|h(k)|
|:---:|:---:|
|A0|100 000|
|B1|101 001|
|C3|110 011|
|D7|111 111|

## Input

``` text
See the Sample Input.
```

## Output

``` text
See the Sample Output.
```

## Sample Input

``` text
put A0
put B0
get 0
get 1
get 5
put C0
get 0
get 4
get 8
put A1
put B1
put C2
put C3
get 9
put C1
exit
```

## Sample Output

``` text
0
0
A0 B0
The bucket is empty.
Out of range.
0
A0 C0
A0 B0
B0
1
9
2
3
B1
1
```
