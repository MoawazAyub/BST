# include < iostream >
# include  < string >

using namespace std;



template<class T>
class List
{
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	
	};

private:
	

	int size;

	Node* head;
	Node* tail;

	Node* createnode(const T & data)
	{
		Node* temp = new Node;
	   
	   temp->data = data;
	   temp->next = NULL;
	   temp->prev = NULL;
	   return temp;
	
	}

public:

	friend ostream & operator<<(ostream &  out,  List & text)
	{
		text.printlist();

		return out;
	
	}

	List(const List & text)
	{
		//Node * newnode;
		Node * curr;

		size = 0;

		if(text.size == 0)
		{
			head = tail = NULL;
			size = 0;
		
		}
		else
		{
			curr = text.head;
			

			while(curr != NULL)
			{
			addatend(curr->data);

			curr = curr->next; 
			}
		
		
		}

	}

	const List & operator=(const List & text)
	{
		Node * curr;

		if (size != 0)
		{
			distroylist();
		
		}

		if(text.size == 0)
		{
			head = tail = NULL;
			size = 0;
		
		}
		else
		{
			curr = text.head;
			

			while(curr != NULL)
			{
			addatend(curr->data);

			curr = curr->next; 
			}
		
		
		}
	
	return *this;
	}

	List()
	{
		head = tail = NULL;
		size = 0;
	
	}
	void addatend(const T & obj)
	{
		if(size == 0)
		{
			head = createnode(obj);
			tail = head;
			size++;
		
		}

		else
		{
			Node * temp;
			temp = createnode(obj);
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
			size++;
		
		
		}
	
	}
	void addatstart(const T & obj)
	{

		if(size == 0)
		{
			head = createnode(obj);
			tail = head;
			size++;
		
		}

		else
		{
			Node * temp;
			temp = createnode(obj);
			temp->next = head;
			head->prev = temp;
			head = temp;
			size++;
		
		
		}
	
	
	}
	void printlist()
	{
		Node * curr;
		curr = head;

		while(curr != tail->next)
		{
			cout<<curr->data;
			curr = curr->next;
		
		}
		cout <<endl << " size is " <<size<< endl;
	}

	void printlisto()
	{
		Node * curr;
		curr = tail;

		while(curr != head->prev)
		{
			cout<<curr->data;
			curr = curr->prev;
		
		}
		cout << endl << "size is " <<size<< endl;
	}

	void distroylist()
	{

		Node * curr;

		while(head != NULL)
		{
			curr = head;
			head = head->next;
			delete curr;
		
		}
		tail = NULL;
		size = 0;
	
	}

	~List()
	{
		Node * curr;

		while(head != NULL)
		{
			curr = head;
			head = head->next;
			delete curr;
		
		}
		tail = NULL;
		size = 0;
	
	
	}

	

	//---------------------------- iterator

	class iterate
	{
		Node* curr;
	public:
		iterate(Node * ptr = NULL)
		{
			curr = ptr;
		
		}

		iterate & operator++()
		{
			curr = curr->next;
			return *this;
		
		}

		iterate & operator--()
		{
			curr = curr->prev;
			return *this;
		
		}

		char & operator*()
		{
			return curr->data;
		
		}

		

		bool operator!=(const iterate & obj)
		{
			return (curr!=obj.curr);
		
		}
	
	};

	iterate begin()
		{
			
			return iterate(head);
			
		
		}
		iterate end()
		{
			
			return iterate(NULL);
			
		
		}

	//---------------------------
	
		void removeatend()
		{
		if(size == 1)
		{
			delete head;
			head = tail = NULL;
			size = 0;
		
		}

		else if(size > 1)
		{
			Node * temp;
			temp = tail->prev;
			delete tail;
			tail = temp;
			tail->next = NULL;
			--size;
		
		}


		}

		void removeatstart()
		{
			if(size == 1)
		{
			delete head;
			head = tail = NULL;
			size = 0;
		
		}

		else if(size > 1)
		{
			Node * temp;
			temp = head->next;
			delete head;
			head = temp;
			head->prev = NULL;
			--size;
		
		}
		
		
		}



		Node * gethead()
		{
			return head;
		
		}

		Node * gettail()
		{
			return tail;
		
		}

		int getsize()
		{
			return size;
		
		}
	



	

};






