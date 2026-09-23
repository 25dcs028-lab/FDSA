#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;
};

class Browser {
    Node* top;

public:
    Browser() {
        top = NULL;
    }

    void visit(string page) {
        Node* newNode = new Node();

        newNode->page = page;
        newNode->next = top;
        top = newNode;

        cout << "Current page: " << top->page << endl;
    }

    void back() {
        if (top == NULL) {
            cout << "No history\n";
            return;
        }

        Node* temp = top;
        top = top->next;

        delete temp;

        if (top == NULL)
            cout << "No page left\n";
        else
            cout << "Current page: " << top->page << endl;
    }
};

int main() {
    Browser b;

    b.visit("Google");
    b.visit("YouTube");
    b.visit("Wikipedia");

    b.back();
    b.back();
    b.back();
    b.back();

    return 0;
}