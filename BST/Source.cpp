# include < iostream >
# include   <vector>
# include "Queue.h"
#include <algorithm>


using namespace std;



template <class T>
class BST
{
private:
	
	struct node
	{
		T data;
		node * left, * right;
	
	
	};
	node * root;
	int size;

	node* createnode(const T & obj)
	{
		node* temp = new node;
		temp->left = NULL;
		temp->right= NULL;
		temp->data = obj;

		return temp;
	
	}

	//----------------------------------------------------------------height mask
	int height(node * curr)
	{
		if(curr == NULL)
		{
			return 0;

		}

		else if(curr->left == NULL && curr->right == NULL)
		{
			return 0;

		}

		else
		{
			return (1 + max(height(curr->left),height(curr->right)));
		
		}
	
	}
	

public:

	BST()
	{
	root = NULL;
	size = 0;
	

    }
	//----------------------------------------------------------------------empty
	bool isempty()
	{
		if(size == 0)
		{
			return true;
		
		}

		else
		{
			return false;
		
		}
	
	}

	//-------------------------------------------------------------------------insert

	void insert(const T & obj)
	{
		if(isempty())
		{
			root = createnode(obj);
			size++;
		
		}

		else
	{
		node* curr = root;
		node* prev = NULL;

		while(curr != NULL)
		{
			prev = curr;

			if(curr->data <= obj)
			{
				curr = curr->right;
			
			}
			else
			{
				curr = curr->left;
			
			}
		

		
		}

		if(prev->data <= obj)
		{
			prev->right = createnode(obj);
			size++;
		
		}

		else
		{
			prev->left = createnode(obj);
			size++;
		
		}

    }
	
	}

	//---------------------------------------------------------------getnode
// ----------------------------------------------------------------------------this is in order
	void getnode(node * curr, vector<node*> & nodes)
	{
		if(curr != NULL)
		{
			getnode(curr->left , nodes);
				nodes.push_back(curr);
			getnode(curr->right , nodes);

		
		}
	
	}


	void getnode_postorder(node * curr, vector<node*> & nodes)
	{
		if(curr != NULL)
		{
			getnode(curr->left , nodes);

			getnode(curr->right , nodes);

			nodes.push_back(curr);
		
		}
	
	}

	void getnode_preorder(node * curr, vector<node*> & nodes)
	{
		if(curr != NULL)
		{
			nodes.push_back(curr);

			getnode(curr->left , nodes);
				
			getnode(curr->right , nodes);

		
		}
	
	}

	
//-----------------------------------------------------------------------class iterator
	class iterator
	{
		node* curr;
		vector<node*> nodes;
		int i;
		BST a;

	public:
	
		
		/*iterator( vector<node*> & nodes1 , node* c = NULL)
		{
			curr = c;
				a.getnode(curr, nodes1 );
				nodes = nodes1;
			i = 0;
		
		}*/

		iterator( vector<node*> & nodes1 , node* c = NULL)
		{
			curr = c;
				
				nodes = nodes1;
			i = 0;
		
		}

		iterator & operator++()
		{
			i = i + 1;
			return *this;
		
		}

		iterator & operator--()
		{
			i = i - 1 ;
			return *this;
		
		}

		T & operator*()
		{
			return (nodes[i])->data;
		
		}

		bool operator!=(const iterator & obj)
		{
			if(i == nodes.size())
			{
				return false;
			
			}

			else 
			{
				return true;
			
			}
		
		}
	
	};

	/*iterator begin()
		{
			vector<node*> v1;
			
			return iterator(v1,root);
			
		
		}*/

	iterator begin()
		{
			vector<node*> v1;

			getnode(root,v1);
			
			return iterator(v1,root);
			
		
		}


	iterator lbegin()
		{
			vector<node*> v1;

			getnode_levelorder(v1);
			
			return iterator(v1,root);
			
		
		}

	iterator end()
		{
			vector<node*> v1;
			
			return iterator(v1,NULL);
			
			
		
		}

	//----------------------------------------------------------------class iterator end


	//------------------------------------------------------------------search

	bool search(const T & find)
	{
		node * curr;
		curr = root;

		while(curr != NULL)
		{
			if(curr->data == find)
			{
				return true;
			
			}

			else if(curr->data < find)
			{
				curr = curr->right;
			
			}

			else if(curr->data > find)
			{
				curr = curr->left;
			
			}
		
		}
	
	return false;
	}

	//------------------------------------------------------------------------height
	
	int height()
	{
		return height(root);
	
	}

	//--------------------------------------------------------------------swap
	void swap( T & t1, T & t2)
	{
		T t3;
		t3 = t1;
		t1 = t2;
		t2 = t3;
	
	}

