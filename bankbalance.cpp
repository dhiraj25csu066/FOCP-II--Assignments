#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Bank {
    unordered_map<int, int> balance;

public:
    bool CREATE(int id, int amt) {
        if (balance.count(id)) return false;
        balance[id] = amt;
        return true;
    }

    bool CREDIT(int id, int amt) {
        if (!balance.count(id)) return false;
        balance[id] += amt;
        return true;
    }

    bool DEBIT(int id, int amt) {
        if (!balance.count(id) || balance[id] < amt)
            return false;
        balance[id] -= amt;
        return true;
    }
};

int main() {
    int Q;
    cin >> Q;

    Bank b;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int x, y;
            cin >> x >> y;
            cout << (b.CREATE(x, y) ? "true" : "false") << endl;
        }
        else if (query == "CREDIT") {
            int x, y;
            cin >> x >> y;
            cout << (b.CREDIT(x, y) ? "true" : "false") << endl;
        }
        else if (query == "DEBIT") {
            int x, y;
            cin >> x >> y;
            cout << (b.DEBIT(x, y) ? "true" : "false") << endl;
        }
    }

    return 0;
}
