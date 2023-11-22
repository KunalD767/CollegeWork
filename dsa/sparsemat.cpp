#include<iostream>
using namespace std;
class Node
{
    public:
    int row;
    int col;
    int data;
    Node *next;
    Node(int x, int y, int z){
        row = x;
        col = y;
        data=z;
        next=NULL;
    }
};
void insertatend(Node* &head,int x,int y,int z){
    Node *new_node = new Node(x,y,z);
    if (head == NULL) {
        head = new_node;
        return;
        }
        Node *last = head;
        while (last->next != NULL) {
            last = last->next;
            }
            last->next = new_node;
            return;
            }
            void printlist(Node *n){
                Node *temp = n;
                while (temp != NULL) {
                    cout << "row: " << temp->row << " col: " << temp->col << " data: " << temp->data <<" address: "<<temp->next<<endl;
                    temp = temp->next;
                    }
            }




int main(){
    int a[5][2],i,j,c;
    int *e;
    for (i=0;i<5;i++){
        for (j=0;j<2;j++){
            cout<<"enter element at"<<i<<","<<j<<endl;
            cin>>a[i][j];
        }
    }    
    Node *head = NULL;
    for (i=0;i<5;i++){
        for (j=0;j<2;j++){
            if (a[i][j]!=0){
                insertatend(head,i,j,a[i][j]);
               
            }
        }
     }
    printlist(head);
    
    return 0;


}