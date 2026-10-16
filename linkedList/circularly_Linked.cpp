#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

bool isCircularList(Node* head) {
    if(head == NULL){
        return true;
    }
    Node* temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }
    if(temp == head){
        return true;
    }
    return false;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = fourth;

    // Make the list circular
    fourth->next = head;

    if (isCircularList(head)) {
        cout << "The linked list is circular." << endl;
    } else {
        cout << "The linked list is not circular." << endl;
    }

    return 0;
}