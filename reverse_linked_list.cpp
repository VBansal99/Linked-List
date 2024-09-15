#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

Node *reverse_linked_list(Node *p)
{
    if (p == NULL)
    {
        cout << "List is empty";
        return p;
    }
    Node *current = p;
    Node *prev = NULL;
    Node *q = NULL;
    while (current != NULL)
    {
        q = prev;
        prev = current;
        current = current->next;
        prev->next = q;
    }
    return prev;
}
void create_linked_list(int arr[], int n)
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

void display_linked_list(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    int n;
    cout << "Enter the size of the linked list:-";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in the linked list:-";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    create_linked_list(arr, n);
    display_linked_list(first);
    first = reverse_linked_list(first);
    display_linked_list(first);
}