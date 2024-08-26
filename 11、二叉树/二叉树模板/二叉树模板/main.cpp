#include <iostream>
using namespace std;

template<typename T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

template<typename T>
class Tree {
private:
    TreeNode<T>* nodes;
    TreeNode<T>* root;
    size_t nodeSize;

    TreeNode<T>* Create(T a[], int size, int nodeId, T nullNode);
    void visit(TreeNode<T>* node);
    void preOrder(TreeNode<T>* node);
    void inOrder(TreeNode<T>* node);
    void postOrder(TreeNode<T>* node);
public:
    Tree();
    Tree(int maxNodes);
    ~Tree();
    TreeNode<T>* GetTreeNode(int id);
    void CreateTree(T a[], int size, T nullNode);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
};

template<typename T>
Tree<T>::Tree() {
    nodeSize = 100001;
    root = NULL;
    nodes = new TreeNode<T>[nodeSize];
}

template<typename T>
Tree<T>::Tree(int maxNodes) {
    nodeSize = maxNodes;
    root = NULL;
    nodes = new TreeNode<T>[nodeSize];
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
void Tree<T>::visit(TreeNode<T>* node) {
    cout << node->val;
}

template<typename T>
TreeNode<T>* Tree<T>::Create(T a[], int size, int nodeId, T nullNode) {
    if (nodeId >= size || a[nodeId] == nullNode) {
        return NULL;
    }
    TreeNode<T>* nowNode = GetTreeNode(nodeId);
    nowNode->val = a[nodeId];
    nowNode->left = Create(a, size, nodeId * 2, nullNode);
    nowNode->right = Create(a, size, nodeId * 2 + 1, nullNode);
    return nowNode;
}

template<typename T>
void Tree<T>::CreateTree(T a[], int size, T nullNode) {
    root = Create(a, size, 1, nullNode);
}

template<typename T>
void Tree<T>::preOrder(TreeNode<T>* node) {
    if (node) {
        visit(node);
        preOrder(node->left);
        preOrder(node->right);
    }
}

template<typename T>
void Tree<T>::preOrderTraversal() {
    preOrder(root);
}

template<typename T>
void Tree<T>::inOrder(TreeNode<T>* node) {
    if (node) {
        inOrder(node->left);
        visit(node);
        inOrder(node->right);
    }
}

template<typename T>
void Tree<T>::inOrderTraversal() {
    inOrder(root);
}

template<typename T>
void Tree<T>::postOrder(TreeNode<T>* node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        visit(node);
    }
}

template<typename T>
void Tree<T>::postOrderTraversal() {
    postOrder(root);
}

int main()
{
    const char nullNpde = '-';
    char a[15] = {
        nullNpde, 'a', 'b', 'c', 'd',
        nullNpde, 'e', 'f', 'g', 'h',
        nullNpde, nullNpde, nullNpde, nullNpde, 'i'
    };

    Tree<char> T(15);
    T.CreateTree(a, 15, nullNpde);
    T.preOrderTraversal(); cout << endl;
    T.inOrderTraversal(); cout << endl;
    T.postOrderTraversal(); cout << endl;

    return 0;
}