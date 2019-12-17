#include <iostream>
#define MAX 2147483647
using namespace std;

class Tree{
    public:
    int n;
    int **node;
    Tree(int n): n(n){
        node = new int*[n];
        for(int i = 0; i < n; i++){
            node[i] = new int[n];
            for(int j = 0; j < n; j++){
                if(i == j) node[i][j] = 0;
                else node[i][j] = -1;
            }
        }
    }
    void connectEdge(int node1, int node2, int distance){
        if(distance < node[node1][node2] || node[node1][node2] < 0){
            node[node1][node2] = distance;
            node[node2][node1] = distance;
        }
    }
    int* computeDistance(int nodeIndex, int ** rood){
        int * distance = new int[n];
        bool * isDone = new bool[n] {0};
        for(int i = 0; i < n; i++) {
            distance[i] = MAX;
            isDone[i] = false;
        }
        distance[nodeIndex] = 0;

        rood[nodeIndex] = new int[nodeIndex + 1]{1, nodeIndex};

        int nowIndex = nodeIndex;
        for(int i = 0; i < n; i++){
            isDone[nowIndex] = true;
            int nextIndex = 0, nextDis = MAX;
            for(int j = 0; j < n; j++){
                int nodeDis = node[nowIndex][j];
                if(nodeDis >= 0) {
                    nodeDis += distance[nowIndex];
                    if(distance[j] > nodeDis) {
                        distance[j] = nodeDis;
                        if(rood[j]) delete[] rood[j];
                        int newSize = rood[nowIndex][0] + 1;
                        rood[j] = new int[newSize + 1]{newSize};
                        for(int k = 1; k < newSize; k++){
                            rood[j][k] = rood[nowIndex][k];
                        }
                        rood[j][newSize] = j;
                    }
                }
                if((distance[j] < nextDis) && (!isDone[j])) {
                    nextIndex = j;
                    nextDis = distance[j];
                }
            }
            nowIndex = nextIndex;
        }
        return distance;
    }
};

int main(){
    int n, e, s;
    cin >> n >> e >> s;
    Tree tree(n);
    while(e--){
        int node1, node2, distance;
        cin >> node1 >> node2 >> distance;
        tree.connectEdge(node1 - 1, node2 - 1, distance);
    }
    int ** rood = new int*[n]{nullptr};
    int *distance = tree.computeDistance(s - 1, rood);
    for(int i = 0; i < n; i++){
        if(s == i + 1 || distance[i] == MAX) continue;
        cout << "Distance of " << s << " to " << i + 1 << ": " << distance[i] << endl;
        cout << "Path: ";
        for(int j = 1; j <= rood[i][0]; j++){
            cout << rood[i][j] + 1 << " ";
        }
        cout  << endl;
    }
}