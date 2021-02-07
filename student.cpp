#include "student.h"

int Student::nextID = 0;
Student::Student(const char* name, int group, int course, int recordBookNumber) : ID(++nextID){
    this->name = name;
    this->group = group;
    this->course = course;
    this->recordBookNumber = recordBookNumber;
}

Student::Student(const Student& student) : ID(student.ID){
    name = student.name;
    group = student.group;
    course = student.course;
    recordBookNumber = student.recordBookNumber;
}

void Student::setGroup(int x) {
    group = x;
}

void Student::setCourse(int x) {
    course = x;
}

int Student::getGroup() const {
    return group;
}

int Student::getCourse() const {
    return course;
}

const char* Student::getname() const {
    return name;
}

int Student::getID() const {
    return ID;
}

int Student::getRecordBookNumber() const {
    return recordBookNumber;
}

std::ostream& operator<< (std::ostream& out, const Student& student) {
    out << "ID: " << student.ID << "\nname: " << student.name << "\ncourse: " << student.course << "\ngroup: " << student.group <<
        "\nrecord book number: " << student.recordBookNumber << '\n';
    return out;
}

float Student::getAverageScore() const {
    return 0;
}
