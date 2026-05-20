#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long odd = (b + 1) / 2 - a / 2;

    if (odd % 2 == 0)
        cout << "even";
    else
        cout << "odd";

    return 0;
}
