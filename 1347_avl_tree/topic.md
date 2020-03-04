# 1347: 108資料結構作業 - AVL tree

* Time Limit: 1 Sec
* Memory Limit: 128 MB

## Description

``` text
Write a program to implement print, insert, and remove operations for AVL tree. After doing some insert and remove operations, you have to make sure tree is still an AVL tree.


You need to design you own class and add any function to implement AVL tree.


Command requirement:

INSERT <int> - insert integer data into tree. If insert duplicate data, ignore.

REMOVE <int> - remove integer data from tree. If the removed node has two children nodes, choose the largest node from left child tree to replace. If node not exists, ignore.

After removing a node, if your AVL tree can do both LL and LR rotation to fix the balance of tree, choose LL rotation fisrt, and if AVL tree can do both RR and RL rotation to fix the balance of tree, choose RR rotation fisrt.

PRINT – print out data of tree with pre-order traversal.
```

## Input

``` text
Input some commands to insert and remove data from tree, finally print the tree with pre-order traversal.
```

## Output

``` text
Print out data of tree with pre-order traversal.
```

## Sample Input

``` text
INSERT 0
INSERT 0
INSERT 0
INSERT 0
INSERT 0
INSERT 0
INSERT 0
INSERT 1
INSERT 2
INSERT 3
INSERT 4
INSERT 5
INSERT 6
INSERT 7
INSERT 8
INSERT 9
REMOVE 7
PRINT
```

## Sample Output

``` text
3,1,0,2,6,5,4,8,9
```

## HINT

Example Class definition:

``` C++
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
    private:
        Node* root;
    public:
        AVLTree();
        void insert();
        void remove();
        void print();
};
```
