#include<iostream>
using namespace std;
struct Node 
{
int data;
struct Node *next;
};

struct Node* head = NULL;

void insert(int newdata) 
{
struct Node *n = (struct Node *)malloc(sizeof(struct Node));
struct Node *temp = head;
n->data = newdata;
n->next = head;
if (head!= NULL) 
{
while (temp->next!=head){ temp=temp->next; }
temp->next=n;
} 
else
{
head=n;
n->next=head;
}
}

void display() 
{
struct Node* temp = head;
do 
{
cout<<temp->data <<" ";
temp=temp->next;
} while(temp!=head);

}
int main() 
{
int n;
cout<<"Enter the number of nodes you want to insert : ";
cin>>n;
int data1;

cout<<"Enter the data of that nodes to be appended : ";
for(int i=1;i<=n;i++)
{
cin>>data1;
insert(data1);
}

cout<<"The circular linked list is: ";
display();
}