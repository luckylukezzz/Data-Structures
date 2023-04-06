#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    void deleteAtHead() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtTail() {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }

        delete current;
        previous->next = nullptr;
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";//
            current = current->next;
        }

        cout << endl;
    }

    void deleteByValue(int val) {
        if (head == nullptr) {
            return;
        }

        if (head->data == val) {
            deleteAtHead();
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != val) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            return;
        }

        previous->next = current->next;
        delete current;
    }
};

int main() {
    LinkedList myList;
    myList.insertAtHead(1);
    myList.insertAtHead(2);
    myList.insertAtTail(3);
    myList.printList(); 
    myList.deleteByValue(3);
    myList.deleteAtTail();
    myList.printList(); 
    return 0;
}