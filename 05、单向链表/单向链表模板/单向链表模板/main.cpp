#include <iostream>
#include <stdexcept>

using namespace std;
#define eleType int

// ����ڵ�ṹ��
struct ListNode {
    eleType data;
    ListNode* next;
    ListNode(eleType x) : data(x), next(NULL) {}
};

// ����������
class LinkedList {
private:
    ListNode* head;
    int size;

public:

    LinkedList() : head(NULL), size(0) {}    // �����캯��
    ~LinkedList();
    void insert(int i, eleType value);       // ������ĵ� i ��λ�ã�����һ��ֵΪ value �Ľ��
    void remove(int i);                      // ɾ������� i ��λ�õĽ��    
    ListNode* find(eleType value);           // ����������ֵΪ value �Ľ��
    ListNode* get(int i);                    // ��ȡ�����е� i ��λ�õĽ��
    void update(int i, eleType value);       // �޸������е� i ��λ�õĽ���ֵΪ value
    void print();                            // ��ӡ��������
};

LinkedList::~LinkedList() {
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void LinkedList::insert(int i, eleType value) {
    if (i < 0 || i > size) {
        throw std::out_of_range("Invalid position");
    }
    ListNode* newNode = new ListNode(value);
    if (i == 0) {
        // �ڱ�ͷ����
        newNode->next = head;
        head = newNode;
    }
    else {
        ListNode* curr = head;
        for (int j = 0; j < i - 1; j++) {
            curr = curr->next;
        }
        // �ڵ� i ��λ�ò���
        newNode->next = curr->next;
        curr->next = newNode;
    }
    size++;
}

void LinkedList::remove(int i) {
    if (i < 0 || i >= size) {
        throw std::out_of_range("Invalid position");
    }
    if (i == 0) {
        // ɾ����ͷ���
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        ListNode* curr = head;
        for (int j = 0; j < i - 1; j++) {
            curr = curr->next;
        }
        // ɾ���� i �����
        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    size--;
}

ListNode* LinkedList::find(eleType value) {
    ListNode* curr = head;
    while (curr != NULL && curr->data != value) {
        curr = curr->next;
    }
    return curr;
}

ListNode* LinkedList::get(int i) {
    if (i < 0 || i >= size) {
        throw std::out_of_range("Invalid position");
    }
    ListNode* curr = head;
    for (int j = 0; j < i; j++) {
        curr = curr->next;
    }
    return curr;
}

void LinkedList::update(int i, eleType value) {
    if (i < 0 || i >= size) {
        throw std::out_of_range("Invalid position");
    }
    get(i)->data = value;
}

void LinkedList::print() {
    ListNode* curr = head;
    while (curr != NULL) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    LinkedList list;
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(3, 40);
    list.insert(4, 50);

    std::cout << "Initial list: ";
    list.print();

    std::cout << "Removing the second node: ";
    list.remove(1);
    list.print();

    std::cout << "Updating the third node to 60: ";
    list.update(2, 60);
    list.print();

    std::cout << "Finding the value of the fourth node: ";
    std::cout << list.find(30)->data << std::endl;

    std::cout << "Getting the third node: ";
    std::cout << list.get(2)->data << std::endl;

    return 0;
}
