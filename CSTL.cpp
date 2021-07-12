//Project Name:Customized Standard Template Library

#include<iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////

//structures for STL:

//structre name: struct node1
//Description:structure for singly Linear,Singly Circular linked list,Stack,Queue.strcture consist of two members as data,and pointer as next which points to next node Of LL..
template <class T>
struct node1
{
	T data;
	struct node1 *next;
};

//structre name: struct node2
//Description:structure for doubly Linear and doubly circular linked list.strcture consist of three members as data,next pointer and prev pointer  which points to next nodeand previous node Of LL respectvely..
template <class T>
struct node2
{
	T data;
	struct node2 *next;
	struct node2 *prev;
};

///////////////////////////////////////////////////////////////////////////////////////

//classes for different data structures:

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//class Name:   SinglyLL
//Description:In this class we have two members as head pointer pointing to first node,and size varaible as a counter (to count size of nodes)..

//////////////////////////////////////////////////////////////////
template <class T>
class SinglyLL
{
	private:
		struct node1 <T> *head;
		int size;
	public:
		//Fucntion Declaration
		SinglyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,T);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(T);
		void Display();
		int Count();
		int SearchFirstOccurence(T);
};
////////////////////////////////////////////////////////

//Function Name:   Constructor
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is a Constructor for SinglyLL
//Returns:         None

////////////////////////////////////////////////////////
template <class T>
SinglyLL<T>::SinglyLL()
{
	head=NULL;
	size=0;
}
////////////////////////////////////////////////////////

//Function Name:   InsertFirst
//Function Author: Shubham Upasani
//Paramters:       Data to insert
//Description:	   This is Function to insert node at First Position
//Returns:         None

/////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
	struct node1<T> *newn=new struct node1<T>;
	
	newn->next=NULL;
	newn->data=no;
	newn->next=head;
	head=newn;
	size++;
}
////////////////////////////////////////////////////////

//Function Name:   InsertLast
//Function Author: Shubham Upasani
//Paramters:       Data to insert
//Description:	   This is Function to insert node at Last Position
//Returns:         None

/////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertLast(T no)
{
	struct node1<T> *temp=head;
	struct node1<T> *newn=NULL;
	newn=new struct node1<T>;
	newn->data=no;
	newn->next=NULL;
	if(head==NULL)   
	{
		head=newn;
	} 
	else     
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
	size++;
}

////////////////////////////////////////////////////////

//Function Name:   DeleteFirst
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Delete node at First Position
//Returns:         None

/////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteFirst()
{
	if(head==NULL)
	{
		return;
	}
	else    //1 or more than 1
	{
		struct node1<T> *temp=head;
		head=head->next;
		delete temp;
		size--;
	}
}

////////////////////////////////////////////////////////

//Function Name:   DeleteLast
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Delete node at Last Position
//Returns:         None

/////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteLast()
{
	if(head==NULL)
	{
		return;
	}
	else if(head->next==NULL)
	{
		delete head;
		head=NULL;
		size--;
	}
	else    
	{
		struct node1<T> *temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		delete temp->next;
		temp->next=NULL;
		size--;
	}
}
////////////////////////////////////////////////////////

//Function Name:   InsertAtPos
//Function Author: Shubham Upasani
//Paramters:       Data to insert and at which position to insert
//Description:	   This is Function to insert node at Given Position
//Returns:         None

/////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertAtPos(T no,T pos)
{
	T Nsize=0;
	int i=0;
	Nsize=Count();
	struct node1<T> *newn=NULL;
	struct node1<T> *temp=head;
	if((pos<1)||(pos>Nsize+1))
	{
		return;
	}
	if(pos==1)
	{
		InsertFirst(no);
		
	}
	else if(pos==Nsize+1)
	{
		InsertLast(no);
		
	}
	else
	{
		newn=new struct node1<T>;
		newn->data=no;
		newn->next=NULL;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		size++;
	}
}
////////////////////////////////////////////////////////

