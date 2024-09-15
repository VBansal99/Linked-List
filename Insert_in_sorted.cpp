#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

void create(int arr[], int n)
{
    Node *temp, *last;
    first = new Node();
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = new Node();
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void insert(Node *ins, int x)
{
    Node *q = NULL;
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        while (ins && ins->data < x)
        {
            q = ins;
            ins = ins->next;
        }
        if (ins == first)
        {
            temp->next = first;
            first = temp;
        }
        else
        {
            temp->next = q->next;
            q->next = temp;
        }
    }
}

void display(Node *traverse)
{
    while (traverse != NULL)
    {
        cout << traverse->data << "->";
        traverse = traverse->next;
    }
}

int main()
{
    int n;
    cout << "Enter the Size of Array:-";
    cin >> n;
    int arr[n];
    cout << "Enter the Elements in Array:-";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ele;
    cout << "Enter the Element to insert in a list:-";
    cin >> ele;
    create(arr, n);
    insert(first, ele);
    display(first);
}