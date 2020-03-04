
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Tree {
public:
    vector<int> head;
    int size;
    Tree() : size(0) {
        head.push_back(0);
    }
    void swap(int i, int j) {
        int tmp = head[i];
        head[i] = head[j];
        head[j] = tmp;
    }
    void insert(int num) {
        size++;
        head.push_back(num);
        for (int i = size; i > 1; i /= 2) {
            int j = i / 2;
            if (head[j] < head[i]) swap(i, j);
            else break;
        }
    }
    void del(int num) {
        if (size) {
            bool found = false;
            for (int i = size; i > 0; i--) {
                if (head[i] == num) {
                    deleteNode(i);
                    found = true;
                }
            }
            if (!found) {
                cout << "Value " << num << " is not in the heap." << endl;
            }
        }
        else {
            cout << "The heap is empty." << endl;
        }
    }
    void deleteNode(int index) {
        swap(size, index);
        size--;
        head.pop_back();
        for (int i = index; i * 2 <= size;) {
            int maxIndex = i, left = i * 2, right = left + 1;
            if (right <= size && head[right] > head[maxIndex]) {
                maxIndex = right;
            }
            if (head[left] > head[maxIndex]) {
                maxIndex = left;
            }
            if (maxIndex != i) {
                swap(i, maxIndex);
                i = maxIndex;
            }
            else break;
        }

    }
    void print() {
        for (int i = 1; i <= size; i++) {
            if(i != 1) cout << " ";
            cout << head[i];
        }
        cout << endl;
    }
};

int main() {
    string cmd;
    Tree t;
    while (getline(cin, cmd)) {
        stringstream ss;
        ss << cmd;
        ss >> cmd;
        if (cmd[0] == 'I') {
            int num;
            while (ss >> num) t.insert(num);
        }
        if (cmd[0] == 'D') {
            int num;
            while (ss >> num) t.del(num);
        }
        if (cmd[0] == 'P') {
            t.print();
        }
        if (cmd[0] == 'E') {
            break;
        }
    }
}