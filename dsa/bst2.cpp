#include <iostream>
using namespace std;
class Automobile {
public:
  string type;
  string company;
  int year;
  Automobile(string type, string company, int year) {
    this->type = type;
    this->company = company;
    this->year = year;
  }
};
class Node {
public:
  Automobile *data;
  Node *left;
  Node *right;
  Node(Automobile *data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};
class BinaryTree {
public:
  Node *root;
  BinaryTree() {
    this->root = nullptr;
  }
  void insert(Automobile *data) {
    Node *a = new Node(data);
    if (root == nullptr) {
      root = a;
      return;
    }
    Node *curr = root;
    Node *parent = nullptr;
    while (true) {
      if (data->year < curr->data->year) {
        if (curr->left == nullptr) {
          curr->left = a;
          return;
        } else {
          parent = curr;
          curr = curr->left;
        }
      } else {
        if (curr->right == nullptr) {
          curr->right = a;
          return;
        } else {
          parent = curr;
          curr = curr->right;
        }
      }
    }
  }



  void inorder(Node *curr) {
    if (curr == nullptr) {
        return;
    }
    inorder(curr->left);
    cout << curr->data->type << " " << curr->data->company << " " << curr->data->year << " -> ";
    inorder(curr->right);
  }
  void preorder(Node *curr) {
    if (curr == nullptr) {
        
        return;
    }
    cout << curr->data->type << " " << curr->data->company << " " << curr->data->year << "->";
    preorder(curr->left);
    preorder(curr->right);
  }


  void postorder(Node *curr) {
    if (curr == nullptr) {
        return;
    }
    postorder(curr->left);
    postorder(curr->right);
    cout << curr->data->type << " " << curr->data->company << " " << curr->data->year << "->";
  }
};

int main() {
  BinaryTree bst;
  bst.insert(new Automobile("SUV", "Toyota", 2018));
  bst.insert(new Automobile("Hatchback", "Volkswagen", 2020));
  bst.insert(new Automobile("Truck", "Tata", 2015));
  bst.insert(new Automobile("Sedan", "Honda", 2019));
  bst.insert(new Automobile("Hatchback", "Maruti Suzuki", 2017));
  cout << "\n\nInorder traversal of the Binary Tree:" << endl;
  bst.inorder(bst.root);
  cout<<"End";
  cout << "\n\nPreorder traversal of the Binary Tree:" << endl;
  bst.preorder(bst.root);
  cout<<"End";
  cout << "\n\nPostorder traversal of the Binary Tree:" << endl;
  bst.postorder(bst.root);
  cout<<"End";
  return 0;
}
