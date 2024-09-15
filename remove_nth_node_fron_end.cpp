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
Node *displayLinkedList(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    return p;
}

Node *removeNthLastNode()
{
    int n;
    cout << "Enter the position you want to remove from the last:-";
    cin >> n;
    Node *firstOne = first;
    Node *secondOne = first;
    while (n > 0)
    {
        firstOne = firstOne->next;
        if (firstOne == NULL)
            return first->next;
        n--;
    }
    while (firstOne->next != NULL)
    {
        firstOne = firstOne->next;
        secondOne = secondOne->next;
    }
    secondOne->next = secondOne->next->next;

    return first;
}
int main()
{
    int n;
    cout << "Enter the size of the linked list:-";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in the linked list:-";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    create_linked_list(arr, n);
    Node *displayData = displayLinkedList(first);
    cout<<endl;
    removeNthLastNode();
    cout<<endl;
    displayLinkedList(first);
}