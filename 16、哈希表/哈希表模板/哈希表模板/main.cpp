#include <iostream>
using namespace std;

// 哈希表节点类
template<typename KeyType, typename ValueType>
class HashNode {
public:
    KeyType key;
    ValueType value;
    HashNode* next;

    HashNode(const KeyType& key, const ValueType& value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

// 哈希表类
template<typename KeyType, typename ValueType>
class HashTable {
private:
    int size;
    HashNode<KeyType, ValueType>** table;

    // 哈希函数
    int hash(const KeyType& key) const {
        int hashkey = key % size;
        if (hashkey < 0) hashkey += size;
        return hashkey;
    }

public:
    // 构造函数，初始化哈希表的大小
    HashTable(int size = 1000);
    // 析构函数，释放动态分配的内存
    ~HashTable();
    // 在哈希表中插入键值对
    void insert(const KeyType& key, const ValueType& value);
    // 从哈希表中删除键值对
    void remove(const KeyType& key);
    // 在哈希表中查找指定键的值
    bool find(const KeyType& key, ValueType& value) const;
};

template<typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::HashTable(int size) {
    this->size = size;
    this->table = new HashNode<KeyType, ValueType>* [size];
    for (int i = 0; i < size; i++) {
        table[i] = NULL;
    }
}

template<typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::~HashTable() {
    for (int i = 0; i < size; i++) {
        if (table[i]) {
            HashNode<KeyType, ValueType>* current = table[i];
            while (current) {
                HashNode<KeyType, ValueType>* next = current->next;
                delete current;
                current = next;
            }
        }
    }
    delete[] table;
}

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
    int index = hash(key);
    HashNode<KeyType, ValueType>* now = new HashNode<KeyType, ValueType>(key, value);
    if (table[index] == NULL) {
        table[index] = now;
    }
    else {
        now->next = table[index];
        table[index] = now;
    }
}

template<typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::remove(const KeyType& key) {
    int index = hash(key);
    if (table[index]) {
        if (table[index]->key == key) {
            HashNode<KeyType, ValueType>* next = table[index]->next;
            delete table[index];
            table[index] = next;
        }
        else {
            HashNode<KeyType, ValueType>* current = table[index];
            while (current->next && current->next->key != key) {
                current = current->next;
            }
            if (current->next) {
                HashNode<KeyType, ValueType>* next = current->next->next;
                delete current->next;
                current->next = next;
            }
        }
    }
}

template<typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::find(const KeyType& key, ValueType& value) const {
    int index = hash(key);
    if (table[index]) {
        if (table[index]->key == key) {
            value = table[index]->value;
            return true;
        }
        else {
            HashNode<KeyType, ValueType>* current = table[index];
            while (current->next && current->next->key != key) {
                current = current->next;
            }
            if (current->next) {
                value = current->next->value;
                return true;
            }
        }
    }
    return false;
}

int main() {
    HashTable<int, char> h(10000);
    h.insert(1, 'a');
    h.insert(2, 'b');
    h.insert(3, 'c');
    h.insert(41012012, 'd');

    char val;
    if (!h.find(43, val)) {
        cout << "43 not found!" << endl;
    }
    if (h.find(41012012, val)) {
        cout << "41012012 found, value is " << val << endl;
    }
    return 0;
}