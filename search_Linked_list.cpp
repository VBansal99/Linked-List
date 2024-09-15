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

void display(Node *p){
    cout<<"Elements in Linked List are:-";
    while(p!=NULL){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<endl;
}
void search(Node *find, int k){
    bool found =false;
    while(find!=NULL){
        if(k==find->data){
            found=true;
            cout<<"Element is Present"<<endl;
            break;
        }
        find=find->next;
    }
    if(!found)
        cout<<"Elements are not found"<<endl;
}
int main()
{
    int n;
    cout << "Enter the size of Linked list:-";
    cin >> n;
    cout<<endl;
    int arr[n];
    cout << "Enter the Elements of Linked list:-";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<endl;
    int key;
    cout<<"Element to be search in linked list:-";
    cin>>key;
    cout<<endl;
    create(arr, n);
    display(first);
    search(first,key);
}