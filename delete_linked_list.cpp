#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

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
void delete_head_linked_list(Node *&p)
{
    if (p == NULL)
        return;
    Node *temp = p;
    p = p->next;
    delete temp;
}
void delete_linked_list_at_pos()
{
    int pos = 0;
    cout << "Enter the position from where you want to delete the linked list:-";
    cin >> pos;
    Node *temp = first;
    Node *q;
    if (pos == 1)
    {
        delete_head_linked_list(temp);
        return;
    }
    else
    {
        for (int i = 1; i < pos && temp != NULL; i++)
        {
            q = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        q->next = temp->next;
        delete temp;
    }
}
void delete_last_node(Node *p)
{
    if (p == NULL)
        return;
    if (p->next == NULL)
    {
        delete p;
        p = NULL;
        return;
    }
    Node *temp = p;
    Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
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
    delete_head_linked_list(first);
    display_linked_list(first);
    delete_linked_list_at_pos();
    display_linked_list(first);
    delete_last_node(first);
    display_linked_list(first);

    return 0;
}