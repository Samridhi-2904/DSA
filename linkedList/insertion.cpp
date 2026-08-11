#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=tail->next;  //or tail=temp;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int data){
    if(position==1){
        insertAtHead(head,data);
    }

    Node* temp = head;
    int count = 1;
    if(temp->next == NULL){
        insertAtTail(tail,data);
    }

    while(count < position-1){
        temp = temp->next;
        count++;

    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
}

int main() {
    Node *node1 = new Node(20);

    cout << node1->data << endl;
    cout << node1->next << endl;

    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head,30);
    insertAtHead(head,40);

    insertAtTail(tail,15);
    insertAtTail(tail,12);
    print(head);

    cout<<endl;
    insertAtPosition(head,tail,3,22);
    print(head);

    cout<< endl <<"head: " << head->data <<endl;
    cout<<"tail: " << tail->data <<endl;
    return 0;
}