#include<iostream>
using namespace std;

struct node
{
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
    //when, (head->next == NULL) and (head->next != NULL)
    else {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode; 
        newNode->prev = temp;
    }
    cout << newNode->data << " is inserted \n";
}

void insertAtBeginning(struct node *&head, int data) {
    struct node *newNode = new node(data);

    if(head == NULL) {
        head = newNode;
    }
    else {
        newNode->next = head; 
        head->prev = newNode;
        head = newNode;
    }
    cout << head->data << " is inserted \n";

}

void insertAtPosition(struct node *&head, int data, int position) {
    struct node *newNode = new node(data);
    if(position == 1) {
        insertAtBeginning(head, data);
    }
    else {
        int count = 1;
        struct node *temp = head;
        while (count < position-1)
        {
            temp = temp->next;
            count++;
        }
        
        temp->next->prev = newNode;
        newNode->next = temp->next;
        newNode-> prev = temp;
        temp->next = newNode;   
    }
    cout << newNode->data << " is inserted at "<< position << " position" << "\n";
}

void printLinkedList(struct node *head) {
    if(head == NULL) {
        cout << "No node is here ! \n";
        return;
    }

    struct node *temp = head;
    cout << "The linked list is :-" << endl;
    while (temp != NULL) 
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;

    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    cout << "Reverse linked list : " << endl;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->prev;
    } 
}

int main() {
    cout << "Insertion in doubly linked list:-" << endl;
    struct node *head = NULL;

    insertAtEnd(head, 12);
    insertAtEnd(head, 14);
    insertAtEnd(head, 56);
    insertAtEnd(head, 15);
    insertAtEnd(head, 20);

    insertAtBeginning(head, 23);

    insertAtPosition(head, 45, 4);

    insertAtEnd(head, 17);

    insertAtBeginning(head, 35);

    insertAtPosition(head, 42, 9);

    printLinkedList(head);
}

