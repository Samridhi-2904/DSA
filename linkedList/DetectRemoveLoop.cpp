#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    Node* detectAndRemoveLoop(Node* head) {
        if (head == NULL)
            return NULL;

        Node* slow = head;
        Node* fast = head;

        while (slow != NULL && fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return slow;
            }
        }
        return NULL;
    }

    Node* getStartingNode(Node* head) {
        if (head == NULL)
            return NULL;

        Node* intersection = detectAndRemoveLoop(head);
        if (intersection == NULL)
            return NULL;

        Node* slow = head;

        while (slow != intersection) {
            slow = slow->next;
            intersection = intersection->next;
        }

        return slow;
    }

    void removeLoop(Node* head) {
        Node* startOfLoop = getStartingNode(head);

        if (startOfLoop == NULL)
            return;

        Node* temp = startOfLoop;

        while (temp->next != startOfLoop) {
            temp = temp->next;
        }

        temp->next = NULL;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    Solution obj;
    obj.removeLoop(head);

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}