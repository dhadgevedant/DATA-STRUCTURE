/******************************************************************************

Student Management System (using Hash Table)
------------------------------------------------
Brief process:
1. Create a `student` class to store student details (PRN, Name, Address, Percentage).
2. Use two vectors:
    - `mykey` to store PRNs (keys).
    - `mychain` (not used here meaningfully) - kept as placeholder.
3. Accept 'n' students and insert them into the hash table using linear probing.
4. Display the hash table showing PRN, Name, Address, and Percentage for each student.
5. Hash function: PRN % 10 is used to determine the index.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string name, address;
    int prn, percentage;
    vector<int> mykey;
    vector<int> mychain; // Placeholder, not actually used here

public:
    Student() {
        prn = -1;
        percentage = 0;
        name = address = "";
        mykey = vector<int>(10, -1);
        mychain = vector<int>(10, -2);
    }

    void accept();
    void displayTable();
} H[10];

void Student::accept() {
    int n;
    cout << "Enter the number of records: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Student s;
        cout << "\nEnter PRN: ";
        cin >> s.prn;
        cout << "Enter Name: ";
        cin >> s.name;
        cout << "Enter Address: ";
        cin >> s.address;
        cout << "Enter Percentage: ";
        cin >> s.percentage;

        int index = s.prn % 10;
        int start = index;

        while (mykey[index] != -1) {
            index = (index + 1) % 10;
            if (index == start) {
                cout << "Hash table is full.\n";
                return;
            }
        }

        mykey[index] = s.prn;
        H[index] = s;
    }
}

void Student::displayTable() {
    cout << "\nIndex\tPRN\tName\t\tAddress\t\tPercentage\n";
    for (int i = 0; i < 10; i++) {
        if (mykey[i] != -1) {
            cout << i << "\t" << H[i].prn << "\t" << H[i].name
                 << "\t\t" << H[i].address << "\t\t" << H[i].percentage << "\n";
        } else {
            cout << i << "\t \t \t\t \t\t \n";
        }
    }
}

int main() {
    Student s;
    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Accept Student Details\n";
        cout << "2. Display Hash Table\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.accept();
                break;
            case 2:
                s.displayTable();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
    return 0;

}

