#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> shelf[10];
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> code;

        int index = code % 10;
        shelf[index].push_back(code);
    }

    cout << "\nFinal Shelf Contents:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";

        if (shelf[i].empty()) {
            cout << "Empty";
        } else {
            for (int code : shelf[i]) {
                cout << code << " ";
            }
        }

        cout << endl;
    }

    return 0;
}