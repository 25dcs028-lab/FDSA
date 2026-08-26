#include <iostream>
using namespace std;

struct Node {
    int token;
    Node* next;

    Node(int t) {
        token = t;
        next = NULL;
    }
};

class PatientQueue {
private:
    Node* head;

public:
    PatientQueue() {
        head = NULL;
    }

    void insertFront(int token) {
        Node* newNode = new Node(token);

        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int token) {
        Node* newNode = new Node(token);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtPosition(int token, int position) {
        Node* newNode = new Node(token);

        if (position <= 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            delete newNode;

            cout << "Invalid position. Patient not inserted.\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;

        cout << "Queue: ";

        if (temp == NULL) {
            cout << "Empty";
        }

        while (temp != NULL) {
            cout << temp->token;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }

    ~PatientQueue() {
        Node* temp;

        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PatientQueue q;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        int token, position;

        cout << "\nEnter operation: ";
        cin >> operation;

        if (operation == "FRONT") {
            cin >> token;
            q.insertFront(token);
        }
        else if (operation == "END") {
            cin >> token;
            q.insertEnd(token);
        }
        else if (operation == "POS") {
            cin >> token >> position;
            q.insertAtPosition(token, position);
        }
        else {
            cout << "Invalid operation.\n";
        }

        q.display();
    }

    return 0;
}
