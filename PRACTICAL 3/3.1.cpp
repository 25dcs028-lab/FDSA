#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[1000];
    cin.getline(str, 1000);

    char longest[1000];
    int maxLen = 0;

    char word[1000];
    int j = 0;

    for (int i = 0; ; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            word[j++] = str[i];
        } else {
            word[j] = '\0';

            int len = strlen(word);
            if (len > maxLen) {
                maxLen = len;
                strcpy(longest, word);
            }

            j = 0;

            if (str[i] == '\0')
                break;
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << maxLen << endl;

    return 0;
}
