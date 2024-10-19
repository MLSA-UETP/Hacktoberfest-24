#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

int length(node* head) {
    node* temp = head;
    int l = 0;
    while (temp != NULL) {
        l++;
        temp = temp->next;
    }
    return l;
}

int intersection(node* &head1, node* &head2) {
    int l1 = length(head1);
    int l2 = length(head2);
    node* ptr1;
    node* ptr2;
    int d = 0;
    if (l1 > l2) {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    } else {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d) {
        ptr1 = ptr1->next;
        if (ptr1 == NULL) {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

void insertAThead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertATtail(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
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
    node* head1 = NULL;
    node* head2 = NULL;

    insertATtail(head1, 1);
    insertATtail(head1, 2);
    insertATtail(head1, 3);
    insertATtail(head1, 4);
    display(head1);

    insertATtail(head2, 7);
    insertATtail(head2, 8);
    insertATtail(head2, 9);
    display(head2);

    
    head2->next->next->next = head1->next->next; 

    int intersect_val = intersection(head1, head2);
    if (intersect_val == -1) {
        cout << "No intersection" << endl;
    } else {
        cout << "Intersection at node with value: " << intersect_val << endl;
    }

    return 0;
}
