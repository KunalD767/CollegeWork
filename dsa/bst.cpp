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

    int height() {
        return calculateHeight(root);
    }
    int calculateHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int lheight = calculateHeight(node->left);
        int rheight = calculateHeight(node->right);
        return 1 + max(lheight, rheight);
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
        int preorder(Node* node) {
            if (node == nullptr) {
                return -1;
            }
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
        int inorder(Node* node) {
            if (node == nullptr) {
                return -1; 
            }
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
        int postorder(Node* node) {
            if (node == nullptr) {
                return -1;
            }
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
            }
        }
};
int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;
    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;
    cout << "Postorder traversal: ";
    tree.postorder(tree.root);
    cout << endl;
    return 0;
}