#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "Enter a sentence: ";
    getline(cin, str);

    string longest = "";
    string word = "";

    for (int i = 0; i <= str.length(); i++)
    {
        if (i < str.length() && str[i] != ' ')
        {
            word += str[i];
        }
        else
        {
            if (word.length() > longest.length())
            {
                longest = word;
            }
            word = "";
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Number of characters: " << longest.length() << endl;

    return 0;
}