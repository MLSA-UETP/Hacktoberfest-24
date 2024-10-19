#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAThead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    if (head != NULL) {
        head->prev = n;
    }
    head = n;
}

void insertATtail(node* &head, int val) {
    if (head == NULL) {
        insertAThead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void deleteAThead(node* &head) {
    if (head == NULL) {
        return;
    }
    node* todelete = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete todelete;
}

void deleteATnode(node* &head, int pos) {
    if (head == NULL) {
        return;
    }
    if (pos == 1) {
        deleteAThead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while (temp != NULL && count != pos) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    node* head = NULL;
    insertAThead(head, 1);
    insertATtail(head, 2);
    insertATtail(head, 3);
    insertATtail(head, 4);
    insertATtail(head, 5);
    insertATtail(head, 6);
    display(head);
    deleteAThead(head);
    display(head);
    deleteATnode(head, 3);
    deleteATnode(head, 4); 
    display(head);
}
