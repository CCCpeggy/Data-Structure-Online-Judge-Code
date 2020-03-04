#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    int num;
    Node *left, *right;
    Node(int num): num(num), left(nullptr), right(nullptr){}
};

class Tree{
    public:
    Node* head;
    Tree(): head(nullptr){}
    void insert(int num){
        Node **cur = &head;
        while(*cur){
            cur= &((num < (*cur)->num) ? (*cur)->left: (*cur)->right);
        }
        *cur = new Node(num);
        adjust();
    }
    void del(int num){
        Node **cur = &head;
        while((*cur)->num != num){
            cur= &((num < (*cur)->num) ? (*cur)->left: (*cur)->right);
        }
        Node **max = &((*cur)->left);
        while((*max)->right){
            max= &((num < (*max)->num) ? (*max)->left: (*max)->right);
        }
        int tmp = (*max)->num;
        (*max)->num = (*cur)->num;
        (*cur)->num = tmp;
        *max = (*max)->left;
        adjust();
    }
    void adjust(Node** node=nullptr){
        if(!node) node=&head;
        if(*node){
            adjust(&((*node)->left));
            adjust(&((*node)->right));
            Node *tmp;
            switch (getCase(*node))
            {
            case 0: // LL
                tmp = (*node)->left;
                (*node)->left=tmp->right;
                tmp->right = (*node);
                *node=tmp;
                break;
            case 3: // RR
                tmp = (*node)->right;
                (*node)->right=tmp->left;
                tmp->left = (*node);
                *node=tmp;
                break;
            case 2: // RL
                tmp = (*node)->right->left;
                (*node)->right->left = tmp->right;
                tmp->right = (*node)->right;
                (*node)->right = tmp->left;
                tmp->left = *node;
                *node=tmp;
                break;
            case 1: // LR
                tmp = (*node)->left->right;
                (*node)->left->right = tmp->left;
                tmp->left = (*node)->left;
                (*node)->left = tmp->right;
                tmp->right = *node;
                *node=tmp;
                break;
            
            }
        }
    }
    int getHeight(Node*node){
        if(!node)return 0;
        int right = getHeight(node->right);
        int left = getHeight(node->left);
        return right > left?right:left;
    }
    int getCase(Node*node){
        int right = getHeight(node->right);
        int left = getHeight(node->left);
        int diff = right-left;
        if(diff <= 1 && diff >= -1) return -1;
        node=right>left?node->right:node->left;
        int tCase = right>left?2:0;
        right = getHeight(node->right);
        left = getHeight(node->left);
        tCase += right>left?1:0;
        return tCase;
    }
    void print(Node **node=nullptr){
        if(!node) node = &head;
        else if(*node) cout << ",";
        if(*node){
            cout << (*node) -> num;
            print(&((*node)->left));
            print(&((*node)->right));
        }
    }
};

int main(){
    string cmd;
    Tree t;
    while(cin >> cmd){
        if(cmd[0] == 'I'){
            int num;
            cin >> num;
            t.insert(num);
        }
        if(cmd[0] == 'R'){
            int num;
            cin >> num;
            t.del(num);
        }
        if(cmd[0] == 'P'){
            t.print();
            cout << endl;
        }
    }
}