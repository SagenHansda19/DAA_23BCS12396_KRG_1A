#include <bits/stdc++.h>
using namespace std;

class DoublyNode {
   public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;
    DoublyNode(int val) : data(val), prev(NULL), next(NULL) {}
};
class DoublyLinkedList {
    DoublyNode* head;
    DoublyNode* tail;

   public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}
    void insertAtBeginning(int val) {
        DoublyNode* node = new DoublyNode(val);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    void insertAtEnd(int val) {
        DoublyNode* node = new DoublyNode(val);
        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    void deleteAtBeginning() {
        if (!head) return;
        DoublyNode* temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }
    void deleteAtEnd() {
        if (!tail) return;
        DoublyNode* temp = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }
    void display() {
        DoublyNode* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
class CircularNode {
   public:
    int data;
    CircularNode* next;
    CircularNode(int val) : data(val), next(NULL) {}
};
class CircularLinkedList {
    CircularNode* tail;

   public:
    CircularLinkedList() : tail(NULL) {}
    void insertAtBeginning(int val) {
        CircularNode* node = new CircularNode(val);
        if (!tail) {
            tail = node;
            tail->next = tail;
        } else {
            node->next = tail->next;
            tail->next = node;
        }
    }
    void insertAtEnd(int val) {
        CircularNode* node = new CircularNode(val);
        if (!tail) {
            tail = node;
            tail->next = tail;
        } else {
            node->next = tail->next;
            tail->next = node;
            tail = node;
        }
    }
    void deleteAtBeginning() {
        if (!tail) return;
        CircularNode* head = tail->next;
        if (tail == head) {
            delete head;
            tail = NULL;
        } else {
            tail->next = head->next;
            delete head;
        }
    }
    void deleteAtEnd() {
        if (!tail) return;
        CircularNode* curr = tail->next;
        if (curr == tail) {
            delete tail;
            tail = NULL;
        } else {
            while (curr->next != tail) {
                curr = curr->next;
            }
            curr->next = tail->next;
            delete tail;
            tail = curr;
        }
    }
    void display() {
        if (!tail) {
            cout << "List empty\n";
            return;
        }
        CircularNode* head = tail->next;
        CircularNode* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "Doubly Linked List:\n";
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.display();
    dll.deleteAtBeginning();
    dll.deleteAtEnd();
    dll.display();

    cout << "\nCircular Linked List:\n";
    CircularLinkedList cll;
    cll.insertAtBeginning(10);
    cll.insertAtEnd(20);
    cll.insertAtBeginning(5);
    cll.display();
    cll.deleteAtBeginning();
    cll.deleteAtEnd();
    cll.display();

    return 0;
}
