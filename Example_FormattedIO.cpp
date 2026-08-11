class Student{
private:
string name;
int age;
float marks;
public:
// Function to assign student data
void setData(string n, int a, float m){
name = n;
age = a;
marks = m;
}
// Function to display student data
void display(){
cout << "Name : " << name << endl;
cout << "Age : " << age << endl;
cout << "Marks : " << marks << endl;
// Formatted File Output
void writeFormatted(){
ofstream file("student2.txt");
file << name << " " << age << " " << marks << endl;
file.close();
// Formatted File Input
void readFormatted(){
ifstream file("student2.txt");
file >> name >> age>> marks;
file.close();
}
}
}
};

int main(){
Student s;
// Store data in object
s.setData("Ram", 20, 85.5);
// -----------------------------
// FORMATTED OUTPUT
// -----------------------------
s.writeFormatted();
// Clear/change object data
s.setData("", 0, 0);
// -----------------------------
// FORMATTED INPUT
// -----------------------------
s.readFormatted();
cout << "Formatted Input:" << endl;
s.display();
return 0;
}
