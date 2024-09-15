#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
}*first=NULL;

void create_linked_list(int arr[],int n){
    Node *temp,*last;
    first=new Node();
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        temp=new Node();
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}
Node* display_linked_list(Node* p){
    while(p!=NULL){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
    return p;
}
void rotate_by_k(Node *p){
    int k=0;
    cout<<"Number of times you want to rotate linked list:-";
    cin>>k;
    int length=0;
    while(p!=NULL){
        p=p->next;
        length++;
    }
    k=k%length;
    if(k==0)
    return;

    p->next=first;
    int stop=length-k;
    for(int i=1;i<stop;i++){
        p=p->next;
    }
}
int main(){
    int n;
    cout<<"Enter the size of the linked list:-";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the linked list:-";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    create_linked_list(arr,n);
    Node* display_data=display_linked_list(first);
    rotate_by_k(first);
    display_linked_list(first);
}