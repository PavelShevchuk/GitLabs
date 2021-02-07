#include "StudentAfterSecondSession.h"

StudentAfterSecondSession::StudentAfterSecondSession(const char* name, int group, int course, int recordBookNumber, int* grades1, int*grades2) {
    this->name = name;
    this->group = group;
    this->course = course;
    this->recordBookNumber = recordBookNumber;
    this->grades1 = grades1;
    this->grades2 = grades2;
}

StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterSecondSession& student) {
    name = student.name;
    group = student.group;
    course = student.course;
    recordBookNumber = student.recordBookNumber;
    grades1 = student.grades1;
    grades2 = student.grades2;
}

void StudentAfterSecondSession::setGrades2(int* grades2) {
    this->grades2 = grades2;
}

int* StudentAfterSecondSession::getGrades2() const {
    return grades2;
}

std::ostream& operator<< (std::ostream& out, const StudentAfterSecondSession& student) {
    out << "ID: " << student.ID << "\nname: " << student.name << "\ncourse: " << student.course << "\ngroup: " << student.group <<
        "\nrecord book number: " << student.recordBookNumber << "\nfirst session grades: " << student.grades1[0] << " " << student.grades1[1] << " " <<
        student.grades1[2] << " " << student.grades1[3] << "\nsecond session grades: " << student.grades2[0] << " " << student.grades2[1] << " " <<
        student.grades2[2] << " " << student.grades2[3] << " " << student.grades2[4] << "\n";
    return out;
}

float StudentAfterSecondSession::getAverageScore() const {
    return (float)(grades1[0] + grades1[1] + grades1[2] + grades1[3] + grades2[0] + grades2[1] + grades2[2] + grades2[3] + grades2[4]) / 9;
}
