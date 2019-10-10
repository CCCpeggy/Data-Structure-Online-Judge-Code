# 1341: 108資料結構作業 - Sparse Matrix

* Time Limit: 1 Sec
* Memory Limit: 128 MB
* Submit: 18
* Solved: 4

## Description

```content
A simpler and more efficient representation for sparse matrices can be obtained when one is limited to the operations of additon, subraction, and multiplication. Now, nodes have the data represented by a node. These nodes are linked together to form two circular lists. The first list, the row list, is made up by linking nodes by rows and within rows by columns. The linking is done via the right data member. The second list, the column list, is made up by linking nodes via the down data member. In this list, nodes are linked by columns and within columns by rows. These two lists share a common header node, In addition, a node is added to contain the dimensions of the matrix. Draw the resulting representation for the matrix of Figure 4.25.

Write a C++ class for this representation. You must include the following

functions.

(a) istream& operator>>(istream& os, Matrix& m):

Read in the matrix and set it up according to the representation of this section. The first input line gives the matrix dimensions and number of nodes in the matrix. The next several lines contain one triple, (row, column, value), each. The last triple ends the input file. These triples are in increasing order by rows. Within rows, the triples are in increasing order of columns. The data is to be read in one line at a time and converted to internal representation.

(b) ostream& operator<<(ostream& os, const Matrix& m):

Output the terms of m. Output format： (row, column, value). The output should be ordered by rows and within rows by columns.

(c) Matrix ::Matrix(const Matrix& a) [Copy Constructor]:

Initialize the sparse matrix *this to the sparse matrix a.

(d) const Matrix& Matrix::operator=(const Matrix& a) const [Assignment Operator]:

Assign sparse matrix a to *this.

(e) ~Matrix:: Matrix () [Destructor]:

Return all nodes of the sparse matrix *this to the available-space list.

(f) Matrix Matrix ::operator+(const Matrix& b) const:

Create and return the sparse matrix *this +b.

(g) Matrix Matrix ::operator-(const Matrix& b) const:

Create and return the sparse matrix *this-b.

(h)Matrix Matrix :operator* (const Matrix&amp; b) const:

Create and return the sparse matrix *this * b.

(i) Matrix Matrix ::Transpose () const:

Create and return the transpose of *this.
```

## Input

```content
See the Sample Input.
```

## Output

```content
See the Sample Output.
```

## Sample Input

```content
+
3 4 7
0 0 1
0 3 1
1 0 3
1 2 1
2 0 1
2 2 1
2 3 1
3 4 4
0 0 4
0 3 1
1 1 9
2 2 7
T
2 3 2
0 0 1
1 0 3
-
3 4 7
0 0 1
0 3 1
1 0 3
1 2 1
2 0 1
2 2 1
2 3 1
2 2 2
0 0 1
1 0 3
*
6 3 5
0 0 2
1 1 1
3 1 1
4 1 1
5 2 9
3 6 3
0 5 7
1 0 4
2 4 9
```

## Sample Output

```content
0 0 5
0 3 2
1 0 3
1 1 9
1 2 1
2 0 1
2 2 8
2 3 1
0 0 1
0 1 3
Error dimensions!
0 5 14
1 0 4
3 0 4
4 0 4
5 4 81
```
