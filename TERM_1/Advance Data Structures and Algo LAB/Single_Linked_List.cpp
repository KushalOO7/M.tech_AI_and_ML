# include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node* next;

  Node() // initializing using constructor
  {
    data = 0;
    next = NULL;
  }
  Node(int d)  // storing user data in node
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
    head=NULL;
  }
  SinglyLL(Node* n) 
  {
    head=n;
  }

// Appending
  void AppendNode(Node* n)
   {
	  if (head==NULL) 
	  {
        head=n;
        cout<<"Node Appended :"<<endl;
      } 
	  else 
	  {
        Node* temp = head;
        while (temp->next!=NULL) 
		{
          temp=temp->next;
        }
        temp->next=n;
        cout<<"Node Appended"<<endl;
      }
  }
  
  // Prepending
  void PrependNode(Node* n) 
  {
  	if (head==NULL) 
	  {
        head=n;
        cout<<"Node Prepended :"<<endl;
      }
      else
	  {
      n->next=head;
      head=n;
      cout << "Node Prepended" << endl;
      }
  }

  // Inserting a Node at a particular index in the list
  void InsertNodeIndex(int k, Node* n) 
  {
  	int count=1;
  	if(head==NULL)
  	{
  	    cout<<"LL is Empty"<<endl;
  	    return;
	}
	else
	{
	Node* temp=head;
  	while(count<k-1)
	{
  		temp=temp->next;
  		count++;
	}
    n->next=temp->next;
    temp->next=n;
    
    cout<<"Node Inserted at index "<<k<<endl;
}
  }

// printing
  void PrintLL() 
  {
    if (head == NULL) 
	{
      cout<<"No Nodes in Singly Linked List";
    } 
	else 
	{
      cout<<endl<<"Singly Linked List : ";
      Node* temp = head;
      
      cout<<"Head-->";
      while(temp!=NULL) 
	  {
        cout<<"["<<temp->data<<"]-->";
        temp=temp->next;
      }
      
      cout<<"NULL"<<endl;
    }

  }
  
  // Deletion (de-Linking the node)
  void Deletion(int n)
  {
  	if(head==NULL)
  	{
  		cout<<"Singly LL is already Empty"<<endl;
	}
	else
	{
		// searching the data node
		Node* prev = NULL;
		Node* ptr = head;
		while(ptr!=NULL)
		{
			if(ptr->data==n)
			{
				if(prev==NULL){ head=head->next; ptr->next=NULL; return;}
		        prev->next = ptr->next;
		        ptr->next = NULL;
			}
			else
			{
				cout<<"data Node not Found: enter the valid data to delete"<<endl;
			}
			prev=ptr;
			ptr=ptr->next;
		}
	}
  }
  
  // Sorting
  void SortingLL()
  {
  	Node *ptr = head;
  	int count=0;
  	if(head==NULL){ cout<<"Singly LL is Empty"<<endl; }
  	else
	  {
	  	while(ptr!=NULL){ ptr=ptr->next; count+=1; }
	  	int c = 0;
	  		
	  	while(c<count)
		{ 
	  	ptr = head->next;
	  	Node* prev = head;
	  	int temp;
	    
		while(ptr!=NULL)
		  {
		  	
		  	if(prev->data > ptr->data)
		  	{
		  	   	temp = prev->data;
		  	   	prev->data = ptr->data;
		  	   	ptr->data = temp;
			}
		  	prev=ptr;
		    ptr=ptr->next;
		    
		  }
		  c++;
	     }  
	  
	  } 
  }
  
  // searching
  void Searching(int val)
  {
  	if(head==NULL){ cout<<"Singly LL is Empty"<<endl; }
  	else
	  {
  		Node* ptr = head;
  		int flag = 0;
  		int count = 1;
  		while(ptr!=NULL)
		{
			if(ptr->data==val)
			{
			  cout<<"Value "<<val<<" is Found in Singly Linked List at the index "<<count<<endl;
			  flag = 1;
			}
			ptr = ptr->next;
			count+=1;
	    }
	    if(flag==0)
			{
			  cout<<"Value "<<val<<" is not Found in Singly Linked List "<<endl;
			}
	  }
  }

};

int main() 
{
  SinglyLL s;
  int option;
  int k1, data1;
  do
   {
    cout<<"\nSelect Option number. Enter 0 to exit"<<endl;
    cout<<"1. AppendNode()" << endl;
    cout<<"2. PrependNode()" << endl;
    cout<<"3. InsertNodeIndex()" << endl;
    cout<<"4. Deletion()" << endl;
    cout<<"5. SortingLL()" << endl;
    cout<<"6. Searching()" << endl;
    cout<<"7. Print()" << endl;
    cout<<"8. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout<<"Appending \nEnter data of the Node to be Appended ="<<endl;
      cin>>data1;
      n1->data=data1;
      s.AppendNode(n1);
      break;

    case 2:
      cout<<"Prepending \nEnter data of the Node to be Prepended ="<<endl;
      cin>>data1;
      n1->data=data1;
      s.PrependNode(n1);
      break;

    case 3:
      cout<<"Insert Node at particular index\nEnter index where you want to Insert this New node:"<<endl;
      cin>>k1;
      cout<<"Enter data of the New Node :"<<endl;
      cin>>data1;
      n1->data=data1;
      s.InsertNodeIndex(k1, n1);
      break;
      
    case 4:
    	cout<<"Deleting Node \nEnter the data of the node which you want to delete :"<<endl;
    	cin>>data1;
    	s.Deletion(data1);
    	break;
    
    case 5:
    	cout<<"Sorted Singly Linked List is : "<<endl;
    	s.SortingLL();
    	s.PrintLL();
    	break;
    
	case 6:
		cout<<"Enter the value of the node to be searched :"<<ends;
		cin>>data1;
		s.Searching(data1);
		break;
		
    case 7:
      s.PrintLL();
      break;
    
	case 8:
      system("cls");
      break;
      
    default:
      cout<<"Enter Valid Option number "<<endl;
    }

  } while(option!=0);

  return 0;
}