// Aakash Choudhari
// 24070123031
// E&TC-A2


#include <iostream>
using namespace std;

#define SIZE 5 // Maximum size of the circular queue

class CircularQueue {
    int arr[SIZE];
    int front;
    int rear;

public:
    // Constructor
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Helper function to check if the queue is empty
    bool isEmpty() const {
        return front == -1;
    }

    // Helper function to check if the queue is full
    bool isFull() const {
        // Condition for a full circular queue
        return (rear + 1) % SIZE == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! (Queue is full)" << endl;
            return;
        }

        if (isEmpty()) {
            front = 0; // Initialize front on the first insert
        }

        // Circularly update rear: rear = (rear + 1) % SIZE
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << value << " inserted into queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! (Queue is empty)" << endl;
            return;
        }

        int dequeuedValue = arr[front];
        cout << dequeuedValue << " removed from queue." << endl;

        if (front == rear) {
            // Case 1: Only one element left. Reset queue to empty state.
            front = -1;
            rear = -1;
        } else {
            // Case 2: Move front circularly: front = (front + 1) % SIZE
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE; // Move index circularly
        } while (i != (rear + 1) % SIZE); // Loop until we pass the rear element
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue(); // Remove 10 (Space at index 0 is now free)
    q.display();

    // The key improvement: enqueue 40. This will wrap around to index 0, reusing space.
    q.enqueue(40);
    q.display();
    
    q.enqueue(50); // Add 50
    q.enqueue(60); // Add 60 (Queue is now full)
    q.display();
    
    q.enqueue(70); // Should trigger overflow

    return 0;
}