//Function Name:   DeleteAtPos
//Function Author: Shubham Upasani
//Paramters:       At which position You have to delete the node
//Description:	   This is Function to Delete node at Given Position
//Returns:         None

/////////////////////////////////////////////////////////


template <class T>
void SinglyLL<T>::DeleteAtPos(T pos)
{
	struct node1<T> *temp=head;
	struct node1 <T>*target=NULL;
	if((pos<1)||(pos>size+1))
	{
		return;
	}
	if(pos==1)
	{
		DeleteFirst();
	}
	else if(pos==size+1)
	{
		DeleteLast();
	}
	else
	{
		int i=0;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		target=temp->next;
		temp->next=target->next;
		delete target;
	}
	size--;
}

//Function Name:   Count
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Count the total number of Nodes present int the Linked List
//Returns:         size

/////////////////////////////////////////////////////////

template<class T>
int SinglyLL<T>::Count()
{
	return size;
}
////////////////////////////////////////////////////////

//Function Name:   Display
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Display whole Linked List
//Returns:         None

/////////////////////////////////////////////////////////


template<class T>
void SinglyLL<T>::Display()
{
	struct node1<T> *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<"\n";
}
////////////////////////////////////////////////////////

//Function Name:   SearchFirstOccurence
//Function Author: Shubham Upasani
//Paramters:       Data
//Description:	   This is Function to return the node number of given data(return the first occurence)
//Returns:         Integer

/////////////////////////////////////////////////////////

