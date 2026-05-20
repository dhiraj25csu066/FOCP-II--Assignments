#include <iostream>
using namespace std;

bool possible(string bulbs, int n, int m, int k) {
    int operations = 0;

    for (int i = 0; i < n; ) {
        if (bulbs[i] == '1') {
            operations++;     
            i = i + k;        
        } else {
            i++;              
        }
    }

    return operations <= m;
}

int main() {
    int n, m;
    cin >> n >> m;

    string bulbs;
    cin >> bulbs;

    int left = 1, right = n;
    int answer = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (possible(bulbs, n, m, mid)) {
            answer = mid;    
            right = mid - 1;  
        } else {
            left = mid + 1;   
        }
    }

    cout << answer;

    return 0;
}
