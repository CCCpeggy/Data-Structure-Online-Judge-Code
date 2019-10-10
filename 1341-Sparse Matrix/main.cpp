#include <iostream>
using namespace std;

class Matrix;

class MatrixNode{
    friend class Matrix;
public:
    int value;
    MatrixNode* down;
    MatrixNode* right;
    int row, column;
    bool head;
    MatrixNode(bool head=false):head(head), right(this), down(this), row(0), column(column), value(value){
    }
    void transport(){
        int tmp = row;
        row = column;
        column = tmp;
        MatrixNode *tmpPtr = right;
        right = down;
        down = tmpPtr;
    }
};

class Matrix{
    public:
    MatrixNode *headNode;
    int row;
    int column;
    Matrix():headNode(nullptr){};

    Matrix(const Matrix& a){
        operator=(a);
    }

    friend istream& operator>>(istream& is, Matrix& m){
        int line;
        is >> m.row >> m.column >> line;
        m.headNode = new MatrixNode(false);
        if (!m.row||!m.column)return;
        MatrixNode* headRow = new MatrixNode(true);
        MatrixNode* headColumn = new MatrixNode(true);
        m.headNode->down = headRow;
        m.headNode->right = headColumn;
        for(int i=1; i<m.row; i++){
            headRow->down = new MatrixNode(true);
            headRow->row = i;
        }
        headRow->down = m.headNode;
        for(int i=1; i<m.column; i++) {
            headColumn->right = new MatrixNode(true);
            headColumn->column = i;
        }
        headColumn->right = m.headNode;
        while(line--){
            MatrixNode* node = new MatrixNode(false);
            is >> node->row >> node->column >> node->value;
            m.insertNode(node);
        }
    }

    friend ostream& operator<<(ostream& os, const Matrix& m){
        MatrixNode* headRow = m.headNode->down;
        while(headRow->down != m.headNode){
            MatrixNode* node = headRow->right;
            while(node->right != headRow){
                os << node.row << " " << node.column << " " << node.value << endl;
                node = node->right;
            }
            headRow = headRow->down;
        }
    }

    void insertNode(MatrixNode* node){
        MatrixNode* headRow = headNode->down;
        MatrixNode* headColumn = headNode->right;
        for(int i=0; i<node->row; i++) headRow = headRow->down;
        for(int i=0; i<node->column; i++) headRow = headRow->right;
        
        MatrixNode* left = headRow->right;
        MatrixNode* up = headColumn->down;
        while(!left->right->head && left->right->column < node->column) left = left->right;
        while(!up->down->head && up->down->row < node->row) up = up->down;

        node -> right = left->right;
        left -> right = node;
        node -> down = up->down;
        up -> down = node;
    }

    const Matrix& operator=(const Matrix& a)
    {
        row = a.row;
        column = a.column;
        headNode = new MatrixNode(false);
        if (!row||!column)return;
        MatrixNode* headRow = new MatrixNode(true);
        MatrixNode* headColumn = new MatrixNode(true);
        headNode->down = headRow;
        headNode->right = headColumn;
        for(int i=1; i<row; i++){
            headRow->down = new MatrixNode(true);
            headRow->row = i;
        }
        headRow->down = headNode;
        for(int i=1; i<column; i++) {
            headColumn->right = new MatrixNode(true);
            headColumn->column = i;
        }
        headColumn->right = headNode;


        MatrixNode* aheadRow = a.headNode->down;
        MatrixNode* aheadColumn = a.headNode->right;
        while(headRow != headNode){
            MatrixNode* aNode = aheadRow->right;
            while(aNode->right != headRow){
                MatrixNode * node = new MatrixNode(false);
                node -> row = aNode -> row;
                node -> column = aNode -> column;
                node -> value = aNode -> value;
                insertNode(node);
                aNode = aNode->right;
            }
            headRow = headRow->down;
        }
        return *this;
    }

    Matrix operator+(const Matrix& b) const{
        Matrix tmp(*this);
        MatrixNode* aheadRow = a.headNode->down;
        MatrixNode* aheadColumn = a.headNode->right;
        while(headRow != headNode){
            MatrixNode* aNode = aheadRow->right;
            while(aNode->right != headRow){
                MatrixNode * node = new MatrixNode(false);
                node -> row = aNode -> row;
                node -> column = aNode -> column;
                node -> value = aNode -> value;
                insertNode(node);
                aNode = aNode->right;
            }
            headRow = headRow->down;
        }
        return *this;
    }

    Matrix operator-(const Matrix& b) const{
        return *this;
    }

    Matrix operator*(const Matrix& b) const{
        return *this;
    }

    Matrix Transpose() const{
        return *this;
    }

    ~Matrix(){
        MatrixNode* headRow = headNode->down;
        MatrixNode* headColumn = headNode->right;
        MatrixNode* nextRow, *nextColumn;
        while(headRow != headNode){
            nextRow = headRow->down;
            MatrixNode* node = headRow->right;
            MatrixNode* nextNode;
            while(node->right != headRow){
                nextNode = node->right;
                delete node;
                node = nextNode;
            }
            delete headRow;
            headRow = nextRow;
        }
        while(headColumn != headNode){
            nextColumn = headColumn->right;
            delete headColumn;
            headColumn = nextColumn;
        }
        delete headNode;
    }
};

int main(){
    char action;
    while(cin >> action){
        if(action == '+'){
            Matrix matrix1, matrix2;
            cin >> matrix1 >> matrix2;
            Matrix matrix3 = matrix1 + matrix2;
            cout << matrix3;
        }
        else if(action == '-'){
            Matrix matrix1, matrix2;
            cin >> matrix1 >> matrix2;
            Matrix matrix3 = matrix1 - matrix2;
            cout << matrix3;
        }        
        else if(action == '*'){
            Matrix matrix1, matrix2;
            cin >> matrix1 >> matrix2;
            Matrix matrix3 = matrix1 * matrix2;
            cout << matrix3;
        }
        else if(action == 'T'){
            Matrix matrix1;
            cin >> matrix1;
            Matrix matrix3 = matrix1.Transpose();
            cout << matrix3;
        }    
    }
}