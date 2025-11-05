#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
    Node* head;
    
public:
    LinkedList() {
        head = NULL;
    }

    // Insert at end
    void insert(int value) {
        Node* newNode = new Node(value);
        
        if (head == NULL) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        
        temp->next = newNode;
    }

    // Delete node by value
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        // If head node is to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted!" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Element not found!" << endl;
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        cout << "Node deleted!" << endl;
    }

    // Display Linked List
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Search element
    void search(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Element found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found!" << endl;
    }

    // Reverse linked list
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;

        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;

        cout << "List reversed successfully!" << endl;
    }

    // Find middle node
    void findMiddle() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle node value: " << slow->data << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n--- Singly Linked List Menu ---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Search" << endl;
        cout << "5. Reverse" << endl;
        cout << "6. Find Middle Node" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;

            case 3:
                list.display();
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 5:
                list.reverse();
                break;

            case 6:
                list.findMiddle();
                break;

            case 7:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
