#include <iostream>
using namespace std;

int main() {
    char ch;
    bool isOpen = true;
    // ty hong for this code btw
    // How it's work:
    // 1. get a character, yes character
    // 2. print it back right away, yes get one char, print one char
    // 3. if its ' " ' just change it idk
    // 4. track if its open / close
    while (cin.get(ch)) {
        if (ch == '"') {
            if (isOpen) {
                cout << "``";
            } else {
                cout << "''";
            }
            isOpen = !isOpen;
        } else {
            cout << ch;
        }
    }

    return 0;
}