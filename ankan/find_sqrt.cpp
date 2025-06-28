#include <iostream>
using namespace std;


int find_perfect_sqrt (int x) {
    if (x == 1)
        return 1;
    int i = 2;
    while (i <= x / 2) {
        if ( i * i == x)
            return i;
        i++;
    }
}
int main () {
    int x;
    cout << "enter a perfect square number : ";
    cin >> x;
    int sq_rt = find_perfect_sqrt(x);
    cout << "square root of this number is : " << sq_rt;
    return 0;
}