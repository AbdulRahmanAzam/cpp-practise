// coding ninja
// https://www.codingninjas.com/studio/problems/reverse-the-singly-linked-list_799897


#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

// void reverseList(Node* &head, Node* &tail){
//     Node* curr = head;
//     Node* prev = NULL;
//     Node* forward = NULL;

//     while(curr != NULL){
//         forward = curr -> next;
//         curr -> next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     head = prev;
// }

void reverseList(Node* &head, Node* &tail) {
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        tail = head;  // Update tail during the first iteration
        head = curr;  // Update head to the current node
        curr = curr->next;  // Move to the next node
        head->next = prev;  // Reverse the current node's next pointer
        prev = head;  // Move prev to the current node
    }
}

void insertAtTail(Node* &tail, int n){
    Node* temp = new Node(n);

    tail -> next = temp;
    tail = temp;
    // or
    // tail = tail -> next;
}

void print(Node* &head){
    Node* temp = head;

    while(temp -> next != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){
    Node* node1 = new Node(1);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    print(head);

    reverseList(head, tail);
    print(head);
}


