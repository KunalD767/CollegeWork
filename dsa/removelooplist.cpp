#include<iostream>
using namespace std;
class Node{
    public:
    int rollno;
    Node* next;
    Node(int data){
       rollno=data;
    }
    
};
void insertAthead(Node* &head, int a){
    Node* b=new Node(a);
    b->next=head;
    head=b;

}
void insertAtpos(Node* &head,int pos, int a){
    int o=0;
    Node* ab=new Node(a);
    Node* n=head;
    if (pos==0){
        insertAthead(head,a);
    }
    else{
        while (o<pos){
            n=n->next;
            o++;
        }
        ab->next=n->next;
        n->next=ab;
    }
}
void del(Node* &head, int pos){
    int o=0;
    Node *a=head;
    while(o<pos){
        a=a->next;
        o++;
    }
    Node* temp=a->next;
    a->next=a->next->next;
    free(temp);

}
void display(Node* &head){
    Node* t=head;
    while (t!=NULL){
        cout<<"the roll no " << "is "<<t->rollno<<" the address of next is "<<t->next<<endl;
        t=t->next;
    }
}
void evendisplay(Node* &head){
    Node* t=head;
    while (t!=NULL){
        cout<<"the even roll no " << " is "<<t->rollno<<" the address of next is "<<t->next<<endl;
        t=t->next;
    }
}
void odddisplay(Node* &head){
    Node* t=head;
    while (t!=NULL){
        cout<<"the odd roll no of" << "is "<<t->rollno<<" the address of next is "<<t->next<<endl;
        t=t->next;
    }
}
void evenodd(Node* &head) {
    Node* a = new Node(0); // Create a dummy even list
    Node* b = new Node(0); // Create a dummy odd list
    Node* even = a;
    Node* odd = b;
    
    while (head != NULL) {
        if (head->rollno % 2 == 0) {
            even->next = new Node(head->rollno);
            even = even->next;
        }
        else {
            odd->next = new Node(head->rollno);
            odd = odd->next;
        }
        head = head->next;
    }
    
    evendisplay(a->next); 
    odddisplay(b->next); 
    delete a; 
    delete b; 
}

int main(){
    Node* n=new Node(1);
    Node* head=n;
    insertAthead(head,4);
    insertAthead(head,3);
    insertAthead(head,2);
    insertAtpos(head,3,5);
    del(head,2);
    evenodd(head);
    
    return 0;
}
