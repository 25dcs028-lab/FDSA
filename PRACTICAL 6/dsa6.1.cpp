#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
    int n;

public:
    Stack(int size) {
        n = size;
        top = -1;
    }

    void push(int x) {
        if (top == n - 1) {
            cout << "Error: Stack is Full\n";
            return;
        }

        arr[++top] = x;
        cout << "Top tray: " << arr[top] << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Error: Stack is Empty\n";
            return;
        }

        cout << "Removed tray: " << arr[top] << endl;
        top--;

        if (top == -1)
            cout << "Stack is Empty\n";
        else
            cout << "Top tray: " << arr[top] << endl;
    }
};

int main() {
    int n;
    cout << "Enter stack capacity: ";
    cin >> n;

    Stack s(n);

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    s.pop();

    return 0;
}