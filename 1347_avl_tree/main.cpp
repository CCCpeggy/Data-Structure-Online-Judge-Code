#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
    int value;
    Node* left;
    Node* right;
    Node(int value): value(value), right(nullptr), left(nullptr){}
};

class AVLTree {
    private:
        Node* root;
    public:
        AVLTree(): root(nullptr){}
        void insert(int num){
            Node** cur = &root;
            while (*cur){
                if (num > (*cur) -> value) cur = &((*cur) -> right);
                else if (num < (*cur) -> value) cur = &((*cur) -> left);
                else return;
            }
            *cur = new Node(num);
            adjust();
        }
        void remove(int num){
            Node** cur = &root;
            while ((*cur) && num != (*cur) -> value){
                if (num > (*cur) -> value) cur = &((*cur) -> right);
                else cur = &((*cur) -> left);
            }
            if (!(*cur)) return;
            if ((*cur) -> left){
                Node** max = &((*cur) -> left);
                while ((*max) -> right) max = &((*max) -> right);
                (*cur) -> value = (*max) -> value;
                (*max) = (*max) -> left;
            }
            else *cur = (*cur) -> right;
            adjust();
        }
        void print(Node* cur = nullptr){
            if (!cur) cur = root;
            else if (root) cout << ",";
            if (cur){
                cout << cur -> value;
                if (cur -> left) print(cur -> left); 
                if (cur -> right) print(cur -> right); 
            } 
        }
        void adjust(Node** cur = nullptr){
            if (!cur) cur = &root;
            if (*cur){
                if ((*cur) -> left) adjust(&((*cur) -> left)); 
                if ((*cur) -> right) adjust(&((*cur) -> right)); 
                Node * tmp;
                switch (determineCase(*cur)){
                    case 0:
                        tmp = *cur;
                        *cur = (*cur) -> left;
                        tmp -> left = (*cur) -> right;
                        (*cur) -> right = tmp;
                        break;
                    case 3:
                        tmp = *cur;
                        *cur = (*cur) -> right;
                        tmp -> right = (*cur) -> left;
                        (*cur) -> left = tmp;
                        break;
                    case 1:
                        tmp = (*cur) -> left -> right;
                        (*cur) -> left -> right = tmp -> left;
                        tmp -> left = (*cur) -> left;
                        (*cur) -> left = tmp -> right;
                        tmp -> right = *cur;
                        *cur = tmp;
                        break;
                    case 2:
                        tmp = (*cur) -> right -> left;
                        (*cur) -> right -> left = tmp -> right;
                        tmp -> right = (*cur) -> right;
                        (*cur) -> right = tmp -> left;
                        tmp -> left = *cur;
                        *cur = tmp;
                        break;
                }
            } 
        }
        int getHeight(Node* node){
            if (!node) return 0;
            int left = getHeight(node -> left), right = getHeight(node -> right);
            return (left > right ? left : right) + 1;
        }
        int determineCase(Node* node){
            int left = getHeight(node -> left), right = getHeight(node -> right);
            int diff = left > right ? left - right : right - left;
            if (diff <= 1) return -1;
            int thisCase = left >= right? 0: 2;
            node = left >= right? node -> left: node -> right;
            left = getHeight(node -> left); 
            right = getHeight(node -> right);
            thisCase += left >= right? 0: 1;
            return thisCase;
        }
};

int main(){
    AVLTree a;
    string s;
    int num;
    while(cin >> s){
        if (s[0] == 'I') {
            cin >> num;
            a.insert(num);
        }
        if (s[0] == 'R') {
            cin >> num;
            a.remove(num);
        }
        if (s[0] == 'P') {
            a.print();
            cout << endl;
        }
    }
}