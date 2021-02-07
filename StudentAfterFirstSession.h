#ifndef STUDENTAFTERFIRSTSESSION
#define STUDENTAFTERFIRSTSESSION

#include "student.h"

class StudentAfterFirstSession : public Student{
protected:
    int* grades1;
    StudentAfterFirstSession() {};
public:
    StudentAfterFirstSession(const char* name, int group, int course, int recordBookNumber, int* grades1);
    StudentAfterFirstSession(const StudentAfterFirstSession& student);
    void setGrades1(int* grades1);
    int* getGrades1() const;
    friend std::ostream& operator<< (std::ostream& out, const StudentAfterFirstSession& student);
    float getAverageScore() const;
};

#endif // !STUDENTAFTERFIRSTSESSION
