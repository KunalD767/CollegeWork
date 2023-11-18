#include<iostream>
using namespace std;
class Node{
    public:
    int rollno;
    string a;
    int marks;
    Node* next;
    Node(int data,string name,int m){
        rollno=data;
        a=name;
        marks=m;
        next=NULL;
    }
    
};
void insertAthead(Node* &head, int a,string c,int m){
    Node* b=new Node(a,c,m);
    b->next=head;
    head=b;

}
void insertAtpos(Node* &head,int pos, int a,string c,int m){
    int o=0;
    Node* ab=new Node(a,c,m);
    Node* n=head;
    if (pos==0){
        insertAthead(head,a,c,m);
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
        cout<<"the roll no is "<<t->rollno<<" the name is "<<t->a<<" and the marks are "<<t->marks<<
        " the address of next is "<<t->next<<endl;
        t=t->next;
    }
}
int main(){
    Node* n=new Node(1,"a",100);
    Node* head=n;
    insertAthead(head,2,"c",30);
    insertAthead(head,4," b",50);
    insertAthead(head,5,"d",50);
    insertAtpos(head,0,3,"e",40);
    del(head,2);

    display(head);
    
    return 0;
}
