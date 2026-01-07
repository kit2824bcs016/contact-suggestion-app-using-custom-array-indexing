#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> indexArray[26];
void insertContact(string name) {
    char first = tolower(name[0]);
    if (first < 'a' || first > 'z') return;
    int idx = first - 'a';

    indexArray[idx].push_back(name);
    sort(indexArray[idx].begin(), indexArray[idx].end());
}
void suggestContacts(string prefix) {
    char first = tolower(prefix[0]);
    if (first < 'a' || first > 'z') {
        cout << "Invalid input!\n";
        return;
    }
    int idx = first - 'a';
    bool found = false;
    cout << "\nSuggestions for \"" << prefix << "\":\n";
    for (size_t i = 0; i < indexArray[idx].size(); i++) {
        string name = indexArray[idx][i];
        if (name.compare(0, prefix.length(), prefix) == 0) {
            cout << " - " << name << endl;
            found = true;
        }
    }
    if (!found) cout << "No matches found.\n";
}
int main() {
    insertContact("Aditi");
    insertContact("Amit");
    insertContact("Anusha");
    insertContact("Akash");
    insertContact("Bhavin");
    insertContact("Bharath");
    insertContact("Chitra");
    insertContact("Charan");
    insertContact("Divya");
    string input;
    cout << "=== Contact Suggestion App ===\n";
    while (true) {
        cout << "\nEnter a name prefix (or type 'exit'): ";
        cin >> input;
        if (input == "exit") break;
        suggestContacts(input);
    }
    return 0;
}

