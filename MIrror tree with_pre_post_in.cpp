#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void mirrorBST(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Swap left and right subtrees
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the left and right subtrees
    mirrorBST(root->left);
    mirrorBST(root->right);
}

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = nullptr;
    int n;
    cout << "Enter the number of elements in the BST: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "In-order traversal of the original BST: ";
    inOrderTraversal(root);
    cout << endl;

    mirrorBST(root);

    cout << "In-order traversal of the mirror image of the BST: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal of the mirror image of the BST: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal of the mirror image of the BST: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
