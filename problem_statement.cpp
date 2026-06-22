#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    // Static: shared across ALL objects
    static int totalCount;  // one copy for the whole class

    // Normal: each object owns its own copy
    string name;             // unique per object
    int rollNumber;        // unique per object

    Student(string n, int r) : name(n), rollNumber(r) {
        ++totalCount; // increments the SHARED counter
    }
    ~Student() { --totalCount; }
};

// Definition outside class (required for static)
int Student::totalCount = 0;

int main() {
    Student s1("safal", 101);
    Student s2("ram", 102);
    cout << Student::totalCount; // 2
    { Student s3("shyam", 103); } // destroyed here
    cout << Student::totalCount; // back to 2
}