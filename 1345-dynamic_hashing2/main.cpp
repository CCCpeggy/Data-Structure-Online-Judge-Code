#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<string*> table;
int vSize = 4;

int hashFunc(string w) {
    int first = (w[0] - 'A' + 4) * 8;
    int second = w[1] - '0';
    return (first + second) % vSize;
}

int put(string value) {
    int hash = hashFunc(value);
    if (table[hash][0].empty()) table[hash][0] = value;
    else if (table[hash][1].empty()) table[hash][1] = value;
    else {
        table[hash][2] = value;
        int bucketSize = 3;
        string* arr = table[hash];
        for (int i = 0; i < bucketSize-1;) {
            int tableH = hashFunc(table[hash][i]);
            if (hash != tableH) {
                if (arr == table[tableH]) table[tableH] = new string[3]{ arr[i] };
                else table[tableH][1] = arr[i];
                for (int j = i + 1; j < bucketSize; j++) arr[j - 1] = arr[j];
                for (int j = bucketSize - 1; j < 3; j++) arr[j].clear();
                bucketSize--;
            }
            else i++;
        }
        if (bucketSize == 3) {
            table.insert(table.end(), table.begin(), table.end());
            vSize *= 2;
            return put(value);
        }
    }
    return hash;
}

void get(int index) {
    if (index >= vSize) cout << "Out of range.";
    else if (!table[index][0].empty()) {
        cout << table[index][0];
        if (!table[index][1].empty()) cout << " " << table[index][1];
    }
    else cout << "The bucket is empty.";
}

int main() {
    string cmd;
    table.push_back(new string[3]{});
    table.push_back(new string[3]{});
    table.push_back(new string[3]{});
    table.push_back(new string[3]{});
    while (cin >> cmd) {
        if (cmd[0] == 'p') {
            string value;
            cin >> value;
            cout << put(value);
        }
        if (cmd[0] == 'g') {
            int index;
            cin >> index;
            get(index);
        }
        if (cmd[0] == 'e') break;
        cout << endl;
    }
}