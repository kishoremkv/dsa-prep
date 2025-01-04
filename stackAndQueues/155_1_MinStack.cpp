#include <iostream>
#include <climits> // For INT_MAX

class MinStack {
private:
    int a[1000];       // Array to store stack elements
    int min[1000];     // Array to store minimum elements
    int topIndex;      // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    MinStack() {
        topIndex = -1; // Empty stack
    }

    // Push operation
    void push(int val) {
        if (topIndex < 999) { // Check for stack overflow
            topIndex++;
            a[topIndex] = val;
            if (topIndex == 0) {
                min[topIndex] = val; // First element is the minimum
            } else {
                min[topIndex] = std::min(val, min[topIndex - 1]); // Update the minimum
            }
        } else {
            std::cout << "Stack Overflow" << std::endl;
        }
    }

    // Pop operation
    void pop() {
        if (topIndex >= 0) { // Check for stack underflow
            topIndex--;
        } else {
            std::cout << "Stack Underflow" << std::endl;
        }
    }

    // Top operation
    int top() {
        if (topIndex >= 0) {
            return a[topIndex];
        } else {
            std::cout << "Stack is empty" << std::endl;
            return INT_MIN; // Return an invalid value for empty stack
        }
    }

    // GetMin operation
    int getMin() {
        if (topIndex >= 0) {
            return min[topIndex];
        } else {
            std::cout << "Stack is empty" << std::endl;
            return INT_MIN; // Return an invalid value for empty stack
        }
    }
};
