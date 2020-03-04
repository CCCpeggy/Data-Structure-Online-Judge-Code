#include <iostream>
using namespace std;
class Tree {
public:
    int n;
    int** edge;
    int* last;
    int* distance;
    Tree(int N) :n(N + 1), edge{ new int* [n] }, last{ new int[n] }, distance{ new int[n] }{
        for (int i = 1; i < n; i++) {
            edge[i] = new int[n];
            distance[i] = 10000000;
            for (int j = 1; j < n; j++) {
                if (i == j)edge[i][j] = 0;
                else edge[i][j] = 10000000;
            }
        }
    }
    void connect(int i, int j, int weight) {
        if (edge[i][j] > weight) edge[i][j] = weight;
        if (edge[j][i] > weight) edge[j][i] = weight;
    }
    void compute(int point) {
        bool* update = new bool[n] {};
        distance[point] = 0;
        last[point] = point;
        int updateValue = point;
        for (int updateSum = 1; updateSum < n; updateSum++) {
            update[updateValue] = true;
            int minDis = 10000000, minIdx=-1;
            for (int i = 1; i < n; i++) {
                if(edge[updateValue][i] < 10000000){
                    int newDis = edge[updateValue][i] + distance[updateValue];
                    if (newDis > 0 && newDis < distance[i]) {
                        distance[i] = newDis;
                        last[i] = updateValue;
                    }
                }
                if (!(update[i]) && distance[i] < minDis) {
                    minDis = distance[i];
                    minIdx = i;
                }
            }
            if (minIdx < 0) break;
            updateValue = minIdx;
        }

    }
    void print(int point) {
        if (point == last[point]) {cout << point;}
        else {
            print(last[point]);
            cout << " " << point;
        }
    }
};
int main() {
    int n, l, p;
    cin >> n >> l >> p;
    Tree t(n);
    while (l--) {
        int line1, line2, weight;
        cin >> line1 >> line2 >> weight;
        t.connect(line1, line2, weight);
    }
    t.compute(p);
    for (int i = 1; i <= n; i++) {
        if (i != p) {
            cout << "Distance of " << p << " to " << i << ": " << t.distance[i] << endl;
            cout << "Path: ";
            t.print(i);
            cout << " " << endl;
        }
    }
}