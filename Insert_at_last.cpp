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
    last=first;
    for (int i = 1; i < n; i++)
    {
        temp = new Node();
        temp->data = arr[i];
        temp->next = NULL;
        last->next=temp;
        last=temp;
    }
}
void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "NULL";
}
void insert_at_end(int ele){
    Node *temp=new Node();
    Node *last;
    temp->data=ele;
    temp->next=NULL;
    if(first==NULL){
        first=temp;
    }else{
        last=first;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=temp;
    }
}
int main()
{
    int n;
    cout << "Enter the size of linked list:-";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in linked list:-";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    create(arr, n);
    display(first);
    cout<<"Enter the element:-";
    int ele;
    cin>>ele;
    insert_at_end(ele);
    display(first);
}