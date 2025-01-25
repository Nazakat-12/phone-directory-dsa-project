/*  DSA Project
    BSCY-3B
    Telephone Directory
    Nazakat Ali BCYS -3B
*/

#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<string>
#include <cstdlib>

using namespace std;
ofstream outf;
ifstream myFileStream;

class contactNode {
    long long int number;
    char fname[20], lname[20], email[40];
    contactNode *left, *right;
    friend class tree;
};

class tree {
public:
    contactNode *root;

    tree() {
        root = NULL;
    }

    void createContact(contactNode *p) {
        contactNode *parent;
        contactNode *tmp = root;
        p->left = NULL;
        p->right = NULL;
        if (root == NULL) {
            root = p;
        } else {
            while (tmp != NULL) {
                parent = tmp;
                if (strcmp(p->fname, tmp->fname) < 0)
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
            if (strcmp(p->fname, parent->fname) < 0)
                parent->left = p;
            else
                parent->right = p;
        }
    }

    void addContact() {
        int valid = 0;
        contactNode *newContact = new contactNode();
        cout << "\nFirst Name: ";
        cin >> newContact->fname;
        cout << "\nLast Name: ";
        cin >> newContact->lname;
        do {
            cout << "\nPhone Number: ";
            cin >> newContact->number;
            valid = validateNumber(newContact->number);
        } while (!valid);
        do {
            cout << "\nEmail-ID: ";
            cin >> newContact->email;
            valid = validateEmail(newContact->email);
        } while (!valid);
        createContact(newContact);
        cout << "\nContact added successfully!";
    }

    int validateNumber(long long int number) {
        int digits = 0;
        while (number > 0) {
            digits++;
            number /= 10;
        }
        if (digits == 10) return 1;
        cout << "Invalid phone number. Please enter a 10-digit number.";
        return 0;
    }

    int validateEmail(char email[]) {
        int atSymbolCount = 0, i = 0;
        while (email[i] != '\0') {
            if (email[i] == '@') atSymbolCount++;
            i++;
        }
        if (atSymbolCount == 1) return 1;
        cout << "Invalid email address. Please enter a valid email.";
        return 0;
    }

    void displayContacts(contactNode *node) {
        if (node != NULL) {
            displayContacts(node->left);
            cout << "\nContact Details:";
            cout << "\nFirst Name: " << node->fname << "\tLast Name: " << node->lname;
            cout << "\nPhone Number: " << node->number << "\tEmail-ID: " << node->email;
            displayContacts(node->right);
        }
    }

    void showAllContacts() {
        if (root == NULL) {
            cout << "\nPhone directory is empty.";
        } else {
            displayContacts(root);
        }
    }

    contactNode *findMinNode(contactNode *node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    contactNode *deleteContact(contactNode *node, char fname[]) {
        if (node == NULL) return node;

        if (strcmp(fname, node->fname) < 0)
            node->left = deleteContact(node->left, fname);
        else if (strcmp(fname, node->fname) > 0)
            node->right = deleteContact(node->right, fname);
        else {
            if (node->left == NULL) {
                contactNode *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                contactNode *temp = node->left;
                delete node;
                return temp;
            }

            contactNode *temp = findMinNode(node->right);
            node->number = temp->number;
            strcpy(node->fname, temp->fname);
            strcpy(node->lname, temp->lname);
            strcpy(node->email, temp->email);
            node->right = deleteContact(node->right, temp->fname);
        }
        return node;
    }

    void searchContact(contactNode *node, char fname[]) {
        if (node != NULL) {
            if (strcmp(fname, node->fname) < 0)
                searchContact(node->left, fname);
            else if (strcmp(fname, node->fname) > 0)
                searchContact(node->right, fname);
            else {
                cout << "\nContact Details:";
                cout << "\nFirst Name: " << node->fname << "\tLast Name: " << node->lname;
                cout << "\nPhone Number: " << node->number << "\tEmail-ID: " << node->email;
                return;
            }
        } else {
            cout << "\nContact not found.";
        }
    }

    void saveContactsToFile(contactNode *node, ofstream &file) {
        if (node != NULL) {
            saveContactsToFile(node->left, file);
            file << node->fname << " " << node->lname << " " << node->number << " " << node->email << "\n";
            saveContactsToFile(node->right, file);
        }
    }

    void saveToFile() {
        outf.open("Contacts.txt", ios::trunc);
        saveContactsToFile(root, outf);
        outf.close();
    }

    void loadFromFile() {
        string fname, lname, email, line;
        long long number;

        myFileStream.open("Contacts.txt");
        if (!myFileStream.is_open()) {
            cout << "File failed to open or does not exist." << endl;
            return;
        }

        while (getline(myFileStream, line)) {
            contactNode *p = new contactNode();
            stringstream ss(line);

            getline(ss, fname, ' ');
            getline(ss, lname, ' ');
            ss >> number;
            ss.ignore();
            getline(ss, email, ' ');

            strcpy(p->fname, fname.c_str());
            strcpy(p->lname, lname.c_str());
            p->number = number;
            strcpy(p->email, email.c_str());

            createContact(p);
        }

        myFileStream.close();
    }
};

int main() {
    tree directory;
    directory.loadFromFile();
    cout << "\nPhone Directory Initialized Successfully\n";

    char choice;
    int option;
    char fname[20];

    do {
        cout << "\nMenu:\n1. Add Contact\n2. Delete Contact\n3. Search Contact\n4. Show All Contacts\n5. Exit\nChoose an option: ";
        cin >> option;

        switch (option) {
        case 1:
            directory.addContact();
            break;
        case 2:
            cout << "\nEnter First Name of Contact to Delete: ";
            cin >> fname;
            directory.root = directory.deleteContact(directory.root, fname);
            cout << "\nContact deleted successfully.";
            break;
        case 3:
            cout << "\nEnter First Name of Contact to Search: ";
            cin >> fname;
            directory.searchContact(directory.root, fname);
            break;
        case 4:
            directory.showAllContacts();
            break;
        case 5:
            cout << "\nExiting...";
            directory.saveToFile();
            break;
        default:
            cout << "\nInvalid Option. Try again.";
        }

        if (option != 5) {
            cout << "\nDo you want to continue? (y/n): ";
            cin >> choice;
        } else {
            choice = 'n';
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for using the Telephone Directory!\n";
    return 0;
}

