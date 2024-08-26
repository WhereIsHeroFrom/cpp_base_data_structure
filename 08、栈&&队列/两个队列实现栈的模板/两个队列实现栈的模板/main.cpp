#include <iostream>
using namespace std;

template<typename T>
class Queue {
private:
    T* data;
    int front;
    int rear;
    int capacity;
    void resize();

public:
    Queue() : data(new T[10]), front(0), rear(0), capacity(10) {}
    ~Queue();
    void enqueue(T element);
    T dequeue();
    T getFront() const;
    int getSize() const;
    bool empty() const;
};

template<typename T>
void Queue<T>::resize() {
    T* newData = new T[capacity * 2];
    for (int i = 0; i < rear; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity *= 2;
}

template<typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template<typename T>
void Queue<T>::enqueue(T element) {
    if (rear == capacity) {
        resize();
    }
    data[rear++] = element;
}

template<typename T>
T Queue<T>::dequeue() {
    if (front == rear) {
        throw std::underflow_error("Queue is empty");
    }
    T element = data[front++];
    return element;
}

template<typename T>
T Queue<T>::getFront() const {
    if (front == rear) {
        throw std::underflow_error("Queue is empty");
    }
    return data[front];
}

template<typename T>
int Queue<T>::getSize() const {
    return rear - front;
}


template<typename T>
bool Queue<T>::empty() const {
    return getSize() == 0;
}

class MyStack {
private:
    Queue<int> q1;
    Queue<int> q2;

public:
    MyStack() {}

    void push(int x) {
        q1.enqueue(x);
    }
    int pop() {
        while (q1.getSize() > 1) {
            q2.enqueue(q1.dequeue());
        }
        int result = q1.dequeue();
        while (!q2.empty()) {
            q1.enqueue(q2.dequeue());
        }
        return result;
    }
    int top() {
        while (q1.getSize() > 1) {
            q2.enqueue(q1.dequeue());
        }
        int result = q1.dequeue();
        q2.enqueue(result);
        while (!q2.empty()) {
            q1.enqueue(q2.dequeue());
        }
        return result;
    }
    bool empty() {
        return q1.empty();
    }
};

int main() {
    return 0;
}