#include <iostream>
using namespace std;

#define MAX 5

struct Queue {
    int arr[MAX];
    int front, rear, count;
};

int main() {
    Queue q;
    q.front = 0;
    q.rear = -1;
    q.count = 0;

    int choice, value;

    cout << "1. Join\n2. Serve\n3. Exit\n";

    while (true) {
        cout << "\nEnter operation: ";
        cin >> choice;

        if (choice == 1) {
            if (q.count == MAX) {
                cout << "Error: Queue is full!\n";
            } else {
                cout << "Enter token number: ";
                cin >> value;

                q.rear = (q.rear + 1) % MAX;
                q.arr[q.rear] = value;
                q.count++;

                cout << "Token joined successfully.\n";
            }
        }
        else if (choice == 2) {
            if (q.count == 0) {
                cout << "Error: Queue is empty!\n";
            } else {
                cout << "Served token: "
                     << q.arr[q.front] << endl;

                q.front = (q.front + 1) % MAX;
                q.count--;
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid operation!\n";
            continue;
        }

        if (q.count == 0)
            cout << "Front token: None\n";
        else
            cout << "Front token: "
                 << q.arr[q.front] << endl;
    }

    return 0;
}