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

void dup(Node* &head,int x){
    if (head==NULL) return;
    Node *a=head;
    while(a!=NULL){
        if (a->data==x){
            break;

        }
        else{
            a=a->next;
        }
    }
    int count=0;
    Node *b=head;
        
    while(b!=NULL){
        if(a->data==b->data){
             count++;
         } 
        b=b->next;
    }
    cout<<" the total number of duplicates "<<" is "<< count;

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
    insert(head,1,23);
    insert(head,2,23);
    insert(head,3,62);
    insert(head,4,44);
    insert(head,5,62);
    dup(head,62);
    display(head);
}