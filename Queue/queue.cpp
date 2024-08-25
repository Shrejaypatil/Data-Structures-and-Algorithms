#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front, rear, size;

public:
    Queue(int s)
    {
        this->size = s;
        front = rear = -1;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    // operations: empty, full, insert, delete , count, display

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (rear == (size - 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enque(int data)
    {
        if (isFull())
        {
            cout << "queue is Full"
                 << "\n";
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    int deque()
    {
        int popVal;
        if (isEmpty())
        {
            cout << "Queue is Empty"
                 << "\n";
            return -1;
        }
        else if (front == rear)
        {
            popVal = arr[front];
            arr[front] = 0;
            front = rear = -1;
        }
        else
        {
            popVal = arr[front];
            arr[front] = 0;
            front++;
        }
        return popVal;
    }

    int count()
    {
        if(isEmpty())
        {
            cout<<"queue is empty"<<"\n";
            return (front-rear);
        }
        return (rear - front) + 1;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size, choice;
    cout << "enter size of queue"
         << "\n";
    cin >> size;

    Queue q(size);

    do
    {
        cout << "enter your choice: "
             << "\n";
        cout << "1.insert"
             << "\n";
        cout << "2.delete"
             << "\n";
        cout << "3.total elements"
             << "\n";
        cout << "4.display"
             << "\n";
        cout << "5.exit"
             << "\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "enter data: "
                 << "\n";
            cin >> data;
            q.enque(data);
            break;

        case 2:
            cout << "deleted element is: " << q.deque() << "\n";
            break;

        case 3:
            cout << "total elements in queue are: " << q.count() << "\n";
            break;

        case 4:
            cout << endl;
            q.display();
            cout << endl;
            break;

        }
    } while (choice != 5);

    return 0;
}