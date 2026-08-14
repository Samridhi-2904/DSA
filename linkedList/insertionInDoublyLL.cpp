#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

};
//traversal
void printNode(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<< temp->data <<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//gives len of linked list
int getLength(Node* head){
    int len=0;
    Node* temp=head;

    while(temp != NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void insertAtHead(Node* &head,int data){

    if(head == NULL){
        Node* temp=new Node(data);
        head=temp;
    }
    else{
        Node* temp=new Node(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void insertAtTail(Node* &tail,int data){

    if(tail == NULL){
        Node* temp=new Node(data);
        tail=temp;
    }
    else{
         Node* temp=new Node(data);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void insertAtPosition(Node* &tail,Node* &head,int position,int data){
    if(position==1){
        insertAtHead(head,data);
        return;
    }

    Node* temp=head;
    int count=1;

    while(count<position-1){
        temp=temp->next;
        count++;
    }

    if(temp->next ==NULL){
        insertAtTail(tail,data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert ->next = temp-> next;
    temp ->next -> prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;


}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    printNode(head);
    cout<< getLength(head) << endl;

    insertAtHead(head,11);
    printNode(head);
    insertAtHead(head,8);
    printNode(head);
    insertAtHead(head,5);
    printNode(head);

    insertAtTail(tail,20);
    printNode(head);

    insertAtPosition(tail,head,2,100);
    printNode(head);
    insertAtPosition(tail,head,1,50);
    printNode(head);
    return 0;
}