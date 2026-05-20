#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> arr) {

    sort(arr.begin(), arr.end(), greater<int>());

    int alex = 0;
    int bob = 0;
    bool alexTurn = true;

    for (int i = 0; i < n; i++) {
        // skip duplicates
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        if (alexTurn)
            alex += arr[i];
        else
            bob += arr[i];

        alexTurn = !alexTurn;
    }

    if (alex > bob)
        return "Alex";
    else
        return "Bob";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << solve(n, arr) << "\n";
    }

    return 0;
}
