#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Node {
public:
    int value[2];
    int size;
    Node* next[3];
    Node* parent;
    int tmpValue;
    Node(int value = 0) : value{ value }, size(value ? 1 : 0), next{} {}
    int insert(int num) {
    }
    void print() {
        cout << value[0];
        for (int i = 1; i < size; i++) {
            cout << " " << value[i];
        }
    }
};

class Tree {
public:
    Node* root;
    Tree() :root(nullptr) {}
    void insert(int num) {
        int updateNum = num;
        if (root) {
            updateNum = insertNode(num, root);
        }
        if (updateNum) {
            Node* newRoot = new Node(updateNum);
            if (root) {
                if (updateNum < root->value[0]) root->next[0] = root;
                if (updateNum > root->value[0]) root->next[1] = root;
            }
            root = newRoot;
        }
    }
    void swap(int* num1, int* num2) {
        int tmp = *num1;
        *num1 = *num2;
        *num2 = tmp;
    }
    Node* insertNode(int num, Node* cur) {
        if (cur->next[0]) {
            int updateNum;
            if (num < cur->value[0]) updateNum = insertNode(num, cur->next[0]);
            else if (cur->size < 2 || num < cur->value[1]) updateNum = insertNode(num, cur->next[1]);
            else updateNum = insertNode(num, cur->next[2]);
            if (updateNum) insertNode(updateNum, cur);
            return 0;
        }
        else {
            if (cur->size == 2)
            {
                if (num < cur->value[0]) {
                    swap(&cur->value[0] , &num);
                }
                else if (num > cur->value[1]) {
                    swap(&cur->value[1], &num);
                }
                return num;
            }
            else {
                for (int i = 0; i < cur->size; i++) {
                    if (num < cur->value[i]) {
                        swap(&cur->value[i], &num);
                    }
                }
                cur->value[cur->size++] = num;
                return 0;
            }
        }
    }
    void split(Node*) {}
    void print() {
        queue<Node*> que;
        queue<int> n;
        que.push(root);
        n.push(1);
        do {
            que.front()->print();
            n.front()--;
            if (n.front() == 0) {
                n.pop();
                cout << endl;
            }
            else cout << " / ";
            for (int i = 0; i < que.front()->size; i++) que.push(que.front()->next[i]);
            n.push(que.front()->size);
            que.pop();
        } while (que.size());
    }
};

int main() {
    string cmd;
    Tree t;
    while (cin >> cmd) {
        if (cmd[0] == 'i') {
            int num;
            cin >> num;
            t.insert(num);
        }
        else if (cmd[0] == 'p') {
            t.print();
        }
    }
}
