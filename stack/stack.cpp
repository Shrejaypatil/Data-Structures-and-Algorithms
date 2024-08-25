/*
what is stack:

its a linear data structure where the data is managed with LIFO fashion that is
Last in first out. to understand it better take a real life example of plates kept
on one another.

real world ex:

1. Process scheduling
2. undo
3. back button in web browsers

Operations: PUSH, POP, PEEK, ISEMPTY, ISFULL

*/

#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    int *arr;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // stack operations

    bool isEmpty()
    {
        if (top == -1)
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
        if (top >= size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    int pop()
    {
        int popVal;
        if (isEmpty())
        {
            cout << "Stack Underflow " << endl;
            return 0;
        }
        else
        {
            popVal = arr[top];
            top--;
        }
        return popVal;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        else
        {
            cout << "Element at top is: " << arr[top] << endl;
            return;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        else
        {
            cout << "--------" << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
            cout << "--------";
            cout << endl;
        }
    }
};

int main()
{
    Stack st(5);

    st.display();

    st.peek();

    st.push(10);

    st.display();

    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st.display();

    cout << "Deleting: " << st.pop() << endl;

    st.display();

    st.push(50);
    st.push(60);

    st.peek();
    st.display();

    cout << "Deleting: " << st.pop() << endl;
    cout << "Deleting: " << st.pop() << endl;
    cout << "Deleting: " << st.pop() << endl;
    cout << "Deleting: " << st.pop() << endl;
    cout << "Deleting: " << st.pop() << endl;

    st.display();

    cout << "Deleting: " << st.pop() << endl;
    cout << "Deleting: " << st.pop() << endl;

    return 0;
}