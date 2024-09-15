#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
}*first=NULL;

void create(int arr[],int n){
    class Node *temp, *last;
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

void display_count_sum(Node *p){
    int sum=0;
    int count=0;
    while(p!=NULL){
        count++;
        sum+=p->data;
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<endl;
    cout<<"Sum of all Elements of Linked List:-"<<sum<<endl;
    cout<<"Size of Linked List:-"<<count<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    create(arr,n);
    display_count_sum(first);
}