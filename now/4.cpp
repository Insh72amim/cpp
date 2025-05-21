#include <bits/stdc++.h>
using namespace std;

void printsome(int x)
{
    cout << x << " ";
}

class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    Node *head = new Node(5);
    int *arr = new int[10];
    delete head;
    delete[] arr;

    return 0;
}