#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(NULL) {}
    };

    Node* head;
    int size;

public:
    Stack() : head(NULL), size(0) {}
    ~Stack();
    void push(T element);
    T pop();
    T top() const;
    int getSize() const;
};

template<typename T>
Stack<T>::~Stack() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void Stack<T>::push(T element) {
    Node* newNode = new Node(element);
    newNode->next = head;
    head = newNode;
    ++size;
}

template<typename T>
T Stack<T>::pop() {
    if (head == NULL) {
        throw std::underflow_error("Stack is empty");
    }
    T result = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    --size;
    return result;
}

template<typename T>
T Stack<T>::top() const {
    if (head == NULL) {
        throw std::underflow_error("Stack is empty");
    }
    return head->data;
}

template<typename T>
int Stack<T>::getSize() const {
    return size;
}

int main() {
    Stack<int> st;
    st.push(4);
    st.push(7);
    st.push(13);
    cout << st.top() << endl;
    st.push(17);
    cout << st.top() << endl;
    st.pop();
    st.pop();
    cout << st.top() << endl;
    cout << st.getSize() << endl;

    return 0;
}