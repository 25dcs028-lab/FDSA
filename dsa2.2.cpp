#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target);
    else
        return binarySearchRecursive(arr, left, mid - 1, target);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int target;

    cout << "Enter book code: ";
    cin >> target;

    int pos1 = binarySearchIterative(arr, n, target);
    int pos2 = binarySearchRecursive(arr, 0, n - 1, target);

    if (pos1 != -1)
        cout << "Iterative: Found at position " << pos1 << endl;
    else
        cout << "Iterative: Not found" << endl;

    if (pos2 != -1)
        cout << "Recursive: Found at position " << pos2 << endl;
    else
        cout << "Recursive: Not found" << endl;

    return 0;
}
