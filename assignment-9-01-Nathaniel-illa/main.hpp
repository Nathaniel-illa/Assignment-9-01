#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int N = 5;

struct Student {
    int id;
    string name;
    string major;
};

void makeStudent(Student *student);
void printStudent(Student *student);

void makeStudent(Student *student) {
    ifstream infile("students.txt");
    if (!infile) {
        cerr << "Error opening file!" << endl;
        return;
    }
    for (Student *ptr = student; ptr < student + N; ++ptr) {
        infile >> ptr->id >> ptr->name >> ptr->major;
    }
    infile.close();
}

void printStudent(Student *student) {
    cout << "Student Information:" << endl;
    for (Student *ptr = student; ptr < student + N; ++ptr) {
        cout << "ID: " << ptr->id << ", Name: " << ptr->name << ", Major: " << ptr->major << endl;
    }
}
