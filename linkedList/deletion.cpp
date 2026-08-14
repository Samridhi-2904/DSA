#include <iostream>

using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void deleteNode(int position, Node* &head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        delete curr;
    }
}
void printNode(Node* &head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }
}
void insertAtHead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
int main()
{
    Node *node1 = new Node(20);
    Node *head = node1;
    insertAtHead(head,30);
    insertAtHead(head,40);
    cout << node1->data << endl;
    cout << node1->next << endl;
    cout<<"Before Deletion"<<endl;
    printNode(head);
    cout<<endl<<"After Deletion"<<endl;
    deleteNode(1, head);
    printNode(head);
    return 0;
}