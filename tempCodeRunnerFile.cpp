#include <iostream>
#include <string>
using namespace std;

string formatText(const string &text) {
    string result;
    int n = text.length();
    int i = 0;

    while (i < n) {
        // Append word characters
        while (i < n && isalpha(text[i])) {
            result += text[i++];
        }

        // If a space exists after the word, add exactly one space
        if (i < n && text[i] == ' ') {
            while (i < n && text[i] == ' ') {
                i++; // Skip multiple spaces
            }
            if (i < n && isalpha(text[i])) {
                result += ' ';
            }
        }

        // If punctuation mark found, add it without space before, and add a space after
        if (i < n && (text[i] == ',' || text[i] == '.' || text[i] == '!' || text[i] == '?')) {
            result += text[i++];
            if (i < n && text[i] == ' ') {
                i++; // Skip existing space
            }
            if (i < n && isalpha(text[i])) {
                result += ' ';
            }
        }
    }

    return result;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string text;
    getline(cin, text);

    string formattedText = formatText(text);
    cout << formattedText << endl;

    return 0;
}
