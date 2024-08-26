#include <iostream>
#include <stdexcept>

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

int main() {
    Queue<int> q;
    q.enqueue(3);
    q.enqueue(4);
    cout << q.getFront() << endl;
    q.enqueue(5);
    cout << q.getFront() << endl;
    q.dequeue();
    cout << q.getFront() << endl;
    cout << q.getSize() << endl;
    return 0;
}