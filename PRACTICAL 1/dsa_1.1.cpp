#include <iostream>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    int arr[n];


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k = h % n;


    for (int i = 0; i < n; i++) {
        cout << arr[(i + k) % n] << " ";
    }

    return 0;
}
