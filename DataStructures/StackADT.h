#pragma once
#include <iostream>
using namespace std;

// ============================================================
// Abstract Base Class (Interface) for Stack ADT
// ============================================================

template <typename T>
class StackADT {
public:
    // Virtual destructor for proper cleanup
    virtual ~StackADT() {}


    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual bool push(const T& newItem) = 0;
    virtual bool pop(T& stackTop) = 0;
    virtual bool peek(T& stackTop) const = 0;
};