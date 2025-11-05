#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

void display() {
    if (front == NULL) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Queue: ";
    display();

    dequeue();
    cout << "After dequeue: ";
    display();

    return 0;
}
