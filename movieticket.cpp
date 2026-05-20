#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class MovieTicket {
    unordered_map<int, unordered_set<int>> booked;
    unordered_map<int, int> seats;

public:
    MovieTicket() {}

    bool BOOK(int userId, int movieId) {
        if (seats[movieId] >= 100 || booked[movieId].count(userId))
            return false;

        booked[movieId].insert(userId);
        seats[movieId]++;
        return true;
    }

    bool CANCEL(int userId, int movieId) {
        if (!booked[movieId].count(userId))
            return false;

        booked[movieId].erase(userId);
        seats[movieId]--;
        return true;
    }

    bool IS_BOOKED(int userId, int movieId) {
        return booked[movieId].count(userId);
    }

    int AVAILABLE_TICKETS(int movieId) {
        return 100 - seats[movieId];
    }
};

int main() {
    int Q;
    cin >> Q;

    MovieTicket mt;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << (mt.BOOK(x, y) ? "true" : "false") << endl;
        }
        else if (query == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << (mt.CANCEL(x, y) ? "true" : "false") << endl;
        }
        else if (query == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << (mt.IS_BOOKED(x, y) ? "true" : "false") << endl;
        }
        else if (query == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << mt.AVAILABLE_TICKETS(y) << endl;
        }
    }

    return 0;
}
