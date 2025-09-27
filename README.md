### 🔄 Cpp\_Exp18\_Circular\_Queue: Efficient Queue Management 🔄

This repository contains the C++ implementation of a **Circular Queue** using a fixed-size array. This structure is an essential data structure in computer science, representing an improvement over the basic linear queue by solving the problem of wasted space that occurs after numerous dequeue operations.

-----

### 🎯 Aim

To implement and demonstrate the operations of a **Circular Queue** using an array, focusing on efficient space management and adherence to the **First-In, First-Out (FIFO)** principle.

-----

### 💡 Theory: The Circular Queue

#### Definition and Structure

A **Circular Queue** is a linear queue where the last position of the queue is conceptually connected to the first position, forming a circle. This design allows for the reuse of array space previously occupied by dequeued elements.

  * **FIFO Principle**: Like all queues, it operates on a First-In, First-Out basis. The element inserted first is always the element removed first.
  * **Implementation**: It is typically implemented using a fixed-size array and two pointers: **`front`** (points to the element to be dequeued) and **`rear`** (points to the last element inserted).
  * **Modular Arithmetic**: The movement of both `front` and `rear` pointers is controlled by the **modulo operator (`% SIZE`)**. This operation ensures that when a pointer reaches the end of the array, it wraps around to the beginning (index 0).

#### State Management (Indices):

  * **Initial State (Empty):** `front = -1` and `rear = -1`.
  * **After First Insertion:** `front = 0` and `rear = 0`.
  * **Full Condition:** The queue is full when the pointer next to `rear` is `front`. This is represented by the formula: **`(rear + 1) % SIZE == front`**.

-----

### ⚙️ Algorithm: Circular Queue Operations

The operations rely on modular arithmetic to handle the wrapping of indices.

#### 1\. Constructor

1.  **Start.**
2.  Initialize **`front = -1`** and **`rear = -1`**.
3.  **End.**

#### 2\. `isFull()`

1.  **Check:** Return `true` if `(rear + 1) % SIZE == front`.
2.  Otherwise, return `false`.

#### 3\. `isEmpty()`

1.  **Check:** Return `true` if `front == -1`.
2.  Otherwise, return `false`.

#### 4\. `enqueue(value)` (Insertion)

1.  **Start.**
2.  **Check for Overflow:** If `isFull()`, display "Overflow" and **End**.
3.  **If `isEmpty()`:** Set `front = 0`.
4.  Calculate new `rear`: **`rear = (rear + 1) % SIZE`**.
5.  Insert `value` at `arr[rear]`.
6.  **End.**

#### 5\. `dequeue()` (Deletion)

1.  **Start.**
2.  **Check for Underflow:** If `isEmpty()`, display "Underflow" and **End**.
3.  Store the value at `arr[front]`.
4.  **If `front == rear` (Single element):** Reset **`front = -1`** and **`rear = -1`** (Queue is now empty).
5.  **Else:** Calculate new `front`: **`front = (front + 1) % SIZE`**.
6.  Display the removed value.
7.  **End.**

#### 6\. `display()` (Traversal)

1.  **Start.**
2.  **Check for Empty:** If `isEmpty()`, display "Queue is empty" and **End**.
3.  Initialize an iterator `i = front`.
4.  **Loop:** While `i` is not equal to `(rear + 1) % SIZE`:
      * Print `arr[i]`.
      * Update `i`: `i = (i + 1) % SIZE`.
5.  **End.**

-----

### 🚀 Flowcharts

#### **General Circular Queue Flow**

```mermaid
graph TD
    A[Start] --> B[Input: value];
    B --> C{isFull()?};
    C -- Yes --> D[Display Overflow];
    C -- No --> E{isEmpty()?};
    E -- Yes --> F[front = 0];
    E -- No --> G[Calculate rear = (rear + 1) % SIZE];
    F --> G;
    G --> H[arr[rear] = value];
    H --> I[End];
    D --> I;
```

#### **Dequeue Operation Flow**

```mermaid
graph TD
    A[Start] --> B{isEmpty()?};
    B -- Yes --> C[Display Underflow];
    B -- No --> D[Store dequeued value = arr[front]];
    D --> E{front == rear?};
    E -- Yes --> F[front = -1, rear = -1];
    E -- No --> G[front = (front + 1) % SIZE];
    F --> H[Display removed value];
    G --> H;
    C --> I[End];
    H --> I;
```

-----

### 🌐 Industrial Relevance

Circular queues are fundamental in systems where buffering data is necessary and resources (memory) must be used efficiently.

  * **Operating Systems (OS)**: Used for managing **job scheduling** and CPU time slicing (Round Robin scheduling).
  * **Networking Buffers**: Essential in routers and network interfaces to handle incoming and outgoing data packets in a fixed-size buffer, ensuring old packets are efficiently overwritten by new ones.
  * **Traffic Management**: In real-time data streaming and event processing, they manage event queues to process items in order while controlling memory usage.

-----

### ⚙️ Tools Used

  * **Language**: C++
  * **Compiler**: g++
  * **Environment**: Any C++ IDE (e.g., VS Code, Code::Blocks)
