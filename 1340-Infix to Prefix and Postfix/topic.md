# 1340: 108資料結構作業 - Infix to Prefix and Postfix

* Time Limit: 1 Sec
* Memory Limit: 128 MB
* Submit: 194
* Solved: 13

## Description

```content
Try to transform an infix expression into its prefix and postfix equivalent with C++. Assume that the operators in the expression only include (, ), *, /, +, and -. Design a class called Stack and implement the necessary member functions, such as push() and pop() to accomplish the infix transformation.
```

## Input

```content
An infix expression such as A*B/C.
```

# Output

```content
The corresponding prefix and postfix expressions of the input infix. See the sample input and output below.
```

## Sample Input

```content
A*B/C
A/B-C+D*E-A*C
A*(B+C)/D-G
A/(B-C*D)
```

## Sample Output

```content
Postfix: AB*C/
Prefix: /*ABC

Postfix: AB/C-DE*+AC*-
Prefix: -+-/ABC*DE*AC

Postfix: ABC+*D/G-
Prefix: -/*A+BCDG

Postfix: ABCD*-/
Prefix: /A-B*CD
```