template<class T>
int SinglyLL<T>::SearchFirstOccurence(T no)
{
	int i=0;
	struct node1<T> *temp=head;
	while(temp!=NULL)
	{
		i++;
		if(temp->data==no)
		{
			break;
		}
	}
	if(temp==NULL)
	{
		return -1;
	}
	else
	{
		return i;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//class Name:   SinglyCircularLL
//Description:In case of singly circular linkde list we have two pointers..one is pointing to first //(head) node and another is pointing to last node(rear)..Due to which there names are head and tail //pointer respectively..(tail ->Next) holds the address of first(head)node..

/////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyCircularLL
{
	private:
		struct node1<T> *head;
		struct node1<T> *tail;
		int size;
	public:
		SinglyCircularLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,T);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(T);
		void Display();
		int Count();
		int SearchFirstOccurence(T);
};
////////////////////////////////////////////////////////

//Function Name:   Constructor
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is a Constructor for SinglyCircularLL
//Returns:         None

/////////////////////////////////////////////////////////
template<class T>
SinglyCircularLL<T>::SinglyCircularLL()
{
	head=NULL;
	tail=NULL;
	size=0;
}

////////////////////////////////////////////////////////

//Function Name:   InsertFirst
//Function Author: Shubham Upasani
//Paramters:       Data to insert
//Description:	   This is Function to insert node at First Position
//Returns:         None

/////////////////////////////////////////////////////////
template<class T>
void SinglyCircularLL<T>::InsertFirst(T no)
{
	struct node1<T> *newn=NULL;
	newn=new struct node1<T>;
	newn->data=no;
	newn->next=NULL;
	if((head==NULL)&&(tail==NULL)) //ll empty
	{
		head=newn;
		tail=newn;
	}
	else  //ll at least one node
	{
		newn->next=head;
		head=newn;
	}
	size++;
	tail->next=head;

}
////////////////////////////////////////////////////////

//Function Name:   InsertLast
//Function Author: Shubham Upasani
//Paramters:       Data to insert
//Description:	   This is Function to insert node at Last Position
//Returns:         None

/////////////////////////////////////////////////////////
template<class T>
void SinglyCircularLL<T>::InsertLast(T no)
{
	struct node1<T> *newn=NULL;
	newn=new struct node1<T>;
	newn->data=no;
	newn->next=NULL;
	if((head==NULL)&&(tail==NULL)) 
	{
		head=newn;
		tail=newn;
	}
	else  
	{
		tail->next=newn;
		tail=newn;
	}
	size++;
	tail->next=head;
}
////////////////////////////////////////////////////////

//Function Name:   DeleteFirst
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Delete node at First Position
//Returns:         None

/////////////////////////////////////////////////////////
template<class T>
void SinglyCircularLL<T>::DeleteFirst()
{
	if(size==0)
	{
		return;
	}
	else if(size==1)  //or head==tail
	{
		delete head; //or delete tail
		head=NULL;
		tail=NULL;
		size--;
	}
	else     //more than 1 node
	{
		head=head->next;
		delete(tail->next);
		tail->next=head;
		size--;
	}

	
	
}
////////////////////////////////////////////////////////

//Function Name:   DeleteLast
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Delete node at Last Position
//Returns:         None

/////////////////////////////////////////////////////////
template<class T>
void SinglyCircularLL<T>:: DeleteLast()
{
	if(size==0)
	{
		return;
	}
	else if(size==1)
	{
		delete head; //or delete tail
		head=NULL;
		tail=NULL;
		size--;
	}
	else
	{
		struct node1<T> *temp=head;
		int i=0;
		for(i=1;i<size-1;i++)
		{
			temp=temp->next;
		}
		delete tail;  //or delete temp->next;
		tail=temp;
		tail->next=head;
		size--;
	}
	
	
}

////////////////////////////////////////////////////////

//Function Name:   InsertAtPos
//Function Author: Shubham Upasani
//Paramters:       Data to insert and at which position to insert
//Description:	   This is Function to insert node at Given Position
//Returns:         None

/////////////////////////////////////////////////////////
template<class T>
void SinglyCircularLL<T>::InsertAtPos(T no,T pos)
{
	struct node1<T> *temp=head;
	if((pos<1)||(pos>size+1))
	{
		return;
	}
	if(pos==1)
	{
		InsertFirst(no);
	}
	else if(pos==size+1)
	{
		InsertLast(no);
	}
	else
	{
		int i=0;
		struct node1<T> *newn=NULL;
		newn=new struct node1<T>;
		newn->data=no;
		newn->next=NULL;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
	size++;
}

////////////////////////////////////////////////////////

//Function Name:   DeleteAtPos
//Function Author: Shubham Upasani
//Paramters:       At which position You have to delete the node
//Description:	   This is Function to Delete node at Given Position
//Returns:         None

/////////////////////////////////////////////////////////
template<class T>
void SinglyCircularLL<T>:: DeleteAtPos(T pos)
{
	struct node1<T> *temp=head;
	struct node1 <T>*target=NULL;
	if((pos<1)||(pos>size+1))
	{
		return;
	}
	if(pos==1)
	{
		DeleteFirst();
	}
	else if(pos==size+1)
	{
		DeleteLast();
	}
	else
	{
		int i=0;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		target=temp->next;
		temp->next=target->next;
		delete target;
	}
	size--;
	
	
	
}
////////////////////////////////////////////////////////

//Function Name:   Display
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Display whole Linked List
//Returns:         None

/////////////////////////////////////////////////////////
template<class T>
void SinglyCircularLL<T>::Display()
{
	struct node1 <T>*temp=head;
	int i=0;
	for(i=1;i<=size;i++)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<"\n";
}
////////////////////////////////////////////////////////

//Function Name:   Count
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Count the total number of Nodes present int the Linked List
//Returns:         size

/////////////////////////////////////////////////////////
template<class T>
int SinglyCircularLL<T>::Count()
{
	return size;
}
////////////////////////////////////////////////////////

//Function Name:   SearchFirstOccurence
//Function Author: Shubham Upasani
//Paramters:       Data
//Description:	   This is Function to return the node number of given data(return the first occurence)
//Returns:         Integer

/////////////////////////////////////////////////////////

template<class T>
int SinglyCircularLL<T>::SearchFirstOccurence(T no)
{
	struct node1<T> *temp=head;
	int icnt=0;
	do
	{
		icnt++;
		if(temp->data==no)
		{
			break;
		}
		temp=temp->next;
	}while(temp!=tail->next);
	
	return icnt;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//class Name:   DoublyLL
//Description:In this class we have two members as head pointer pointing to first node,and size varaible as a counter (to count size of nodes)..

//////////////////////////////////////////////////////////////////
template <class T>
class DoublyLL
{
	private:
		struct node2 <T> *head;
		int size;
	public:
		//Fucntion Declaration
		DoublyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,T);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(T);
		void Display();
		int Count();
		int SearchFirstOccurence(T);
		int SearchLastOccurence(T);
};
////////////////////////////////////////////////////////

//Function Name:   Constructor
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is a Constructor for DoublyLL
//Returns:         None

////////////////////////////////////////////////////////
template <class T>
DoublyLL<T>::DoublyLL()
{
	head=NULL;
	size=0;
}
////////////////////////////////////////////////////////

//Function Name:   InsertFirst
//Function Author: Shubham Upasani
//Paramters:       Data to insert
//Description:	   This is Function to insert node at First Position
//Returns:         None

/////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
	
	struct node2<T> *newn=NULL;
	newn=new struct node2<T>;
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	if(head==NULL)
	{
		head=newn;
		size++;
	}
	else
	{
		newn->next=head;
		head->prev=newn;
		head=newn;
		size++;
	}
}
////////////////////////////////////////////////////////

//Function Name:   InsertLast
//Function Author: Shubham Upasani
//Paramters:       Data to insert
//Description:	   This is Function to insert node at Last Position
//Returns:         None

/////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>::InsertLast(T no)
{
	
	struct node2<T> *temp=head;
	struct node2<T> *newn=NULL;
	newn=new struct node2<T>;
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	if(head==NULL)
	{
		head=newn;
		size++;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->prev=temp;
		size++;
	}
}

////////////////////////////////////////////////////////

//Function Name:   DeleteFirst
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Delete node at First Position
//Returns:         None

/////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>::DeleteFirst()
{
	struct node2<T> *temp=head;
	if(size==0)
	{
		return;
	}
	else if(size==1)
	{
		delete head;
		size--;
	}
	else
	{
		temp=temp->next;
		delete temp->prev;
		temp->prev=NULL;
		size--;
	}
		
}

////////////////////////////////////////////////////////

//Function Name:   DeleteLast
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Delete node at Last Position
//Returns:         None

/////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>::DeleteLast()
{
	struct node2<T> *temp=head;
	if(size==0)
	{
		return;
	}
	else if(size==1)
	{
		delete head;
		size--;
	}
	else
	{
		int i=0;
		for(i=1;i<size-1;i++)
		{
			temp=temp->next;
		}
		delete temp->next;
		temp->next=NULL;
		size--;
	}
	
}

////////////////////////////////////////////////////////

//Function Name:   InsertAtPos
//Function Author: Shubham Upasani
//Paramters:       Data to insert and at which position to insert
//Description:	   This is Function to insert node at Given Position
//Returns:         None

/////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertAtPos(T no,T pos)
{
	int Nsize=0,i=0;
	struct node2<T> *temp=head;
	Nsize=Count();
	if((pos<1)||(pos>Nsize+1))
	{
		return;
	}
	if(pos==1)
	{
		InsertFirst(no);
		
	}
	else if(pos==Nsize)
	{
		InsertLast(no);
	}
	else
	{
		struct  node2<T> *newn=NULL;
		newn=new struct node2<T>;
		newn->data=no;
		newn->next=NULL;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
		size++;
	}
}
////////////////////////////////////////////////////////

//Function Name:   DeleteAtPos
//Function Author: Shubham Upasani
//Paramters:       At which position You have to delete the node
//Description:	   This is Function to Delete node at Given Position
//Returns:         None

/////////////////////////////////////////////////////////


template <class T>
void DoublyLL<T>::DeleteAtPos(T pos)
{
	int i=0;
	struct node2<T> *temp=head;
	struct node2 <T>*target=NULL;
	if((pos<1)||(pos>size+1))
	{
		return;
	}
	if(pos==1)
	{
		DeleteFirst();
	}
	else if(pos==size+1)
	{
		DeleteLast();
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		target=temp->next;
		temp->next=target->next;
		target->next->prev=temp;
		size--;
	}
	
}

//Function Name:   Count
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Count the total number of Nodes present int the Linked List
//Returns:         size

/////////////////////////////////////////////////////////

template<class T>
int DoublyLL<T>::Count()
{
	return size;
}
////////////////////////////////////////////////////////

//Function Name:   Display
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Display whole Linked List
//Returns:         None

/////////////////////////////////////////////////////////


template<class T>
void DoublyLL<T>::Display()
{
	struct node2<T> *temp=head;
	cout<<"NULL"<<"\t";
	while(head!=NULL)
	{
		cout<<head->data<<"\t";
		head=head->next;
	}
	cout<<"NULL"<<"\t";
}
////////////////////////////////////////////////////////

//Function Name:   SearchFirstOccurence
//Function Author: Shubham Upasani
//Paramters:       Data
//Description:	   This is Function to return the node number of given data(return the first occurence)
//Returns:         Integer

/////////////////////////////////////////////////////////

template<class T>
int DoublyLL<T>::SearchFirstOccurence(T no)
{
	int i=0;
	struct node2<T> *temp=head;
	while(temp!=NULL)
	{
		i++;
		if(temp->data==no)
		{
			break;
		}
	}
	if(temp==NULL)
	{
		return -1;
	}
	else
	{
		return i;
	}
}

////////////////////////////////////////////////////////

//Function Name:   SearchLastOccurence
//Function Author: Shubham Upasani
//Paramters:       Data
//Description:	   This is Function to return the node number of given data(return the last occurence)
//Returns:         Integer

/////////////////////////////////////////////////////////
template <class T>
int DoublyLL<T>::SearchLastOccurence(T no)
{
	struct node2<T> *temp=head;
	int icnt=size;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp->prev!=NULL)
	{
		if(temp->data==no)
		{
			break;
		}
		icnt--;
		temp=temp->prev;
	}
	return icnt;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//class Name:   DoublyCircularLL
//Description:In this class we have three members as head pointer pointing to first node,tail pointer pointing to the last node,and size varaible as a counter (to count size of nodes)..

//////////////////////////////////////////////////////////////////
template <class T>
class DoublyCircularLL
{
	private:
		struct node2 <T> *head;
		struct node2<T> *tail;
		int size;
	public:
		//Fucntion Declaration
		DoublyCircularLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,T);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(T);
		void Display();
		int Count();
		int SearchFirstOccurence(T);
		int SearchLastOccurence(T);
		
};
////////////////////////////////////////////////////////

