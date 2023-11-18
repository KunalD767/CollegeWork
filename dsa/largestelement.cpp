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
    int inorder(Node* node) {
            if (node == nullptr) {
                return -1; 
            }
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
        int size(Node* node){
            if (node==nullptr)return 0;
            return size(node->left)+size(node->right)+1;
        }
        void kthlarge(Node* node, int k, int &count) {
        if (node == nullptr || count >= k) {
            return;
        }

        kthlarge(node->right, k, count);
        count++;
        if (count == k) {
            cout <<k<< "th largest element: " << node->data << endl;
            return;
        }
        kthlarge(node->left, k, count);
    }

    void findKthLargest(int k) {
        int count = 0;
        kthlarge(root, k, count);
    }
        
        };
int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(23);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    tree.findKthLargest(4);
    cout << endl;
    
    return 0;
}