#ifndef STACKCPP
#define STACKCPP
#include "Stack.h"

template<class T>
void Stack<T>::extendDataArray() {
    T* newArray = new T[capacity * 2];
    for (int i = 0; i < capacity; ++i) {
        newArray[i] = stack[i];
    }
    delete[]stack;
    stack = newArray;
    capacity *= 2;
}

template<class T>
Stack<T>::Stack() {
    capacity = 1024;
    stack = new T[capacity];
    top = -1;
}

template<class T>
Stack<T>::Stack(const Stack& st) {
    top = st.top;
    capacity = st.capacity;
    stack = new T[capacity];
    for (int i = 0; i <= st.top; i++)
    {
        stack[i] = st.stack[i];
    }
}

template<class T>
int Stack<T>::getSize() const {
    return top + 1;
}

template<class T>
bool Stack<T>::isEmpty() const{
    return top == -1;
}

template<class T>
void Stack<T>::Push(const T& value) {
    if (top + 1 == capacity) {
        extendDataArray();
    }
    stack[++top] = value;
}


template<class T>
T Stack<T>::Top()
{
    if (!isEmpty())
        return stack[top];
    else
        exit(EXIT_FAILURE);
}

template<class T>
T Stack<T>::Pop()
{
    if (isEmpty())
        throw std::exception("Pop: Stack is empty");
    T pastTop = stack[top];
    --top;
    return pastTop;
}

template<class T>
bool Stack<T>::operator==(const Stack& a)
{
    if (a.getSize() == getSize())
        for (int i = 0; i < a.getSize(); i++)
            if (a.stack[i] != stack[i])
                return false;
            else
                return false;
    return true;
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& st) {
    if (this == &st)
    {
        return *this;
    }
    delete[] stack;
    top = st.top;
    capacity = st.capacity;
    stack = new T[st.capacity];
    for (int i = 0; i <= st.top; i++)
    {
        stack[i] = st.stack[i];
    }
    return *this;
}

template<class T>
void Stack<T>::operator>> (T value) {
    Push(value);
}


template<class T>
void Stack<T>::operator<< (T& value) {
    value = Pop();
}

template<class T>
int Stack<T>::operator[] (int i) {
    return stack[i];
}

template<class T>
bool Stack<T>::operator< (const Stack& a){
    return getSize() < a.getSize();
}

template<class T>
bool Stack<T>::operator> (const Stack& a){
    return getSize() > a.getSize();
}

template<class T>
Stack<T>::~Stack() {
    delete[] stack;
}

#endif