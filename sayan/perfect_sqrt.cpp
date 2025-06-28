#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int N;
    cout << "Enter a perfect square number "<< endl;
    cin >> N;

    int res = -1;

    for(int i = 1; i * i <= N; i++) {
        if (i * i == N) {
            res = i;
            break;
        }

    }

    if (res != -1){
        cout << "Square root of " << N << " is " << res << endl;
    }
    else {
        cout << N << "Is not a perfect square." << endl;
    }

    return 0;
}