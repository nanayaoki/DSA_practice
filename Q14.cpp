#include <iostream>
using namespace std;

#define MAX 5   // Maximum orders (M)

class CircularQueue {
    int front, rear;
    int arr[MAX];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Place order (enqueue)
    void placeOrder(int orderID) {
        // Check if queue is full
        if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) {
            cout << "Sorry! No more orders can be accepted. Queue is FULL.\n";
            return;
        }

        // First order
        if (front == -1 && rear == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX;
        }

        arr[rear] = orderID;
        cout << "Order " << orderID << " placed successfully.\n";
    }

    // Serve order (dequeue)
    void serveOrder() {
        if (front == -1) {
            cout << "No orders to serve. Queue is EMPTY.\n";
            return;
        }

        cout << "Order " << arr[front] << " served.\n";

        // Single element left
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }

    // Display pending orders
    void displayOrders() {
        if (front == -1) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending Orders: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, orderID;

    do {
        cout << "\n--- Pizza Parlor System ---\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Pending Orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> orderID;
                q.placeOrder(orderID);
                break;

            case 2:
                q.serveOrder();
                break;

            case 3:
                q.displayOrders();
                break;

            case 4:
                cout << "Thank you! Visit again.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
