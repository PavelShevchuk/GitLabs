#ifndef STUDENT
#define STUDENT
#include <iostream>

class Student{
protected:
    static int nextID;
    const char* name;
    const int ID;
    int group, course, recordBookNumber;
    Student() : ID(++nextID) {};  //запрет вызова конструктора без параметра
public:
    Student(const char* name, int group, int course, int recordBookNumber);
    Student(const Student& student);
    void setGroup(int x);
    void setCourse(int x);
    int getGroup() const;
    int getCourse() const;
    const char* getname() const;
    int getID() const;
    int getRecordBookNumber() const;
    friend std::ostream& operator<< (std::ostream& out, const Student& student);
    virtual float getAverageScore() const;
};

#endif // !STUDENT