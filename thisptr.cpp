#include <iostream>
using namespace std;

class Student {
    string name;
    int age;

public:
    void setData(string name, int age) {
        this->name = name;   // this pointer refers to class variable
        this->age = age;
    }

    void display() {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
    }
};

int main() {
    Student s1;

    s1.setData("Saphal", 18);
    s1.display();

    return 0;
}