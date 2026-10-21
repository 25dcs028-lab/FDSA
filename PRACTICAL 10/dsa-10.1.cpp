#include <iostream>
using namespace std;

int main() {
    int slots[10];
    int n, reg;

    for (int i = 0; i < 10; i++)
        slots[i] = -1;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number: ";
        cin >> reg;

        int index = reg % 10;
        int count = 0;

        while (slots[index] != -1 && count < 10) {
            index = (index + 1) % 10;
            count++;
        }

        if (count == 10) {
            cout << "Parking lot is full!\n";
        } else {
            slots[index] = reg;
            cout << "Vehicle parked at slot " << index << endl;
        }
    }

    cout << "\nFinal Parking Lot:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";

        if (slots[i] == -1)
            cout << "Empty";
        else
            cout << slots[i];

        cout << endl;
    }

    return 0;
}