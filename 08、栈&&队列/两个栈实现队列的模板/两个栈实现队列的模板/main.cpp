#include <iostream>
using namespace std;

template<typename T>
class Stack {
private:
    T* data;
    int size;
    int capacity;
    void resize();
public:
    Stack() : data(new T[10]), size(0), capacity(10) {}
    ~Stack();
    void push(T element);
    T pop();
    T top() const;
    int getSize() const;
    bool empty() const;
};

template<typename T>
void Stack<T>::resize() {
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] data;
}

template<typename T>
void Stack<T>::push(T element) {
    if (size == capacity) {
        resize();
    }
    data[size++] = element;
}

template<typename T>
T Stack<T>::pop() {
    if (size == 0) {
        throw std::underflow_error("Stack is empty");
    }
    return data[--size];
}

template<typename T>
T Stack<T>::top() const {
    if (size == 0) {
        throw std::underflow_error("Stack is empty");
    }
    return data[size - 1];
}

template<typename T>
int Stack<T>::getSize() const {
    return size;
}

template<typename T>
bool Stack<T>::empty() const {
    return size == 0;
}

class MyQueue {
private:
    Stack<int> s1;  // 入队栈
    Stack<int> s2;  // 出队栈

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int result = s2.top();
        s2.pop();
        return result;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    return 0;
}