//Function Name:   Constructor
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is a Constructor for DoublyCircularLL
//Returns:         None

////////////////////////////////////////////////////////
template <class T>
DoublyCircularLL<T>::DoublyCircularLL()
{
	head=NULL;
	tail=NULL;
	size=0;
}
////////////////////////////////////////////////////////

//Function Name:   InsertFirst
//Function Author: Shubham Upasani
//Paramters:       Data to insert
//Description:	   This is Function to insert node at First Position
//Returns:         None

/////////////////////////////////////////////////////////
template <class T>
void DoublyCircularLL<T>::InsertFirst(T no)
{
	struct node2<T> *newn=NULL;
	newn=new struct node2<T>;
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	if((head==NULL)&&(tail==NULL))			//ll is empty
	{
		head=newn;
		tail=newn;
		size++;
	}
	else
	{
		newn->next=head;
		newn->prev=head->prev;
		head=newn;
		tail->next=head;
		size++;
	}
}
////////////////////////////////////////////////////////

//Function Name:   InsertLast
//Function Author: Shubham Upasani
//Paramters:       Data to insert
//Description:	   This is Function to insert node at Last Position
//Returns:         None

/////////////////////////////////////////////////////////
template <class T>
void DoublyCircularLL<T>::InsertLast(T no)
{
	struct node2<T> *newn=NULL;
	newn=new struct node2<T>;
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	if((head==NULL)&&(tail==NULL))			
	{
		head=newn;
		tail=newn;
		size++;
	}
	else
	{
		tail->next=newn;
		newn->prev=tail;
		tail=newn;
		tail->next=head;
		size++;
	}
	
}

