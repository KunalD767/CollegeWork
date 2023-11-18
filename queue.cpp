#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front; 
    Node* rear;  
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void Insert(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int del() {
        if (isEmpty()) {
            cerr << "Queue is empty. Cannot del." << endl;
            return -1; 
        }

        int dequeuedValue = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr; 
        }

        return dequeuedValue;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        Node* current = front;
        cout << "Queue: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.Insert(1);
    queue.Insert(2);
    queue.Insert(3);

    queue.display();

    cout << "Deleted element: " << queue.del() << endl;
    queue.display();

    return 0;
}