	//------------------------------------------------------------------remove
	void remove(const T & obj)
	{
		bool found  = false;
		node * curr = root;
		node * prev = NULL;

		while(curr != NULL)
		{
			if(curr->data == obj)
			{
				found = true;
				break;
			
			}

			else if(curr->data <= obj)
			{
				prev = curr;
				curr = curr->right;
			
			}

			else if(curr->data > obj)
			{
				prev = curr;
				curr = curr->left;
			
			}

		}

		if(found == false)
		{
			cout << "could not find the required data" << endl;
		
		}

		else
		{//-----------------------------------------------leaf
			if(curr->left == NULL && curr->right == NULL)
			{
				if(curr->data <= prev->data)
				{
					prev->left = NULL;
					delete curr;
				
				}

				else if(curr->data > prev->data)
				{
					prev->right = NULL;
					delete curr;
				
				}
			
			}

			//-------------------------------------------------one child

			else if(curr->left == NULL && curr->right != NULL)
			{
				if(curr->data <= prev->data)
				{
					prev->left = curr->right;
					delete curr;
				
				}

				else if(curr->data > prev->data)
				{
					prev->right = curr->right;
					delete curr;
				
				}
			
			}

			else if(curr->left != NULL && curr->right == NULL)
			{
				if(curr->data <= prev->data)
				{
					prev->left = curr->left;
					delete curr;
				
				}

				else if(curr->data > prev->data)
				{
					prev->right = curr->left;
					delete curr;
				
				}
			
			}

			//-------------------------------------------------------- two childs
			else if(curr->left != NULL && curr->right != NULL)
			{
				node * curr1 = curr->left;
				node * prev1 = curr;

				while(curr1->right != NULL)
				{
					prev1 = curr1;
					curr1 = curr1->right;
				
				}

				

				//---------------------------------
				//-----------------------------------------------leaf
			if(curr1->left == NULL && curr1->right == NULL)
			{
				if(curr1->data <= prev1->data)
				{
					swap(curr1->data,curr->data);
					prev1->left = NULL;
					delete curr1;
				
				}

				else if(curr1->data > prev1->data)
				{
					swap(curr1->data,curr->data);
					prev1->right = NULL;
					delete curr1;
				
				}
			
			}

			//-------------------------------------------------one child

			/*else if(curr1->left == NULL && curr1->right != NULL)
			{
				if(curr1->data <= prev1->data)
				{
					prev1->left = curr1->right;
					delete curr1;
				
				}

				else if(curr1->data > prev1->data)
				{
					prev1->right = curr1->right;
					delete curr1;
				
				}
			
			}*/

			else if(curr1->left != NULL && curr1->right == NULL)
			{
				if(curr1->data <= prev1->data)
				{
					swap(curr1->data,curr->data);
					prev1->left = curr1->left;
					delete curr1;
				
				}

				else if(curr1->data > prev1->data)
				{
					swap(curr1->data,curr->data);
					prev1->right = curr1->left;
					delete curr1;
				
				}
			
			}
				//---------------------------------

			
			}//--------------------------------------------------------------end of two childs

		cout<< " deletion successful " << endl;
		}//----------------------------------------------- end of else

	
	}//---------------------------------------------------------------end of remove

	//-------------------------------------------------------------------get node level order

	void getnode_levelorder(vector<node*> & v)
	{
		Queue<node*> q;
		q.enque(root);

		while(!q.isempty())
		{
		   node* curr = q.front();
		   q.deque();
		   if(curr->left != NULL )
		   {
			   q.enque(curr->left);
		   
		   }

		   if(curr->right != NULL )
		   {
			   q.enque(curr->right);
		   
		   }

		   v.push_back(curr);
		
		}
	
	}

	//------------------------------------------------------------depth
	int depth(const node*  obj)
	{
		int i = 0;
		node* curr = root;

		while(curr != NULL)
		{
			if(curr == obj)
			{
				return i;
			
			}

			else if(curr->data <= obj->data)
			{
				curr = curr->right;
				i++;
			
			}

			else if(curr->data > obj->data)
			{
				curr = curr->left;
				i++;
			
			}
		
		
		}

		cout<<"wrong data"<<endl;

	return (-1);
	}

	//--------------------------------------------------------------width
	int width()
	{
		int max = 1;
		int t2 = 1;
		vector<node*>  v;
		getnode_levelorder(v);

		

		for(unsigned int i = 0 ; i < (v.size() - 1) ; i++)
		{
			if(depth(v[i]) != depth(v[i+1]))
			{
				t2 = 1;
			
			}

			else if(depth(v[i]) == depth(v[i+1]))
			{
				t2++;

				if(t2 > max)
				{
					max = t2;
				
				}
			
			}
		
		}
		return max;
	
	
	}

	//---------------------------------------------------------------update key

	void updatekey(const T & key1, const T & key2)
	{
		remove(key1);
		insert(key2);
	
	}

	//------------------------------------------------------------make skew

	void makeskew()
	{
		vector<node*>  v;
		getnode(root,v);

		root = v[0];

		for(unsigned int i = 0 ; i < (v.size() - 1) ; i++)
		{
			v[i]->left  = NULL;
			v[i]->right = v[i+1];
		
		}

		v[v.size() - 1]->left = NULL;
		v[v.size() - 1]->right = NULL;
	
	}

