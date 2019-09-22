#include <iostream>
void HanoiTowers(int a, int b, int c, int n){
    if (n == 0) return;
    HanoiTowers(a, c, b, n - 1);
    std::cout << "Move disk " << n << " From tower " << a << " to tower " << c << std::endl;
    HanoiTowers(b, a, c, n - 1);
}
int main(){
    int n;
    while(std::cin >> n){
        HanoiTowers(2, 3, 1, n);
    }
}