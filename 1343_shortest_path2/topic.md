# 1343: 108資料結構作業 - Shortest Path

* Time Limit: 1 Sec
* Memory Limit: 128 MB

## Description

``` text
Given T is a graph with n vertices. The edges of T are undirected. Each edge in T has a non-negative length. Write a C++ program to read the tree T and calculate shortest distance from a specified vertex s to all the other vertexes. You should print out not only the distance but also the path from s to every vertex.



The input may exist multiple edges between two vertexes. The printing format is the same as Sample Output. You should design a class called Graph to store vertices and edges.
```

## Input

``` text
First Line: n e s

n is number or vertexes

e is number of edges

s is the starting vertex

Second Line ~ (n + 1)th Line: p q d

P and q are non-negative integers indicating the vertex of the defined edge <p, q>, and d is the length of the edge.
```

## Output

``` text
See the Sample Output.
```

## Sample Input

``` text
10 17 7
1 2 1
1 8 1
2 4 1
2 7 1
2 10 1
4 6 1
5 6 1
3 7 1
6 4 1
6 5 1
6 9 1
7 9 1
8 4 1
8 10 1
9 6 1
9 7 1
10 7 1
```

## Sample Output

``` text
Distance of 7 to 1: 2
Path: 7 2 1
Distance of 7 to 2: 1
Path: 7 2
Distance of 7 to 3: 1
Path: 7 3
Distance of 7 to 4: 2
Path: 7 2 4
Distance of 7 to 5: 3
Path: 7 9 6 5
Distance of 7 to 6: 2
Path: 7 9 6
Distance of 7 to 8: 2
Path: 7 10 8
Distance of 7 to 9: 1
Path: 7 9
Distance of 7 to 10: 1
Path: 7 10
```
