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
    else {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;

        cout << newNode->data << " is inserted \n";   
    }
}

void searchInLinkedList(struct node *&head, int data) {
    if(head == NULL) {
        cout << "No node is here !" << endl;
        return;
    }
    else {
        struct node *temp = head;
        int position = 1;
        while(temp != NULL) {
            if(temp->data == data) {
                cout << data << " is found at " << position << " position" << endl;
                return;
            }
            temp = temp->next;
            position ++;
        }
    }
}

void printLinkedList(struct node *head) {
    if(head == NULL) {
        cout << "No node is here !" << endl;
        return;
    }
    else {
        struct node *temp = head;
        cout << "The Linked list is :-" << endl;
        while (temp->next != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << temp->data << "\n";

        cout << "Reverse Linked List is :-" << endl;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->prev;
        }  
        cout << "\n"; 
    }
}

int main() {
    cout << "Traversal in doubly linked list :-" << endl;
    struct node *head = NULL;
    insertAtEnd(head, 11);
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 14);
    insertAtEnd(head, 15);

    printLinkedList(head);

    searchInLinkedList(head, 14);

}