	//-------------------------------------------------------------------- path skew end

	//------------------------------------------------------------------path sum
	void vectorsum(vector<node*> & v1,vector<T> & sum)
	{
		T sum1 = T();

		for(unsigned int i = 0 ; i < v1.size() ; i++)
		{
			sum1 = sum1 + v1[i]->data;
		
		}

		sum.push_back(sum1);
	
	}

	//---------------------------------------------------mask

	void pathsum(vector<T> & sum1,node * curr, vector<node*> & nodes)
	{
		
			nodes.push_back(curr);
			if(curr->left != NULL)
			{
			pathsum(sum1,curr->left , nodes);
			
			}

			if(curr->right != NULL)
			{
			
			pathsum(sum1,curr->right , nodes);
			
			nodes.pop_back();
			}

			else if(curr->right == NULL && curr->left == NULL)
			{
				vectorsum(nodes,sum1);
				nodes.pop_back();
			
			}
		
		
		
	
	}

	void pathsum(vector<T> & sum)
	{
		vector<node*>  v;
		pathsum(sum,root,v);
	
	}
	//----------------------------------------------------------

};

template<class T>
void printbstinorder(BST<T> & a)
{
	BST<int>::iterator it = a.begin();

	
	
	for(it; it != a.end() ; ++it)
	{
	cout<<*it<<",";
	}

}

template<class T>
void printbstlevelorder(BST<T> & a)
{
	BST<int>::iterator it = a.lbegin();

	
	
	for(it; it != a.end() ; ++it)
	{
	cout<<*it<<",";
	}

}

void printmenu()
{
	cout<<"press 1 to insert"<<endl;
	cout<<"press 2 to delete"<<endl;
	cout<<"press 3 to find height"<<endl;
	cout<<"press 4 to find width"<<endl;
	cout<<"press 5 to get path sum"<<endl;
	cout<<"press 6 to update key"<<endl;
	cout<<"press 7 to make tree skew"<<endl;
	cout<<"press 8 to print in order"<<endl;
	cout<<"press 9 to print in level order"<<endl;
	cout<<"press 0 to quit"<<endl;

}

void main()
{
	
	BST<int> a;

	int select  = -1;

	printmenu();

	while(select != 0)
	{
		cout<<"select the option"<<endl;
		cin >> select;

		if(select == 1)
		{
			int value;
			cout<<"enter the data"<<endl;
			cin >> value;
			a.insert(value);
		
		}

		else if(select == 2)
		{
			int value;
			cout<<"enter the data to be deleted"<<endl;
			cin >> value;
			a.remove(value);
		
		}

		else if(select == 3)
		{
			cout << endl;
			cout << "the height = " <<a.height();
			cout << endl;
		
		}

		else if(select == 4)
		{
			cout << endl;
			cout << "the width = " <<a.width();
			cout << endl;
		
		}

		else if(select == 5)
		{
			vector<int> s;
			cout << endl;
			cout << "the path sums are ";
			a.pathsum(s);
	for(unsigned int i = 0 ; i < s.size(); i++)
	{
		cout<<s[i]<<" ";
	
	}
			cout << endl;
		
		}

		else if(select == 6)
		{
			int v1 = 0;
			int v2 = 0;
			cout << "enter the key you want to replace" <<endl;
			cin >> v1;
			cout << "enter the new key" <<endl;
			cin >> v2;

			a.updatekey(v1,v2);
		
		}

		else if(select == 7)
		{
			cout << "the tree has been skewed"<<endl;
			
			a.makeskew();
		
		}

		else if(select == 8)
		{
			cout<<"printing in order"<<endl;

			printbstinorder(a);
		
		}

		else if(select == 9)
		{
			cout<<"printing in level order"<<endl;

			printbstlevelorder(a);
		
		}


	
	}

	//BST<int> a;
	//
	//
	//
	//a.insert(50);
	//a.insert(30);
	//a.insert(100);
	//a.insert(25);
	//a.insert(40);
	//a.insert(35);
	//a.insert(47);
	//a.insert(80);
	//a.insert(95);
	//a.insert(150);

	//vector<int> s;

	//
	//
	//a.pathsum(s);

	//for(unsigned int i = 0 ; i < s.size(); i++)
	//{
	//	cout<<s[i]<<" ";
	//
	//}

	//printbstinorder(a);
	//cout << endl;
	//printbstlevelorder(a);

	//------------------------------------------------------------------------experiment
	BST<int> b[1000];

	for(int i = 0 ; i < 1000 ; i++)
	{
		for(int j = 0 ; j < 1000 ; j++)
		{
			b[i].insert(rand());
		
		}
	
	}

	

	

	int sum = 0;

	for(int i = 0 ; i < 1000 ; i++)
	{
		
		sum = sum + b[i].height();
	
	}

	cout <<"average = " << sum/1000<<" as the average is more closer then ln n so if we had to read file from a disk we will try to collect data in random order ";

	



}


