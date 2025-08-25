#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack {
   private:
    int top;
    int capacity;
    T* arr;

   public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }
    ~Stack() { delete[] arr; }
    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
        } else {
            arr[++top] = value;
        }
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
        } else {
            top--;
        }
    }
    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return T();
        }
        return arr[top];
    }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == capacity - 1; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Stack<int> s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.peek() << endl;
    s.pop();
    cout << "Top after pop: " << s.peek() << endl;
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    while (!s.isEmpty()) {
        cout << "Popping: " << s.peek() << endl;
        s.pop();
    }
    s.pop();
    return 0;
}
