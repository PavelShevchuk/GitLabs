#ifndef STACK
#define STACK

#include <iostream>

template <class T>
class Stack {
private:
    T* stack;
    int top;
    int capacity;
    void extendDataArray();
public:
    Stack<T>();
    Stack<T>(const Stack& st);
    int getSize() const;
    bool isEmpty() const;
    void Push(const T& value);
    T Top();
    T Pop();
    bool operator==(const Stack& a);
    Stack& operator= (const Stack& st);
    void operator>> (T value);
    void operator<< (T& value);
    int operator[] (int i);
    bool operator< (const Stack& a);
    bool operator> (const Stack& a);
    ~Stack<T>();
};

#include "Stack.cpp"

#endif
