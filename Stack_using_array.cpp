#include <iostream>
using namespace std;

#define MAX 100  // Maximum size of stack

class Stack {
private:
    int arr[MAX];  // Array to store stack elements
    int top;       // Top index

public:    // Constructor
    Stack() {
        top = -1;  // Initialize stack as empty
    }

    // Function to push an element onto the stack
    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot push " << x << "\n";
            return;
        }
        arr[++top] = x;
        cout << "Pushed: " << x << "\n";
    }

    // Function to pop an element from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return;
        }
        cout << "Popped: " << arr[top--] << "\n";
    }

    // Function to return the top element of the stack
    int peek() {
        if (top < 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top < 0;
    }

    // Function to get the size of the stack
    int getSize() {
        return top + 1;
    }
};

// Driver code
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << "\n";

    s.pop();
    cout << "Stack size: " << s.getSize() << "\n";

    s.pop();
    s.pop();
    s.pop(); // Attempting to pop from an empty stack

    return 0;
}