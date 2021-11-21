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

class CircularLL
{
  public:
  	
  Node* head;

  CircularLL() 
  {
    head=NULL;
  }
  
  CircularLL(Node* n)
  {
  	head = n;
  }
  
// Appending
  void AppendNode(Node* n)
   {
	  if (head==NULL) 
	  {
        head=n;
        head->next=head;
        cout<<"Node Appended :"<<endl;
      }
	  else
	  {
        Node* temp = head;
        while(temp->next!=head)
		{
          temp=temp->next;
        }
        temp->next=n;
        n->next=head;
        cout<<"Node Appended"<<endl;
      }
  }

// Prepending
  void PrependNode(Node* n)
   {
	  if (head==NULL) 
	  {
        head=n;
        n->next=head;
        cout<<"Node Prepended"<<endl;
      }
	  else
	  {
	  	Node* temp=head;
        while(temp->next!=head)
		{
          temp=temp->next;
        }
        
        temp->next=n;
        n->next=head;
        head=n;
        cout<<"Node Prepended"<<endl;
      }
  }
  
  // inserting Node at Particular Index
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
    
    cout<<"Node inserted at index "<<k<<endl;
}
  }
  
// Deletion (de-Linking the node)
  void Deletion(int n)
  {
  	if(head==NULL)
  	{
  		cout<<"Circular LL is already Empty"<<endl;
	}
	else
	{
		// searching the data node
		Node* tail  = head;
		while(tail->next!=head)
		{
			tail=tail->next;
		}
		
		Node* prev = NULL;
		Node* ptr = head;
		while(ptr->next!=head)
		{
			if(ptr->data==n)
			{
				if(prev==NULL)
				{
				 head=head->next; 
				 ptr->next=NULL; 
				 tail->next=head;
				 cout<<"Node is deleted"<<endl;
				 return;
				}
		        prev->next = ptr->next;
		        ptr->next = NULL;
		        cout<<"Node is deleted"<<endl;
		        return;
			}
			prev=ptr;
			ptr=ptr->next;
		}
		
		if(ptr->data==n){ prev->next=ptr->next; ptr->next=NULL; cout<<"Node is deleted"<<endl; }
		else{ cout<<"Given Data not found in Circular LL . Please enter valid data"<<endl; }
	}
  }
  
  // Searching
  void Searching(int n)
  {
  	int count=1;
  	if(head==NULL){ cout<<"Circular LL is empty"<<endl; }
  	else
  	{
  	  Node* temp = head;
	  do
	  {
	  	if(temp->data==n)
	  	{
	  		cout<<"data found at index ["<<count<<"] in Circular LL "<<endl; return;
		}
		temp=temp->next;
		count++;
	  } while(temp!=head);
	  
	  cout<<"data not found. Enter the valid data to be found"<<endl;
	}
  }
  
  // Sorting
  void Sorting()
  {
  	Node *ptr = head;
  	int count=1;
  	if(head==NULL){ cout<<"Circular LL is Empty"<<endl; return; }
  	else
	  {
	  	while(ptr->next!=head){ ptr=ptr->next; count+=1; }
	  	int c = 1;
	  		
	  	while(c<=count)
		{
	  	ptr = head->next;    // for next node CirLL[i+1]
	  	Node* prev = head;   // for previous node CirLL[i]
	  	int temp;
	    
		while(ptr!=head)     // Using Bubble Sort
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
  
  // Printing Circular LL
  void PrintLL() 
  {
    if (head==NULL) 
	{
      cout<<"No Nodes in Circular Linked List";
    } 
	else 
	{
      cout<<endl<<"Circular Linked List : ";
      Node* temp = head;
      
      cout<<"Head-->";
      
      do 
	  {
        cout<<"["<<temp->data<<"]-->";
        temp=temp->next;
      } while(temp!=head);
      
      cout<<"Head"<<endl;
    }
  }
  
 };

int main()
{
  CircularLL c;
  int option;
  int k1,data1;
  do
   {
    cout<<"\nSelect Option number or Press 0 to exit"<<endl;
    cout<<"[1] AppendNode()" << endl;
    cout<<"[2] PrependNode()" << endl;
    cout<<"[3] InsertNodeIndex()" << endl;
    cout<<"[4] Deletion()" << endl;
    cout<<"[5] Searching()" << endl;
    cout<<"[6] Sorting()" << endl;
    cout<<"[7] Print()" << endl;
    cout<<"[8] Clear Screen" << endl << endl;

    cin >> option;
    Node* n1 = new Node();
    //Node n1;

    switch (option) 
	{
	
    case 0:
      break;
      
    case 1:
      cout<<"Enter data of the Node to be Appended ="<<endl;
      cin>>data1;
      n1->data=data1;
      c.AppendNode(n1);
      break;
		
	case 2:
	  cout<<"Enter data of the Node to be Prepended ="<<endl;
      cin>>data1;
      n1->data=data1;
      c.PrependNode(n1);
      break;
		
    case 3:
      cout<<"Insert Node at particular index\nEnter index where you want to Insert this New node:"<<endl;
      cin>>k1;
      cout<<"Enter data of the New Node :"<<endl;
      cin>>data1;
      n1->data=data1;
      if(k1=1){ c.PrependNode(n1); cout<<"Node inserted at index "<<k1<<endl;}
      else{ c.InsertNodeIndex(k1, n1); }
      break;
	  	
    case 4:
    	cout<<"Enter the data of the node which you want to delete :"<<endl;
    	cin>>data1;
    	c.Deletion(data1);
    	break;
    
	case 5:
    	cout<<"Enter the data of the node which you want to search :"<<endl;
    	cin>>data1;
    	c.Searching(data1);
    	break;	
	
	case 6:
		cout<<"Circular LL is (SORTED) :"<<endl;
		c.Sorting();
		c.PrintLL();
		break;
			
    case 7:
      c.PrintLL();
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