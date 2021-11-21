# include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		
		Node()        // initializing using constructer
		{
			data = 0;
			next = NULL;
		}
		
		Node(int d)   // storing the user data
		{
			data = d;
		}
};

class SinglyLL
{
	public:
		Node* head;
		
		SinglyLL()
		{
			head = NULL;
		}
		
		SinglyLL(Node* n)
		{
			head = n;
		}
		
		
		void AppendNode(Node* n)
		{
			if(head == NULL)
			{
				head = n;
				cout<<"Node is appended \n";
			}
			
			
			
			else
			{
				Node* temp = head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				
				temp->next = n;
				cout<<"Node is appended \n";
			}
		}
		
		void Prepend(Node* n)
		{
			if(head == NULL)
			{
				head = n;
				cout<<"Node is prepended \n";
			}
			
			else
			{
				n->next = head;
				head = n;
				cout<<"Node is prepended \n";
			}
		}
		
		void InsertAtIndex(int k, Node* n)
		{
			int count = 1;
			if(head == NULL)
			{
				cout<<"LL is Empty \n";
			}
			
			else
			{
				Node* temp = head;
				while(count<k-1)
				{
					temp = temp->next;
					count++;
				}
	
				n->next = temp->next;
				temp->next = n;
				cout<<"node inserted at the given index \n";
			}
		}
		
		void PrintLL()
		{
			
			if(head == NULL)
			{
				cout<<"LL is Empty \n";
			}
			
			else
			{
				cout<<"\nSingly Linked List is : "<<endl;
				Node* temp = head;
				
				cout<<"Head-->";
				while(temp!=NULL)
				{
					cout<<"["<<temp->data<<"]--->";
					temp = temp->next;
				}
				cout<<"NULL"<<endl;
			}
			
		}
};

int main()
{
	SinglyLL s;
	int opt,k1,k2;
	
	do
	{
		cout<<"\nSelect Option or Enter 0 to exit"<<endl;
		cout<<"1. Append_Node()"<<endl;
		cout<<"2. Prepend_Node()"<<endl;
		cout<<"3. Insert_Node_at_Index()"<<endl;
		cout<<"4. Print_Node()"<<endl;
		cout<<"5. Clear_Screen"<<endl;
		
		cin>>opt;
		Node* n1 = new Node();
		
		switch(opt)
		{
			case 0:
				break;
			
			case 1:
				cout<<"Enter the data of the node to be appended : ";
				cin>>k1;
				n1->data = k1;
				s.AppendNode(n1);
				break;
			case 2:
				cout<<"Enter the data of the node to be prepended : ";
				cin>>k1;
				n1->data = k1;
				s.Prepend(n1);
				break;
			case 3:
				cout<<"Enter the index of the node to be inserted : ";
				cin>>k1;
				cout<<"\nEnter the data of the node to be inserted : ";
				cin>>k2;
				n1->data = k2;
				
				if(k1==1 or k1==0) { s.Prepend(n1); }
				else{ s.InsertAtIndex(k1,n1); }
				
				break;
			case 4:
				s.PrintLL();
				break;
			case 5:
				system("cls");
				break;
			
			default :
				cout<<"enter the valid option number";
				
		}
	}while(opt!=0);
	
	return 0;
}