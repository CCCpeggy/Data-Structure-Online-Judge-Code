#include <iostream>
using namespace std;

class Heap{
    public:
    int *data;
    int n;
    int cur;
    Heap(): cur(1){}
    void show(){cout << data[cur]<< endl;;}
    void left(){
        cur *= 2;
        cout << data[cur]<< endl;;
    }
    void right(){
        cur *= 2;
        cout << data[++cur]<< endl;;
    }
    void heapify(int i){
        int left = 2*i, right = left+1;
        int maxIdx = i;
        if(left <= n) if (data[left] > data[maxIdx]) maxIdx = left;
        if(right <= n) if (data[right] > data[maxIdx]) maxIdx = right;
        if(maxIdx != i){
            int tmp = data[maxIdx];
            data[maxIdx] = data[i];
            data[i] = tmp;
            heapify(maxIdx);
        }
    }
    void adjust(){
        for(int i=n/2; i>=1; i--) heapify(i);
    }
    void heapTop(){
        data[1] = data[n--];
        adjust();
        cur = 1;
    }
};
istream& operator>> (istream& is, Heap& h){
    cin >> h.n;
    h.data = new int[h.n+1];
    for(int i=1; i<=h.n; i++) 
        cin >> h.data[i];
    h.adjust();
}
int main(){
    Heap h;
    cin >> h;
    string cmd;
    while(cin >> cmd){
        if(cmd[0] == 's') h.show();
        if(cmd[0] == 'l') h.left();
        if(cmd[0] == 'r') h.right();
        if(cmd[0] == 'h') h.heapTop();
    }
}