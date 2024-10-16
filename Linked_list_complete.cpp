#include <iostream>
#include <chrono>
#include <thread>
class Node{
public:
    int data;
    Node *next;
}*first=NULL;


auto lamdaDisplay=[](Node *p)->void{
    while(p!=NULL){
        std::cout<<p->data<<"->";
        p=p->next;
    }
    std::cout<<"NULL"<<std::endl;
};

auto countingNodes=[](Node *p)->void{
    int count=0;
    while(p!=NULL){
        p=p->next;
        count++;
    }
    std::cout<<"The Number of nodes in the linked list is:-"<<count<<std::endl;
};

auto sumOfLinkedList = [](Node *p)->int{
    long long sum=0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    return sum;   
};

auto maximumElement = [](Node *p)->int{
    long long maxi=0;
    while(p!=NULL){
        if(p->data>maxi)
        maxi=p->data;
        p=p->next;
    }
    return maxi;
};

auto searchInLinkedList = [](Node *p)->void{
    int element=0;
    bool found=false;
    std::cout<<"Enter the element you want to search in the linked list:-";
    std::cin>>element;
    int i=1;
    while(p!=NULL){
        if(p->data==element){
            found=true;
        std::cout<<"Element is present"<<std::endl;
        std::cout<<"Element present at "<<i<<" postion"<<std::endl;
        break;
        }
        p=p->next;
        i++;
    }
    if(!found){
            found=false;
            std::cout<<"Element is not present"<<std::endl;
        }
};

void insertatHead(Node *p){
    Node *temp=new Node();
    int element=0;
    std::cout<<"Enter the element you want to insert at head:-";
    std::cin>>element;
    temp->data=element;
    temp->next=first;
    first=temp;
}

void insertatLast(Node *p){
    Node *temp =new Node();
    int element=0;
    std::cout<<"Enter the element you want to insert at end:-";
    std::cin>>element;
    temp->data=element;
    temp->next=NULL;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;
}

void insertatPosition(Node *p){
    int pos=0;
    std::cout<<"Enter the position where you want to insert the element:-";
    std::cin>>pos;
    int element=0;
    std::cout<<"Enter the element you want to insert:-";
    std::cin>>element;
    if(pos<0)
    std::cout<<"Invalid position";
    Node *temp=new Node();
    temp->data=element;
    if(pos==0){
        temp->next=first;
        first=temp;
    }else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}

auto checkIfListIsSortedorNot = [](Node *p)->bool{
    int mini=00000;
    while(p!=NULL){
        if(p->data<mini)
        return false;
        else{
        mini=p->data;
        p=p->next;
        }
    }
    return true;
};

void removeDuplicates(Node *p){
    while(p!=NULL){
        p=p->next;
        
    }
}

// void display(Node *p){
//     while(p!=NULL){
//         std::cout<<p->data<<"->";
//         p=p->next;
//     }
//     std::cout<<"NULL"<<std::endl;
// }
void menu(){
    int choice=0;
    long long result=0;
    long long max=0;
    bool isSorted=false;
    std::cout<<"1. Display Linked list"<<std::endl;
    std::cout<<"2. Counting nodes in Linked list"<<std::endl;
    std::cout<<"3. Sum of all elements in Linked list"<<std::endl;
    std::cout<<"4. Maximum element in Linked list"<<std::endl;
    std::cout<<"5. Search in a Linked List"<<std::endl;
    std::cout<<"6. Insert at head in Linked list"<<std::endl;
    std::cout<<"7. Insert at last in Linked list"<<std::endl;
    std::cout<<"8. Insert a position in Linked list"<<std::endl;
    std::cout<<"9. Check if Linked list is Sorted or not"<<std::endl;
    std::cout<<"10. Remove duplicates from Sorted linked list"<<std::endl;
    std::cout<<"11. Reverse a Linked list"<<std::endl;
    std::cout<<"12. Concatinate a Linked list"<<std::endl;
    std::cout<<"13. Merging a Linked list"<<std::endl;
    std::cout<<"14. Check Loop in Linked list"<<std::endl;
    std::cout<<"15. Remove Loop from Linked list"<<std::endl;
    std::cout<<"16. Add Two Numbers in a Linked list"<<std::endl;
    std::cout<<"17. Remove Nth Node from the end of the Linked list"<<std::endl;
    std::cout<<"18. Remove Linked list element"<<std::endl;
    std::cout<<"19. Design Linked list"<<std::endl;
    std::cout<<"20. Delete Nodes from the Linked list present in Array"<<std::endl; 
    while(true){
    std::cout<<"Enter your choice:-";
    std::cin>>choice;
    switch(choice){
        case 1:
            std::cout<<"Display Linked list"<<std::endl;
            lamdaDisplay(first);
            break;
        case 2:
            std::cout<<"Counting Nodes in a Linked list"<<std::endl;
            countingNodes(first);
            break;
        case 3:
            std::cout<<"Sum of all elements in the linked list is"<<std::endl;
            result=sumOfLinkedList(first);
            std::cout<<"Sum of all elements in the linked list is:-"<<result<<std::endl;
            break;
        case 4:
            std::cout<<"Maximum Element in the linked list"<<std::endl;
            max=maximumElement(first);
            std::cout<<"Maximum Element in the Linked list is:-"<<max<<std::endl;
            break;
        case 5:
            std::cout<<"Search for the element in the Linked list"<<std::endl;
            searchInLinkedList(first);
            break;
        case 6:
            std::cout<<"Insert at head in Linked list"<<std::endl;
            insertatHead(first);
            lamdaDisplay(first);
            break;
        case 7:
            std::cout<<"Insert at end in Linked list"<<std::endl;
            insertatLast(first);
            lamdaDisplay(first);
            break;
        case 8:
            std::cout<<"Enter the element at position"<<std::endl;
            insertatPosition(first);
            lamdaDisplay(first);
            break;    
        case 9:
            std::cout<<"Check if linked list is Sorted or Not:-"<<std::endl;
            isSorted=checkIfListIsSortedorNot(first);
            lamdaDisplay(first);
            if(isSorted)
            std::cout<<"Linked List is Sorted"<<std::endl;
            else
            std::cout<<"Linked List is not Sorted"<<std::endl;
            break;
        case 10:
            std::cout<<"Remove Duplicated from the Linked List"<<std::endl;

        default:
        std::cout<<"Invalid choice"<<std::endl;
        break;
    }
    }
}

void createLinkedList(int arr[],int n){
    first=new Node();
    Node *last=NULL;
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        Node *temp=new Node();
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}
int main(){
int n;
    std::cout << "Enter the size of Linked list:- ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter the elements in the Linked list:- ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout<<std::endl;
    createLinkedList(arr,n);
    menu();
}