////////////////////////////////////////////////////////

//Function Name:   DeleteFirst
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Delete node at First Position
//Returns:         None

/////////////////////////////////////////////////////////
template <class T>
void DoublyCircularLL<T>::DeleteFirst()
{
	if(size==0)
	{
		return;
	}
	if(size==1)
	{
		delete head;
		delete tail;
		head=NULL;
		tail=NULL;
		size--;
	}
	else
	{
		head=head->next;
		delete tail->next;
		tail->next=head;
		head->prev=tail;
		size--;
	}
}

////////////////////////////////////////////////////////

//Function Name:   DeleteLast
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Delete node at Last Position
//Returns:         None

/////////////////////////////////////////////////////////
template <class T>
void DoublyCircularLL<T>::DeleteLast()
{
	struct node2<T> *temp=head;
	if(size==0)
	{
		return;
	}
	
	if(size==1)
	{
		delete head;
		delete tail;
		head=NULL;
		tail=NULL;
		size--;
	}
	else
	{
		for(int i=1;i<size-1;i++)
		{
			temp=temp->next;
		}
		delete temp->next;
		temp->next=head;
		size--;
	}
	
}

////////////////////////////////////////////////////////

//Function Name:   InsertAtPos
//Function Author: Shubham Upasani
//Paramters:       Data to insert and at which position to insert
//Description:	   This is Function to insert node at Given Position
//Returns:         None

