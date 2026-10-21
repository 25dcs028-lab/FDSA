#include <iostream>
using namespace std;

struct Node {
    int patient;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

int main() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;

    int choice, value;

    cout << "1. Arrive\n2. Attend\n3. Exit\n";

    while (true) {
        cout << "\nEnter operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter patient number: ";
            cin >> value;

            Node* newNode = new Node;
            newNode->patient = value;
            newNode->next = NULL;

            if (q.rear == NULL) {
                q.front = q.rear = newNode;
            } else {
                q.rear->next = newNode;
                q.rear = newNode;
            }

            cout << "Patient added successfully.\n";
        }
        else if (choice == 2) {
            if (q.front == NULL) {
                cout << "Error: No patients waiting!\n";
            } else {
                Node* temp = q.front;

                cout << "Attended patient: "
                     << temp->patient << endl;

                q.front = q.front->next;

                if (q.front == NULL)
                    q.rear = NULL;

                delete temp;
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid operation!\n";
            continue;
        }

        if (q.front == NULL)
            cout << "Front patient: None\n";
        else
            cout << "Front patient: "
                 << q.front->patient << endl;
    }

    while (q.front != NULL) {
        Node* temp = q.front;
        q.front = q.front->next;
        delete temp;
    }

    return 0;
}