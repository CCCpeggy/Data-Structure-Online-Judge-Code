#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    int num;
    bool op;
    Node *left, *right;
    Node(int num, bool op): num(num), op(op), left(nullptr), right(nullptr){}
    
    void print(){
        if(op) cout << (char)num;
        cout << num;
    }
};

class Tree{
    public:
    Node* head;
    Tree(string formula){

    }
    int piority(int op, int& weight){
        switch(op){
            case '+':
            case '-':
                return weight + 1;
            case '*':
            case '/':
                return weight + 1;
            case '(':
                weight += 20;
            case ')':
                weight -= 10;
                return -1;
            default:
                return 0;
        }
    }
    int readNum(string& str, int& basicWeight, int& nextOpWeight){
        int num = 0, i;
        nextOpWeight = 0;
        for(i = 0; str[i]; i++){
            nextOpWeight = piority(str[i], basicWeight);
            if (nextOpWeight > 0) break;
            num *= 10;
            num += str[i] - '0';
        }
        str = str.substr(i);
        return num;
    }
    Node* build(string str, int& basicWeight, Node* left=nullptr){
        if (str.empty()) return left;
        else if (left){
            int op = str[0];
            Node *thisNode = new Node(op, true);
            return build(str, basicWeight, thisNode);
        }
        else{
            int opWeight;
            int newBasicWeight = basicWeight;
            int num = readNum(str, newBasicWeight, opWeight);
            Node *thisNode = new Node(num, true);
            if (opWeight > basicWeight){
                Node *thisNodeLeft = thisNode;
                thisNode = build(str, newBasicWeight, thisNodeLeft);
            }
            return build(str, newBasicWeight, thisNode);
        }
    }
    double compute(Node* node){
        if(!node->op) return node->num;
        double num1 = compute(node->left);
        double num2 = compute(node->right);
        switch (node->num)
        {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        }
        return 0;
    }
};

int main(){
    string formula;
    while(cin >> formula){
        Tree t(formula);
        cout << t.compute(t.head);
    } 
}