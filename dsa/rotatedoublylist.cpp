#include<iostream>
using namespace std;
class Node{
    public:
    int data;
   
    Node* next;
    Node* prev;
    Node(int a){
        data=a;
        next=NULL;
        prev=NULL;
    }

    
};
void InsertAtHead(Node* &head,int a){
    Node* c=new Node(a);
    c->prev=NULL;
    c->next=head;
    head->prev=c;
    head=c;
}
void Insertatpos(Node* &head,int pos,int a){
    int i=1;
    Node* t=head;
    while(i<pos){
        t=t->next;
        i++;
    }
    Node* f=new Node(a);
    f->next=t->next;
    f->prev=t->prev;
    t->next=f;
    f->prev=t;
    
}

void rotateList(Node* &head, int n) {
    if (head == nullptr || n == 0) {
        return;
    }
    Node* current = head;
    int count = 1;
    while (count < n && current != nullptr) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        return; 
    }

    
    Node* nthNode = current;
    while (current->next != nullptr) {
        current = current->next;
    }

    
    current->next = head;
    head->prev = current;
    head = nthNode->next;
    head->prev = nullptr;
    nthNode->next = nullptr;
}

void display(Node* &head){
    Node* t=head;
    while(t!=NULL){
         cout<<"the Node id is "<<t->data <<" the address of next is "
         <<t->next<<" the address of prev is "<<t->prev<<endl;
         t->prev=t;
         t=t->next;
         
    }
}
int main(){

    Node* a=new Node(1);
    Node* head=a;
    InsertAtHead(head,2);
    InsertAtHead(head,3);
    Insertatpos(head,2,4);
    display(head);
    rotateList(head, 2);
    cout<<"After Rotation:"<<endl;
    display(head);

    return 0;
}


