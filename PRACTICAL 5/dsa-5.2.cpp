
#include <iostream>
using namespace std;


class SinglyCircular {
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = NULL;
        }
    };

    Node* head;

public:
    SinglyCircular() {
        head = NULL;
    }

    void join(int value, int position) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        if (position == 1) {
            Node* temp = head;

            while (temp->next != head)
                temp = temp->next;

            newNode->next = head;
            temp->next = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void leave(int value) {
        if (head == NULL)
            return;

        Node* current = head;
        Node* previous = NULL;

        if (head->data == value && head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        if (head->data == value) {
            Node* last = head;

            while (last->next != head)
                last = last->next;

            head = head->next;
            last->next = head;

            delete current;
            return;
        }

        previous = head;
        current = head->next;

        while (current != head) {
            if (current->data == value) {
                previous->next = current->next;
                delete current;
                return;
            }

            previous = current;
            current = current->next;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "Circle is empty";
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
};


class DoublyCircular {
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int value) {
            data = value;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head;

public:
    DoublyCircular() {
        head = NULL;
    }

    void join(int value, int position) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        if (position == 1) {
            Node* last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            last->next = newNode;
            head->prev = newNode;

            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void leave(int value) {
        if (head == NULL)
            return;

        Node* current = head;

        do {
            if (current->data == value)
                break;

            current = current->next;

        } while (current != head);

        if (current->data != value)
            return;

        if (current->next == current) {
            delete current;
            head = NULL;
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == head)
            head = current->next;

        delete current;
    }

    void display() {
        if (head == NULL) {
            cout << "Circle is empty";
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
};


int main() {

    SinglyCircular s;
    DoublyCircular d;

    int choice, id, position;

    cout << "CIRCULAR PASSING GAME\n";

    while (true) {

        cout << "\n\n1. Join Student";
        cout << "\n2. Leave Student";
        cout << "\n3. Display Circle";
        cout << "\n4. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {

            cout << "Enter student ID: ";
            cin >> id;

            cout << "Enter position: ";
            cin >> position;

            s.join(id, position);
            d.join(id, position);

            cout << "\nSingly Circular: ";
            s.display();

            cout << "\nDoubly Circular: ";
            d.display();
        }

        else if (choice == 2) {

            cout << "Enter student ID to leave: ";
            cin >> id;

            s.leave(id);
            d.leave(id);

            cout << "\nSingly Circular: ";
            s.display();

            cout << "\nDoubly Circular: ";
            d.display();
        }

        else if (choice == 3) {

            cout << "\nSingly Circular: ";
            s.display();

            cout << "\nDoubly Circular: ";
            d.display();
        }

        else if (choice == 4) {
            cout << "\nProgram ended.";
            break;
        }

        else {
            cout << "\nInvalid choice!";
        }
    }

    return 0;
}

