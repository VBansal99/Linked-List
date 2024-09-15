#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

void add_two_linked_list(Node *l1, Node *l2)
{
    int res = 0;
    long long sum = 0;
    Node *result = NULL;
    Node *temp, *last;
    while (l1 != NULL || l2 != NULL)
    {
        sum = res;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }
            res = sum / 10;
            sum = sum % 10;
        
        temp = new Node();
        temp->data = sum;
        temp->next = NULL;
        if (result == NULL)
        {
            result = temp;
            last = result;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    if(res>0){
        temp= new Node();
        temp->data=res;
        last->next=temp;
    }

    while (result != NULL)
    {
        cout << result->data << "->";
        result = result->next;
    }
}

Node *create_linked_list(int arr[], int n)
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
    cout << "NULL";
    return first;
}
void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
}
void enter_the_elements(int arr[], int n)
{
    cout << "Enter the elements of list:-";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}
int main()
{
    int size_of_list1;
    int size_of_list2;
    cout << "Enter the size of List 1:-";
    cin >> size_of_list1;
    cout << "Enter the size of list 2:-";
    cin >> size_of_list2;
    int l1[size_of_list1];
    int l2[size_of_list2];
    enter_the_elements(l1, size_of_list1);
    enter_the_elements(l2, size_of_list2);
    Node *first1 = create_linked_list(l1, size_of_list1);
    Node *first2 = create_linked_list(l2, size_of_list2);
    cout << "List1:- ";
    display(first1);
    cout << endl;
    cout << "List2:- ";
    display(first2);
    cout << endl;

    add_two_linked_list(first1, first2);

    return 0;
}