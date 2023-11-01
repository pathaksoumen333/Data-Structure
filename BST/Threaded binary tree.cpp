#include <iostream>
using namespace std;

class ThreadedNode {
public:
    int data;
    ThreadedNode* left;
    ThreadedNode* right;
    bool isThreaded;

    ThreadedNode(int value) : data(value), left(nullptr), right(nullptr), isThreaded(false) {}
};

class ThreadedBinaryTree {
public:
    ThreadedNode* root;

    ThreadedBinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    ThreadedNode* insertRec(ThreadedNode* root, int value) {
        if (root == nullptr) {
            return new ThreadedNode(value);
        }

        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else if (value > root->data) {
            root->right = insertRec(root->right, value);
        }

        return root;
    }

    void createThreads() {
        ThreadedNode* pre = nullptr;
        createThreadRec(root, pre);
    }

    void createThreadRec(ThreadedNode* current, ThreadedNode*& pre) {
        if (current == nullptr)
            return;

        createThreadRec(current->left, pre);

        if (pre && !current->left) {
            current->left = pre;
            current->isThreaded = true;
        }

        if (pre && pre->right == nullptr) {
            pre->right = current;
            pre->isThreaded = true;
        }

        pre = current;
        createThreadRec(current->right, pre);
    }

    void inOrderTraversal() {
        ThreadedNode* current = leftMost(root);
        while (current) {
            cout << current->data << " ";
            if (current->isThreaded)
                current = current->right;
            else
                current = leftMost(current->right);
        }
        cout << endl;
    }

    ThreadedNode* leftMost(ThreadedNode* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }
};

int main() {
    ThreadedBinaryTree tbt;
    int n, val;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        tbt.insert(val);
    }

    tbt.createThreads();
    cout << "In-order traversal: ";
    tbt.inOrderTraversal();

    return 0;
}
