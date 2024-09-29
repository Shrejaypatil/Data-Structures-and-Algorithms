
#include <iostream>
#include <stack>

using namespace std;

void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(num);
}

void insertAtMid(stack<int> &st, int cnt, int n, int x)
{
    if (cnt == n / 2)
    {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    insertAtMid(st, cnt + 1, n, x);

    st.push(num);
}

void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int num = st.top();
    st.pop();

    reverse(st);

    insertAtBottom(st, num);
}

void sorted(stack<int> &s, int num)
{
    if (s.empty() || (s.empty() || s.top() < num))
    {
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    sorted(s, num);

    s.push(n);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int num = st.top();
    st.pop();

    sortStack(st);

    sorted(st, num);
}

int main()
{

    stack<int> st;

    st.push(3);
    st.push(5);
    st.push(9);
    st.push(2);
    st.push(4);

    display(st);

    insertAtBottom(st, 10);

    display(st);

    int n = st.size();

    insertAtMid(st, 0, n, 100);

    display(st);

    reverse(st);

    display(st);

    sortStack(st);

    display(st);

    return 0;
}
