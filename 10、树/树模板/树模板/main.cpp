#include <iostream>
using namespace std;

template<typename T>
struct ListNode {
    T data;
    ListNode* next;
    ListNode(T d) : data(d), next(NULL) {}
};

template<typename T>
struct TreeNode {
    T data;
    ListNode<TreeNode<T>*>* childrenHead;

    TreeNode() {
        data = T();
        childrenHead = NULL;
    }

    void AddChild(TreeNode<T>* node) {
        ListNode<TreeNode<T>*>* childNode = new ListNode<TreeNode<T>*>(node);
        if (childrenHead == NULL) {
            childrenHead = childNode;
        }
        else {
            childNode->next = childrenHead;
            childrenHead = childNode;
        }
    }
};

template<typename T>
class Tree {
private:
    TreeNode<T>* nodes;
    TreeNode<T>* root;
public:
    Tree();
    Tree(int maxNodes);
    ~Tree();
    TreeNode<T>* GetTreeNode(int id);
    void SetRoot(int rootId);
    void AddChild(int parentId, int sonId);
    void AssignData(int nodeId, T data);
    void Print(TreeNode<T>* node = NULL);
};

template<typename T>
Tree<T>::Tree() {
    nodes = new TreeNode<T>[100001];
    root = NULL;
}

template<typename T>
Tree<T>::Tree(int maxNodes) {
    nodes = new TreeNode<T>[maxNodes];
    root = NULL;
}

template<typename T>
Tree<T>::~Tree() {
    delete[] nodes;
}

template<typename T>
TreeNode<T>* Tree<T>::GetTreeNode(int id) {
    return &nodes[id];
}

template<typename T>
void Tree<T>::SetRoot(int id) {
    root = GetTreeNode(id);
}

template<typename T>
void Tree<T>::AddChild(int parentId, int sonId) {
    TreeNode<T>* parentNode = GetTreeNode(parentId);
    TreeNode<T>* sonNode = GetTreeNode(sonId);
    parentNode->AddChild(sonNode);
}

template<typename T>
void Tree<T>::AssignData(int id, T data) {
    GetTreeNode(id)->data = data;
}

template<typename T>
void Tree<T>::Print(TreeNode<T>* node) {
    if (node == NULL) {
        node = root;
    }
    cout << node->data;
    ListNode<TreeNode<char>*>* tmp = node->childrenHead;
    while (tmp) {
        Print(tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    Tree<char> T(9);
    T.SetRoot(0);
    T.AssignData(0, 'a');
    T.AssignData(1, 'b');
    T.AssignData(2, 'c');
    T.AssignData(3, 'd');
    T.AssignData(4, 'e');
    T.AssignData(5, 'f');
    T.AssignData(6, 'g');
    T.AssignData(7, 'h');
    T.AssignData(8, 'i');

    T.AddChild(0, 2);
    T.AddChild(0, 1);
    T.AddChild(1, 3);
    T.AddChild(2, 5);
    T.AddChild(2, 4);
    T.AddChild(3, 8);
    T.AddChild(3, 7);
    T.AddChild(3, 6);

    T.Print();

    return 0;
}