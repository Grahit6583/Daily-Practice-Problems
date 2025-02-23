#include <iostream>
#include <string>
using namespace std;

string formatText(const string &text) {
    string result;
    int n = text.length();
    int i = 0;

    while (i < n) {
        while (i < n && isalpha(text[i])) {
            result += text[i++];
        }

        if (i < n && text[i] == ' ') {
            while (i < n && text[i] == ' ') {
                i++; 
            }
            if (i < n && isalpha(text[i])) {
                result += ' ';
            }
        }

        if (i < n && (text[i] == ',' || text[i] == '.' || text[i] == '!' || text[i] == '?')) {
            result += text[i++];
            if (i < n && text[i] == ' ') {
                i++; 
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
