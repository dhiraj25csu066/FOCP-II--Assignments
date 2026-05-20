#include <iostream>
using namespace std;

int countDistinctPrimes(int n) {
    int count = 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1) count++;

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int k = countDistinctPrimes(n);

        int ans = 1 << k;   
        cout << ans << "\n";
    }

    return 0;
}
