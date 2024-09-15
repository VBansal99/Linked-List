#include <bits/stdc++.h>
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
void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << endl;
}
void max_element(Node *calc)
{
    int maxi = INT_MIN;
    while (calc != NULL)
    {
        maxi = max(maxi, calc->data);
        calc = calc->next;
    }
    cout << "Maximum Element in the linked list is:-" << maxi << endl;
}
int main()
{
    int n;
    cout << "Enter the Size of Linked List:-";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    create(arr, n);
    display(first);
    max_element(first);
}