/////////////////////////////////////////////////////////

template <class T>
void DoublyCircularLL<T>::InsertAtPos(T no,T pos)
{
	struct node2<T> *newn=NULL;
	struct node2<T> *temp=head;
	newn=new struct node2<T>;
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	if((pos<1)||(pos>size+1))
	{
		return;
	}
	if(pos==1)
	{
		InsertFirst(no);
		
	}
	else if(pos==size+1)
	{
		InsertLast(no);
		
	}
	else
	{
		int i=0;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		newn->prev=temp;
		temp->next->prev=newn;
		size++;
	}
}
////////////////////////////////////////////////////////

//Function Name:   DeleteAtPos
//Function Author: Shubham Upasani
//Paramters:       At which position You have to delete the node
//Description:	   This is Function to Delete node at Given Position
//Returns:         None

/////////////////////////////////////////////////////////


template <class T>
void DoublyCircularLL<T>::DeleteAtPos(T pos)
{
	int i=0;
	struct node2<T> *temp=head;
	struct node2 <T>*target=NULL;
	if((pos<1)||(pos>size+1))
	{
		return;
	}
	if(pos==1)
	{
		DeleteFirst();
	}
	else if(pos==size+1)
	{
		DeleteLast();
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		target=temp->next;
		temp->next=target->next;
		target->next->prev=temp;
		size--;
	}
}

//Function Name:   Count
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Count the total number of Nodes present int the Linked List
//Returns:         size

/////////////////////////////////////////////////////////

template<class T>
int DoublyCircularLL<T>::Count()
{
	return size;
}
////////////////////////////////////////////////////////

