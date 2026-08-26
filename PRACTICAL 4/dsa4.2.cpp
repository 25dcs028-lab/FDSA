#include <iostream>
using namespace std;

struct Node {
    int token;
    Node *next;
};

class PatientQueue {
    Node *head;

public:
    PatientQueue() {
        head = NULL;
    }

    void insertEnd(int x) {
        Node *newNode = new Node;
        newNode->token = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void deleteToken(int value) {
        if (head == NULL) {
            cout << "Queue is empty.\n";
            return;
        }

        if (head->token == value) {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Token " << value << " removed.\n";
            return;
        }

        Node *curr = head;
        while (curr->next != NULL && curr->next->token != value)
            curr = curr->next;

        if (curr->next == NULL) {
            cout << "Token not found.\n";
            return;
        }

        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
        cout << "Token " << value << " removed.\n";
    }

    void display() {
        Node *temp = head;

        cout << "Queue : ";
        while (temp != NULL) {
            cout << temp->token << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reversePrint(Node *temp) {
        if (temp == NULL)
            return;

        reversePrint(temp->next);
        cout << temp->token << " ";
    }

    void displayReverse() {
        cout << "Reverse Queue : ";
        reversePrint(head);
        cout << endl;
    }
};

int main() {
    PatientQueue q;

    q.insertEnd(101);
    q.insertEnd(102);
    q.insertEnd(103);
    q.insertEnd(104);

    q.display();

    q.deleteToken(103);
    q.display();

    q.displayReverse();

    return 0;
}
