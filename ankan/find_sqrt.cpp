#include <iostream>
using namespace std;


int find_perfect_sqrt (int x) {
    if (x == 1)
        return 1;
    int left = 2;
    int right = x / 2;

    while (left <= right) {
        
        int mid = left + (right - left) / 2;
        long long i = (long long) mid * mid;
        if (i == x) 
            return mid;
        else if (i < x)
            left = mid + 1;
        else
            right = mid - 1;
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