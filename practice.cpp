// Create a Linked List
// Count Nodes in a Linked list
// Sum of elements in Linked list
// Maximum element in Linked list
// Searching in a Linked list
// Insert at Head in Linked list
// Insert at end in Linked list
// Insert at specific position
// Insert in a sorted linked list
#include <iostream>
#include <math.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

void insert_in_sorted()
{
    int data = 0;
    cout << "Enter the element you want to insert:-";
    cin >> data;
    Node *temp;
    temp = new Node();
    temp->data = data;
    if (first == NULL || first->data > data)
    {
        temp->next = first;
        first = temp;
    }
    else
    {
        Node *q = first;
        while (q->next != NULL && q->next->data < data)
        {
            q = q->next;
        }
        temp->next = q->next;
        q->next = temp;
    }
}

void insert_at_position(Node *p)
{
    int position = 0;
    cout << "Enter the position where you want to insert Node:-";
    cin >> position;
    int element = 0;
    cout << "Enter the element you want to insert:-";
    cin >> element;
    Node *temp = new Node();
    temp->data = element;
    if (position < 0)
    {
        cout << "Invalid position";
        return;
    }
    else
    {
        for (int i = 0; i < position - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void insert_at_end()
{
    Node *temp, *last;
    int data = 0;
    cout << "Enter the element you want to insert:-";
    cin >> data;
    temp = new Node();
    temp->data = data;
    temp->next = NULL;
    Node *track;
    track = first;
    if (first == NULL)
    {
        first = temp;
    }
    while (track->next != NULL)
    {
        track = track->next;
    }
    track->next = temp;
}
void insert_at_head()
{
    Node *temp;
    int element = 0;
    cout << "Enter the element you want to insert:-";
    cin >> element;
    temp = new Node();
    temp->data = element;
    temp->next = NULL;
    temp->next = first;
    first = temp;
}
void search_in_linked_list(Node *p, int data)
{
    bool flag = 0;
    while (p != NULL)
    {
        if (p->data == data)
        {
            flag = 1;
            cout << "Element found" << endl;
            break;
        }
        p = p->next;
    }
    if (!flag)
        cout << "Element not found" << endl;
}
int maximum_element(Node *p)
{
    int maxi = 0;
    while (p != NULL)
    {
        maxi = max(maxi, p->data);
        p = p->next;
    }
    return maxi;
}
int sum_of_elements(Node *p)
{
    long long sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int count_Nodes(Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
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
    cout << "Enter the elements of the linked list:-";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int data = 0;
    cout << "Enter the element you want to search in the linked list:-";
    cin >> data;
    create_linked_list(arr, n);
    display_linked_list(first);
    cout << "Number of nodes are:-" << count_Nodes(first) << endl;
    cout << "Sum of all elements in linked list:-" << sum_of_elements(first) << endl;
    cout << "Maximum element in the linked list is:-" << maximum_element(first) << endl;
    search_in_linked_list(first, data);
    insert_at_head();
    display_linked_list(first);
    insert_at_end();
    display_linked_list(first);
    insert_at_position(first);
    display_linked_list(first);
    insert_in_sorted();
    display_linked_list(first);
}