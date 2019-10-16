#include <iostream>
#include <string>
#define OTHER 2147483647
#define FRONT_BRACKET 4
#define DIVISOR 3
#define MULT 3
#define MINUS 2
#define PLUS 2
#define REAR_BRACKET 1
using namespace std;

class Stack{
    private:
    int N;
    int size;
    int * stack;
    public:
    Stack():size(0), N(1), stack(nullptr){
        stack = new int[1];
    }
    void push(char value, int right){
        int newSize = size + 1;
        if(newSize >= N){
            N *= 2;
            int * newStack = new int[N];
            for(int i = 0; i < size; i++) newStack[i] = stack[i];
            delete stack;
            stack = newStack;
        }
        stack[size] = value * 1000 + right;
        size ++;
    }
    char pop(){
        if(size > 0) {
            size--;
            return stack[size] / 1000;
        }
        return 0;
    }
    int right(){
        if(size > 0) return stack[size - 1] % 1000;
        return 0;
    }
    char operator[](int index){
        if(index < size) return stack[index] / 1000;
        return 0;
    }
};

string postfix(string infix){
    Stack stack;
    string s = "";
    int right = 0;
    for(char c:infix){
        int symbolRight = 0;
        bool printChar = false;
        switch (c)
        {
            case '(':
                symbolRight = FRONT_BRACKET + right;
                right += FRONT_BRACKET;
                break;
            case '/':
                symbolRight = DIVISOR + right;
                printChar = true;
                break;
            case '*':
                symbolRight = MULT + right;
                printChar =  true;
                break;
            case '-':
                symbolRight = MINUS + right;
                printChar =  true;
                break;
            case '+':
                symbolRight = PLUS + right;
                printChar =  true;
                break;
            case ')':
                symbolRight = REAR_BRACKET + right;
                right -= FRONT_BRACKET;
                break;
            default:
                symbolRight = OTHER;
        }
        if (symbolRight == OTHER){
            s += c ;
        }
        else {
            while(stack.right() >= symbolRight) s += stack.pop();
            if(printChar) stack.push(c, symbolRight);
        }
    }
    while(stack.right()) s += stack.pop();
    return s;
}

string prefix(string::reverse_iterator& begin, string::reverse_iterator& end){
    
    string s[] = {"", "", ""};
    s[0] = *(begin++);
    int count = 2;
    while(count && begin != end){
        char c = *begin;
        if(c == '/'||c == '*'||c == '-'||c == '+') s[count--] += prefix(begin, end);
        else {
            s[count--] += c;
            begin++;
        }
    }
    return s[0] + s[1] + s[2];
}

int main(){
    string formula;
    while (cin >> formula){
        string post = postfix(formula);
        cout << "Postfix: " << post << endl;
        
        auto begin = post.rbegin(), end = post.rend();
        cout << "Prefix: " << prefix(begin, end) << endl << endl;
        
    }

}