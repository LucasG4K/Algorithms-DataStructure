#ifndef METHODS_HPP 
#define METHODS_HPP

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

template <typename T>
class Sequence {
private:
    Node<T>* begin;
    Node<T>* end;
public:
    Sequence();
    void Insert(T value);
    void Print();
    T queueLeave();
    T stackPop();
    T listRemove(T value);
};

#endif