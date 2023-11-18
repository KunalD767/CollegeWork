#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insert(Node* &head, int pos, int data) {
    if (pos == 0) {
        Node *new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        return;
    }

    Node *curr = head;
    for (int i = 0; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        return;
    }

    Node *temp = new Node(data);
    temp->next = curr->next;
    curr->next = temp;
}

void middle(Node* &head){
    Node* ptr1= head;
    Node* ptr2=head;
    while(ptr2->next!=nullptr && ptr2->next->next!=nullptr){
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }
    cout<<"Middle element is "<<ptr1->data<<endl;
}
void display(Node* &head){
    if (head==NULL){
        cout<<"Linked list not present";
        return;
    }
    Node* curr=head;
    while (curr!=NULL){
        cout<< " " << curr->data ;
        curr=curr->next;
    }
}
int main(){
    Node* head=new Node(62);
    insert(head,1,24);
    insert(head,2,23);
    insert(head,3,62);
    insert(head,4,44);
    middle(head);
    display(head);
}