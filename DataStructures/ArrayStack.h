#pragma once
#include <iostream>
#include "StackADT.h"
using namespace std;

// ============================================================
// Array-based implementation of StackADT
// ============================================================

template <typename T>
class ArrayStack : public StackADT<T> {
private:
    int top;
    int maxSize;
    T* items;

public:
    ArrayStack(int size = 100) {
        maxSize = size;
        items = new T[maxSize];
        top = -1;
    }

    ~ArrayStack() override {
        delete[] items;
    }

    bool isEmpty() const override {
        return top == -1;
    }

    bool isFull() const override {
        return top == maxSize - 1;
    }

    bool push(const T& newItem) override {
        if (isFull()) return false;
        items[++top] = newItem;
        return true;
    }

    bool pop(T& stackTop) override {
        if (isEmpty()) return false;
        stackTop = items[top--];
        return true;
    }

    bool peek(T& stackTop) const override {
        if (isEmpty()) return false;
        stackTop = items[top];
        return true;
    }

    void print() const {
        cout << "Stack (bottom -> top): ";
        for (int i = 0; i <= top; i++)
            cout << items[i] << " ";
        cout << endl;
    }
};