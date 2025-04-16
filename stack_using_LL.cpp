#include <iostream>
using namespace std;

// Node structure for stack
struct StackNode {
    int data;
    StackNode* next;

    // Constructor to initialize node
    StackNode(int x) {
        data = x;
        next = nullptr;
    }
};

// Stack class using linked list
class Stack {
private:
    StackNode* top; // Pointer to the top of the stack
    int size;       // Variable to keep track of stack size

public:
    // Constructor
    Stack() {
        top = nullptr;
        size = 0;
    }

    // Function to push an element onto the stack
    void push(int x) {
        StackNode* newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
        size++;
        cout << "Pushed: " << x << "\n";
    }

    // Function to pop an element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return;
        }
        StackNode* temp = top;
        top = top->next;
        cout << "Popped: " << temp->data << "\n";
        delete temp;
        size--;
    }

    // Function to return the top element of the stack
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to get the size of the stack
    int getSize() {
        return size;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
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