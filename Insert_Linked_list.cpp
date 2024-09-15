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

void insert(Node *p, int element, int pos)
{
    // Create a Node
    if (pos < 0){
        cout << "Invalid Postion";
    return;
    }
    Node *temp = new Node();
    temp->data = element;
    if (pos == 0)
    {
        temp->next = first;
        first = temp;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
}
int main()
{
    int n;
    cout << "Enter the size of Linked List:-";
    cin >> n;
    int arr[n];
    cout << "Enter elements in Linked List:-";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int pos;
    cout << "Enter the Postion where u want to insert element:-";
    cin >> pos;
    int element;
    cout << "Enter the Element you want to insert:-";
    cin >> element;
    create(arr, n);
    insert(first, element, pos);
    display(first);
}