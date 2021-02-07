#ifndef STUDENTAFTERSECONDSESSION
#define STUDENTAFTERSECONDSESSION

#include "StudentAfterFirstSession.h"

class StudentAfterSecondSession : public StudentAfterFirstSession{
protected:
    int* grades2;
    StudentAfterSecondSession() {};
public:
    StudentAfterSecondSession(const char* name, int group, int course, int recordBookNumber, int* grades1, int* grades2);
    StudentAfterSecondSession(const StudentAfterSecondSession& student);
    void setGrades2(int* grades2);
    int* getGrades2() const;
    friend std::ostream& operator<< (std::ostream& out, const StudentAfterSecondSession& student);
    float getAverageScore() const;
};

#endif
