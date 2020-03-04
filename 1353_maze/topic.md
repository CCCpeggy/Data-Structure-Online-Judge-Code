# 1353: 108資料結構期中考 - Maze

* Time Limit: 1 Sec
* Memory Limit: 128 MB

## Description

![maze](../../../image/2020-01-04-17-02-09.png)

``` markdown
Given a m x n Maze, where a value of 1 implies a blocked path, while a 0 means one can walk right on through, please output all possible paths from (0, 0) to (m - 1, n - 1) in alphabetical order.

If there is no any path to reach exit, output “No path”. Note that the moving directions include North, East, West, and South only.

Don’t use std::stack from STL library, but std::vector is available.
```

## Input

``` markdown
Input two integers in the first input line to indicate the dimensions of m and n. Then one inputs values of one row in each input line.
```

## Output

``` markdown
Output all possible paths of maze in alphabetical order. If there isno any path to reach exit, output “No path”.
```

## Sample Input

``` markdown
4 6
011001
000101
110000
111000
```

## Sample Output

``` markdown
(0,0),(1,0),(1,1),(1,2),(2,2),(2,3),(2,4),(2,5),(3,5)
(0,0),(1,0),(1,1),(1,2),(2,2),(2,3),(2,4),(3,4),(3,5)
(0,0),(1,0),(1,1),(1,2),(2,2),(2,3),(3,3),(3,4),(2,4),(2,5),(3,5)
(0,0),(1,0),(1,1),(1,2),(2,2),(2,3),(3,3),(3,4),(3,5)

```

## HINT

``` markdown
Note that maybe several inputs in one input file.
```
