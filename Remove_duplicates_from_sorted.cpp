#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
}*first=NULL;
int remove_duplicates_from_sorted_linked_list(Node *p){
    int result=0;
    if(p==NULL)
    return result;
    Node *current=p->next;
    Node *prev=p;
    while(current!=NULL){
        if(current->data!=prev->data){
            prev=current;
            current=current->next;
        }else{
            prev->next=current->next;
            result=current->data;
            delete current;
            current=prev->next;
        }
    }
    return result;
}
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
void display_linked_list(Node *p){
    while(p!=NULL){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    int n;
    cout<<"Enter the size of the linbked list:-";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the linked list:-";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    create_linked_list(arr,n);
    display_linked_list(first);
    cout<<remove_duplicates_from_sorted_linked_list(first)<<endl;
    display_linked_list(first);
    return 0;
}