# 1344: 108資料結構作業 - Heap Sort

* Time Limit: 1 Sec
* Memory Limit: 128 MB

## Description

``` text
Input a list with N elements, and use Heap Sort to do descending sort, and implement following commands:

heap: Pop the root value, and refresh the heap, reset current element to the root value of the heap tree.

left: Move current view to left root of subtree, and output current element.

right: Move current view to right branch, and output current element.

show: Output current element.
```

## Input

``` text
Input N and N elements(element is a positive integer), then input command.
```

## Output

``` text
See the Sample Output.
```

## Sample Input

``` text
10
26 5 77 1 61 11 59 15 48 19
show
left
right
heap
show
right
show
```

## Sample Output

``` text
77
61
19
61
59
59
```