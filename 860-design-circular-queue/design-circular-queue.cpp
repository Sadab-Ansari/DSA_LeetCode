class MyCircularQueue {
public:
    vector<int> q;

    int front;
    int rear;
    int size;
    int capacity;

    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);

        front = 0;
        rear = -1;
        size = 0;
    }

    bool enQueue(int value) {

        // Queue full
        if (isFull())
            return false;

        // Move rear circularly
        rear = (rear + 1) % capacity;

        q[rear] = value;

        size++;

        return true;
    }

    bool deQueue() {

        // Queue empty
        if (isEmpty())
            return false;

        // Move front circularly
        front = (front + 1) % capacity;

        size--;

        return true;
    }

    int Front() {

        if (isEmpty())
            return -1;

        return q[front];
    }

    int Rear() {

        if (isEmpty())
            return -1;

        return q[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};