//Function Name:   Display
//Function Author: Shubham Upasani
//Paramters:       None
//Description:	   This is Function to Display whole Linked List
//Returns:         None

/////////////////////////////////////////////////////////


template<class T>
void DoublyCircularLL<T>::Display()
{
	struct node2 <T>*temp=head;
	int i=0;
	for(i=1;i<=size;i++)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<"\n";
}
////////////////////////////////////////////////////////

//Function Name:   SearchFirstOccurence
//Function Author: Shubham Upasani
//Paramters:       Data
//Description:	   This is Function to return the node number of given data(return the first occurence)
//Returns:         Integer

/////////////////////////////////////////////////////////

template<class T>
int DoublyCircularLL<T>::SearchFirstOccurence(T no)
{
	struct node2<T> *temp=head;
	int icnt=0;
	do
	{
		icnt++;
		if(temp->data==no)
		{
			break;
		}
		temp=temp->next;
	}while(temp!=tail->next);
	
	return icnt;
}


////////////////////////////////////////////////////////

//Function Name:   SearchLastOccurence
//Function Author: Shubham Upasani
//Paramters:       Data
//Description:	   This is Function to return the node number of given data(return the last occurence)
//Returns:         Integer

/////////////////////////////////////////////////////////
template <class T>
int DoublyCircularLL<T>:: SearchLastOccurence(T no)
{
	struct node2 <T>*temp=tail;
	int icnt=size;
	while(temp!=head)
	{
		if(temp->data==no)
		{
			break;
		}
		icnt--;
		temp=temp->prev;
	}
	return icnt;
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

//class Name:   QUEUE
//Description:In this class we have three members as head pointer pointing to first node,tail pointer pointing to last node,and size varaible as a counter (to count size of nodes)..

//////////////////////////////////////////////////////////////////
template<class T>
class QUEUE
{
	private:        //Access Specifier
		int isize;
		struct node1<T> *head;
		struct node1<T> *tail;
	public:         //Access Specifier
		//Function Declaration
		QUEUE();
		~QUEUE();
		void EnQueue(T);
		int DeQueue();
		void Display();
		int Count();
		
};
////////////////////////////////////////////////////////

//Function Name:   Constructor
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is a Constructor for QUEUE
//Returns:         None

////////////////////////////////////////////////////////
template<class T>
QUEUE<T>::QUEUE()
{
	isize=0;
	head=NULL;
	tail=NULL;
}
////////////////////////////////////////////////////////

//Function Name:   Destructor
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is a Destructor for QUEUE
//Returns:         None

////////////////////////////////////////////////////////
template<class T>
QUEUE<T>::~QUEUE()
{
	int i=0;
	struct node1<T> *temp=NULL;
	for(i=1;i<=isize;i++)
	{
		temp=head;
		head=head->next;
		delete temp;
	}

}
////////////////////////////////////////////////////////

//Function Name:   EnQueue
//Function Author: Shubham Upasani
//Paramters:       Data
//Description:     This is used to insert the element at last of QUEUE
//Returns:         None

////////////////////////////////////////////////////////
template<class T>
void QUEUE<T>::EnQueue(T ino)
{
	struct node1<T> *newn=new struct node1<T>;
	newn->data=ino;
	newn->next=NULL;
	if(isize==0)
	{
		head=newn;
		tail=newn;
		isize++;
	}
	else
	{
		tail->next=newn;
		tail=newn;
		tail->next=head;
		isize++;
	}
}
////////////////////////////////////////////////////////

//Function Name:   DeQueue
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is used to delete the element at first of QUEUE
//Returns:         deleted element

////////////////////////////////////////////////////////
template <class T>
int QUEUE<T>::DeQueue()  
{
	int iret=-1;
	if(isize==0)
	{
		cout<<"QUEUE is empty\n";
		return iret;
	}
	else
	{
		struct node1<T> *temp=head;
		head=head->next;
		tail->next=head;
		iret=temp->data;
		isize--;
		delete temp;
		return iret;
	}
}
////////////////////////////////////////////////////////

//Function Name:   Display
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is used to display the data of QUEUE
//Returns:         None

////////////////////////////////////////////////////////
template<class T>
void QUEUE<T>::Display()
{
	struct node1<T> *temp=head;
	do
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}while(temp!=tail->next);
}
////////////////////////////////////////////////////////

