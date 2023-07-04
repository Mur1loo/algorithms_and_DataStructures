#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=nullptr;
    }
};

void insert(node* &head, int val){
    node* n = new node(val);

    if(head==nullptr){
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = n;
}

void printlist(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head = nullptr;
    insert(head, 5);
    insert(head, 10);
    printlist(head);

return 0;
}
