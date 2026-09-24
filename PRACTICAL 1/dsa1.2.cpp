#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cout << "Enter number of borrowed books: ";
    cin >> n;

    int id;
    map<int, int> count;

    cout << "Enter book IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> id;
        count[id]++;
    }

    cout << "Books borrowed more than once: ";

    for (auto x : count) {
        if (x.second > 1) {
            cout << x.first << " ";
        }
    }

    return 0;
}