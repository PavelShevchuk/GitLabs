#include "StudentAfterFirstSession.h"

StudentAfterFirstSession::StudentAfterFirstSession(const char* name, int group, int course, int recordBookNumber, int* grades1){
    this->name = name;
    this->group = group;
    this->course = course;
    this->recordBookNumber = recordBookNumber;
    this->grades1 = grades1;
}

StudentAfterFirstSession::StudentAfterFirstSession(const StudentAfterFirstSession& student){
    name = student.name;
    group = student.group;
    course = student.course;
    recordBookNumber = student.recordBookNumber;
    grades1 = student.grades1;
}

void StudentAfterFirstSession::setGrades1(int* grades1) {
    this->grades1 = grades1;
}

int* StudentAfterFirstSession::getGrades1() const {
    return grades1;
}

std::ostream& operator<< (std::ostream& out, const StudentAfterFirstSession& student) {
    out << "ID: " << student.ID << "\nname: " << student.name << "\ncourse: " << student.course << "\ngroup: " << student.group <<
        "\nrecord book number: " << student.recordBookNumber << "\nfirst session grades: " << student.grades1[0] << " " << student.grades1[1] << " " <<
        student.grades1[2] << " " << student.grades1[3] << '\n';
    return out;
}

float StudentAfterFirstSession::getAverageScore() const {
    return (float)(grades1[0] + grades1[1] + grades1[2] + grades1[3]) / 4;
}
