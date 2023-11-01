#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    TreeNode* insertRec(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else {
            root->right = insertRec(root->right, value);
        }

        return root;
    }

    int sumLeafNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return root->data;
        }

        int leftSum = sumLeafNodes(root->left);
        int rightSum = sumLeafNodes(root->right);

        return leftSum + rightSum;
    }
};

int main() {
    BinarySearchTree bst;
    int n, val;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        bst.insert(val);
    }

    int leafSum = bst.sumLeafNodes(bst.root);

    cout << "Sum of leaf nodes: " << leafSum << endl;

    // Clean up memory (optional)
    // You can add a destructor in the BinarySearchTree class to handle memory cleanup.

    return 0;
}
