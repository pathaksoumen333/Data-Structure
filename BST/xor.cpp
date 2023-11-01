#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class XORTree {
public:
    Node* root;

    Node* buildXORTree(int arr[], int start, int end) {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;
        Node* node = new Node(arr[mid]);

        node->left = buildXORTree(arr, start, mid - 1);
        node->right = buildXORTree(arr, mid + 1, end);

        return node;
    }

    void insert(int value) {
        int arr[1] = { value };
        root = buildXORTree(arr, 0, 0);
    }

    void XORTraversal(Node* node) {
        if (node != nullptr) {
            XORTraversal(node->left);
            cout << node->data << " ";
            XORTraversal(node->right);
        }
    }
};

int main() {
    XORTree tree;
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    int arr[n];
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        tree.insert(arr[i]);
    }

    cout << "XOR Tree traversal: ";
    tree.XORTraversal(tree.root);
    cout << endl;

    return 0;
}
