#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    int num[2];
    Node* child[3], *parent;
    Node(int num=0): num{num}, child{}, parent(nullptr){};
    int size(){
        int i;
        for(i=0; i<2 && num[i];i++){}
        return i;
    }
    bool isLeaf(){
        for(int i=0; i<3;i++) if(child[i])return false;
        return true;
    }
    Node* getChild(int idx){
        if(child[idx]) {
            child[idx] = new Node();
            child[idx]->parent=this;
        }
        return child[idx];
    }
    Node* setChild(int idx, Node* node){
        child[idx] = node;
	    if (node != NULL) {
            node->parent = this;
        }
    }
    int getSibNumber() {
	for (int i = 0; i < 3; i++) {
		if (this->parent != NULL) {
			if (this == this->parent->getChild(i)) return i;
		}
	}
	return -1;
}
};
class Tree{
    public:
    Node* head;
    Tree(): head(new Node()){    }
    int* sortArr(int n1, int n2, int n3){
        int * arr = new int[3]{n1, n2, n3};
        for(int i=0; i<3; i++)
            for(int j=i+1; j<3; j++){
                if(arr[i] < arr[j]){
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
    }
    void insert(int num){
        Node * node=head;
        while(!node->isLeaf()){
            if(num < node->num[0]) node=node->getChild(0);
            else if(node->size == 2 && num > node->num[0]) node=node->getChild(2);
            else node=node->getChild(0);
        }
        int nodeSize = node->size();
        if(nodeSize<2)node->num[nodeSize] = num;
        else{
            if(!node->parent || node->parent->size()){
                int * sortNum = sortArr(node->num[0], node->num[1], num);
                Node* leftNode = new Node(sortNum[0]);
                Node* rightNode = new Node(sortNum[2]);
                node->
            }
        }
    }
    void print(){

    }
};

int main(){
    Tree a;
    string s;
    int num;
    while(cin >> s){
        if (s[0] == 'i') {
            cin >> num;
            a.insert(num);
        }
        if (s[0] == 'p') {
            a.print();
            cout << endl;
        }
    }
}