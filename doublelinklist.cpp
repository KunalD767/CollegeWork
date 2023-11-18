#include<iostream>
using namespace std;
class Employee{
    public:
    int Empid;
    string name;
    Employee* next;
    Employee* prev;
    Employee(int a,string b){
        Empid=a;
        name=b;
        next=NULL;
        prev=NULL;
    }

    
};
void InsertAtHead(Employee* &head,int a,string b){
    Employee* c=new Employee(a,b);
    c->prev=NULL;
    c->next=head;
    head->prev=c;
    head=c;
}
void Insertatpos(Employee* &head,int pos,int a, string b){
    int i=1;
    Employee* t=head;
    while(i<pos){
        t=t->next;
        i++;
    }
    Employee* f=new Employee(a,b);
    f->next=t->next;
    f->prev=t->prev;
    t->next=f;
    f->prev=t;
    
}
void del(Employee* &head, int pos){
    Employee* a=head;
    int i=0;
    while(i<pos){
        a=a->next;
        i++;
    }
    Employee* temp=a->next;
    a->next=a->next->next;
    free(temp);

}
void display(Employee* &head){
    Employee* t=head;
    while(t!=NULL){
         cout<<"the Employee id is "<<t->Empid <<" the name is "<<t->name<<" the address of next is "
         <<t->next<<" the address of prev is "<<t->prev<<endl;
         t->prev=t;
         t=t->next;
         
    }
}
int main(){

    Employee* a=new Employee(1,"kunal");
    Employee* head=a;
    InsertAtHead(head,2,"k");
    InsertAtHead(head,3,"c");
    Insertatpos(head,2,4,"a");
    del(head,2);
    display(head);

    return 0;
}


