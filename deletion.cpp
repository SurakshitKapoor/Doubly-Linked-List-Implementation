#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
    node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void insertAtEnd(struct node *&head, int data) {
    struct node *newNode = new node(data);
    if(head == NULL) {
        head = newNode;
    }
    else {
        struct node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    // else if(head->next == NULL) {
    //     head->next = newNode;
    //     newNode->prev = head;
    // }
    // else {
    //     struct node *temp = head;
    //     while (temp->next != NULL)
    //     {
    //         temp = temp->next;
    //     }
    //     temp->next = newNode;
    //     newNode->prev = temp;
    // }
    cout << newNode->data << " is inserted" << endl;
}

void deleteAtBeginning(struct node *&head) {
    if(head == NULL) {
        cout << "No node is here !" << endl;
        return;
    }
    else if(head->next == NULL){
        delete head;
        head = NULL;
    }
    else {
        struct node *delNode = head;
        head = head->next;
        head->prev = NULL;
        delete delNode;

    }
}
void deleteAtEnd(struct node *&head) {
    if(head == NULL) {
        cout << "No node is here !" << endl;
        return;
    }
    else if(head->next == NULL) {
        delete head;
        head = NULL;
    }
    else {
        struct node *temp = head;
        struct node*temp2 = NULL;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp2 = temp->prev;
        temp2->next = NULL;
        delete temp;
    }
}

void deleteAtPosition(struct node *&head, int position) {
    struct node *temp = head;
    if(position == 1) {
        deleteAtBeginning(head);
    }
    else {
        int count = 1;
        while (count < position-1)
        {
            temp = temp->next;
            count++;
        }
        struct node *delNode = temp->next;
        temp->next = delNode->next;
        if(delNode->next != NULL) {
            delNode->next->prev = temp;
        }        
        delete delNode;
    }    
}

void printLinkedList(struct node *&head) {
    if(head == NULL) {
        cout << "No node is here !" << endl;
        return;
    }
    else {
        struct node *temp = head;
        cout << "\n The linked list is :- \n";
        while (temp->next != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << temp->data << "\n";

        cout << "Reverse Linked List is :- \n";
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->prev;
        }  
    }
}

int main() {
    cout << "Deletion in doubly linked list :-" << endl;
    struct node *head = NULL;

    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 15);
    insertAtEnd(head, 18);
    insertAtEnd(head, 20);

    deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);

    deleteAtBeginning(head);
    // deleteAtBeginning(head);
    // deleteAtBeginning(head);
    // deleteAtBeginning(head);

    deleteAtPosition(head, 1);
    // deleteAtPosition(head, 2);

    printLinkedList(head);
}