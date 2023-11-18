#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
};
class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        root = nullptr;
    }
    void insert(int data) {
        Node* a = new Node;
        a->data = data;
        a->left = nullptr;
        a->right = nullptr;
        if (root == nullptr) {
            root = a;
            return;
        }
        Node* curr = root;
        while (true) {
            if (data < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = a;
                    return;
                } else {
                    curr = curr->left;
                }
            } 
            else {
                if (curr->right == nullptr) {
                    curr->right = a;
                    return;
                } else {
                    curr = curr->right;
                }
            }
        }
    }
} ;   
    int Height(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = Height(node->left);
        int right = Height(node->right);
        return 1 + max(left, right);
    }
int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    cout << "Height of the binary tree is: " << Height(tree.root);
    return 0;
}