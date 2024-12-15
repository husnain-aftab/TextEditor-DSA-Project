#include <iostream>
#include <string>
using namespace std;

//Node structure for the linked list
struct Node {
    string line;   //Each node stores one line of text
    Node* next;    //Pointer to the next node
};

//Text Editor class
class TextEditor {
private:
    Node* head;    //Head of the linked list

public:
    //Constructor
    TextEditor() {
        head = nullptr; //Initialize the head to null
    }

    //Add a new line to the text
    void addLine(string newLine) {
        Node* newNode = new Node();
        newNode->line = newLine;
        newNode->next = nullptr;

        if (head == nullptr) { //If the list is empty
            head = newNode;
        } else { //Otherwise, add the new node at the end
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Line added successfully!" << endl;
    }

    //Display all lines of text
    void displayText() {
        if (head == nullptr) {
            cout << "No text available. Add some lines first." << endl;
            return;
        }

        Node* temp = head;
        int lineNumber = 1;
        while (temp != nullptr) {
            cout << lineNumber << ": " << temp->line << endl;
            temp = temp->next;
            lineNumber++;
        }
    }

    //Search for a word in the text
    void searchWord(string word) {
        if (head == nullptr) {
            cout << "No text available. Add some lines first." << endl;
            return;
        }

        Node* temp = head;
        int lineNumber = 1;
        bool found = false;

        while (temp != nullptr) {
            if (temp->line.find(word) != string::npos) {
                cout << "Word found in line " << lineNumber << ": " << temp->line << endl;
                found = true;
            }
            temp = temp->next;
            lineNumber++;
        }

        if (!found) {
            cout << "Word '" << word << "' not found." << endl;
        }
    }

    //Replace a word in the text
    void replaceWord(string oldWord, string newWord) {
        if (head == nullptr) {
            cout << "No text available. Add some lines first." << endl;
            return;
        }

        Node* temp = head;
        int replacements = 0;

        while (temp != nullptr) {
            size_t pos = 0;
            while ((pos = temp->line.find(oldWord, pos)) != string::npos) {
                temp->line.replace(pos, oldWord.length(), newWord);
                pos += newWord.length();
                replacements++;
            }
            temp = temp->next;
        }

        if (replacements > 0) {
            cout << "Replaced " << replacements << " occurrence(s) of '" << oldWord << "' with '" << newWord << "'." << endl;
        } else {
            cout << "No occurrences of '" << oldWord << "' found to replace." << endl;
        }
    }

    //Destructor to clean up memory
    ~TextEditor() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

//Main function
int main() {
    TextEditor editor;
    int choice;
    string input, oldWord, newWord;

    //Display menu once
    cout << "=== Simple Text Editor ===" << endl;
    cout << "Menu:" << endl;
    cout << "1. Add a line" << endl;
    cout << "2. View text" << endl;
    cout << "3. Search for a word" << endl;
    cout << "4. Replace a word" << endl;
    cout << "5. Exit" << endl;

    //Loop to accept user choices
    do {
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); //Ignore leftover newline from previous input

        switch (choice) {
            case 1:
                cout << "Enter a line to add: ";
                getline(cin, input);
                editor.addLine(input);
                break;

            case 2:
                cout << "Current text:" << endl;
                editor.displayText();
                break;

            case 3:
                cout << "Enter the word to search: ";
                getline(cin, input);
                editor.searchWord(input);
                break;

            case 4:
                cout << "Enter the word to replace: ";
                getline(cin, oldWord);
                cout << "Enter the new word: ";
                getline(cin, newWord);
                editor.replaceWord(oldWord, newWord);
                break;

            case 5:
                cout << "Exiting text editor. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