//Function Name:   Count
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is used to count the elements of QUEUE
//Returns:         count of elements

////////////////////////////////////////////////////////
template<class T>
int QUEUE<T>::Count()
{
	return isize;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

//class Name:   Stack
//Description:In this class we have two members as head pointer pointing to first node,and size varaible as a counter (to count size of nodes)..

//////////////////////////////////////////////////////////////////
template<class T>
class Stack
{
	private:
		struct node1<T> *head;
		int isize;
	public:
		//Fucntion Decleration
		Stack();  
		~Stack();  
		void Push(T);
		int Pop();  
		void Display();
		int count();
		int Peek();
};
////////////////////////////////////////////////////////

//Function Name:   Constructor
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is a Constructor for Stack
//Returns:         None

////////////////////////////////////////////////////////
template<class T>
Stack<T>::Stack() 
{
	this->head=NULL;   
	this->isize=0;
	
}
////////////////////////////////////////////////////////

//Function Name:   Destructor
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is a Destructor for Stack
//Returns:         None

////////////////////////////////////////////////////////
template<class T>
Stack<T>::~Stack() 
{
	struct node1 <T> *temp=NULL;
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		delete temp;
	}
}
////////////////////////////////////////////////////////

//Function Name:   Push
//Function Author: Shubham Upasani
//Paramters:       data
//Description:     This is used to insert(push) the data in Stack
//Returns:         None

////////////////////////////////////////////////////////
template<class T>
void Stack<T>::Push(T ino)  
{
	struct node1<T> *newn=new struct node1<T>;
	newn->data=ino;
	newn->next=NULL;
	newn->next=head;
	head=newn;
	isize++;
}
////////////////////////////////////////////////////////

//Function Name:   Pop
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is used to delete(pop) the data in Stack
//Returns:         popped element

////////////////////////////////////////////////////////
template<class T>
int Stack<T>::Pop()  
{
	int iret=-1;
	if(isize==0)
	{	
		cout<<"stcak is empty\n";
		return iret;
	}
	else
	{
		struct node1<T> *temp=head;
		head=head->next;
		iret=temp->data;
		delete temp;
		isize--;
		return iret;
		
	}
	
}
////////////////////////////////////////////////////////

//Function Name:   Peek
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is used to peek the data in Stack i.e which element is at the top of Stack
//Returns:         peek element

////////////////////////////////////////////////////////
template<class T>
int Stack<T>::Peek()
{
	if(isize==0)
	{
		return -1;
	}
	else
	{
		return head->data;
	}
}
////////////////////////////////////////////////////////

//Function Name:   Display
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is used to Display the data of Stack
//Returns:         None

////////////////////////////////////////////////////////
template<class T>
void Stack<T>::Display()
{
	struct node1<T> *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<"\n";
}
////////////////////////////////////////////////////////

//Function Name:   Count
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is used to count the elements of Stack
//Returns:         count of element

////////////////////////////////////////////////////////
template<class T>
int Stack<T>::count()
{
	return this->isize;
}

////////////////////////////////////////////////////////

//Function Name:   main
//Function Author: Shubham Upasani
//Paramters:       None
//Description:     This is a main function
//Returns:         0

////////////////////////////////////////////////////////
int main()
{
	SinglyLL <int>obj1;
	SinglyCircularLL <int>obj2;
	DoublyLL <int>obj3;
	DoublyCircularLL <int>obj4;
	QUEUE <int>obj5;
	Stack <int>obj6;
	return 0;
}//End Of main