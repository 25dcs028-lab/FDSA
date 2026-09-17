#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;
    Node* current;
    int count;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
        current = NULL;
        count = 0;
    }

    void addBegin(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
            current = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        count++;
    }

    void addEnd(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
            current = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        count++;
    }

    void insertAfterCurrent(string song) {
        if (current == NULL) {
            addBegin(song);
            return;
        }

        Node* newNode = new Node(song);

        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        else {
            tail = newNode;
        }

        current->next = newNode;

        count++;
    }

    void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty\n";
            return;
        }

        Node* temp = head;

        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }

        if (current == temp) {
            current = head;
        }

        delete temp;
        count--;
    }

    void play(string song) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->song == song) {
                current = temp;
                cout << "Now playing: " << song << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Song not found\n";
    }

    void showCount() {
        cout << "Number of songs: " << count << endl;
    }

    void display() {
        Node* temp = head;

        cout << "Playlist: ";

        if (temp == NULL) {
            cout << "Empty";
        }

        while (temp != NULL) {
            cout << temp->song;

            if (temp->next != NULL) {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Playlist p;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "ADD_BEGIN") {
            string song;
            cin >> song;

            p.addBegin(song);
            p.display();
        }

        else if (operation == "ADD_END") {
            string song;
            cin >> song;

            p.addEnd(song);
            p.display();
        }

        else if (operation == "PLAY") {
            string song;
            cin >> song;

            p.play(song);
            p.display();
        }

        else if (operation == "INSERT_AFTER") {
            string song;
            cin >> song;

            p.insertAfterCurrent(song);
            p.display();
        }

        else if (operation == "REMOVE") {
            p.removeFirst();
            p.display();
        }

        else if (operation == "COUNT") {
            p.showCount();
        }

        else if (operation == "DISPLAY") {
            p.display();
        }

        else {
            cout << "Invalid operation\n";
        }
    }

    return 0;
}