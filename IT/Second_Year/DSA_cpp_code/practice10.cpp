#include <iostream>
#include <fstream>
using namespace std;

class stud {
public:
    int rollno;
    string name;
    int div;
};

class f_stud {
public:
    fstream f;
    stud s;

    void create();
    void display();
    void search();
    void deleteRecord();
    void deleteFile();
    void addRecord();
};

void f_stud::create() {
    f.open("STUD", ios::out | ios::binary);

    if (!f.is_open()) {
        cout << "Error opening file!" << endl;
        exit(0);
    }

    for (int i = 0; i < 2; i++) {
        cout << "Name\t Roll no\t Div\t" << endl;

        cin >> s.name;
        cin >> s.rollno;
        cin >> s.div;

        f.write((char*)&s, sizeof(s));
    }
    f.close();
}

void f_stud::display() {
    f.open("STUD", ios::in | ios::binary);

    if (!f.is_open()) {
        cout << "Error opening file!" << endl;
        exit(0);
    }

    while (f.read((char*)&s, sizeof(s))) {
        cout << "Name\t Roll no\t Div" << endl;
        cout << s.name << "\t" << s.rollno << "\t" << s.div << endl;
    }
    f.close();
}

void f_stud::search() {
    int roll;
    cout << "Enter roll no you want to search: ";
    cin >> roll;

    f.open("STUD", ios::in | ios::binary);

    if (!f.is_open()) {
        cout << "Error opening file!" << endl;
        exit(0);
    }

    bool found = false;
    while (f.read((char*)&s, sizeof(s))) {
        if (s.rollno == roll) {
            cout << "Record found: " << s.rollno << "\t" << s.name << "\t" << s.div << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found" << endl;
    }

    f.close();
}

void f_stud::deleteRecord() {
    int roll;
    cout << "Enter roll no you want to delete: ";
    cin >> roll;

    f.open("STUD", ios::in | ios::binary);
    ofstream tempfile("tempStud", ios::out | ios::binary);

    if (!f.is_open() || !tempfile.is_open()) {
        cout << "Error opening file!" << endl;
        exit(0);
    }

    bool found = false;
    while (f.read((char*)&s, sizeof(s))) {
        if (s.rollno != roll) {
            tempfile.write((char*)&s, sizeof(s));
        } else {
            found = true;
        }
    }

    f.close();
    tempfile.close();

    if (found) {
        if (remove("STUD") != 0 || rename("tempStud", "STUD") != 0) {
            cout << "Error deleting record" << endl;
        } else {
            cout << "Record deleted successfully" << endl;
        }
    } else {
        cout << "Record not found" << endl;
        remove("tempStud");
    }
}

void f_stud::deleteFile() {
    if (remove("STUD") != 0) {
        cout << "Error deleting file" << endl;
    } else {
        cout << "File deleted successfully" << endl;
    }
}

void f_stud::addRecord() {
    f.open("STUD", ios::app | ios::binary);

    if (!f.is_open()) {
        cout << "Error opening file!" << endl;
    } else {
        cout << "Name\t Roll no\t Div\t" << endl;

        cin >> s.name;
        cin >> s.rollno;
        cin >> s.div;

        f.write((char*)&s, sizeof(s));
        f.close();
    }
}

int main() {
    f_stud s1;
    int ch = 0;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Create records\n";
        cout << "2. Display records\n";
        cout << "3. Search record\n";
        cout << "4. Delete record\n";
        cout << "5. Delete entire file\n";
        cout << "6. Add record\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                s1.create();
                break;
            case 2:
                cout << "Output" << endl;
                s1.display();
                break;
            case 3:
                s1.search();
                break;
            case 4:
                s1.deleteRecord();
                break;
            case 5:
                s1.deleteFile();
                break;
            case 6:
                s1.addRecord();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != 7);

    return 0;
}
