#include <iostream>
using namespace std;

struct node
{
  int info;
  node *left,*right;
};
//------------------------
class BST
{
   private :
	    node *temp;
   public  :
	    node *root;
	    int number;
	    BST();
	    void insertRecursive(node *temp, int number); //insert with recursion
	    void insertIerative(node *temp, int number);// insert with iteration
	    
            bool find(node * temp, int num); 		//recursive
	    bool findIterative(node * temp, int num);  // iterative

	    void deleteNode(node* &temp, int number); // recursive
	    
	    //in order traversal
	    void in_order(node *temp);

	//Check if a Binary tree is less than Root
	bool isSubtreeLesser(node*temp, int value)
	{
	// int value = value of Root node of any binary tree
	// if node is less than root value, and its left, right subtree are also less than Root
	if(temp == NULL)
		return true;
	if(temp->info <= value && isSubtreeLesser(temp->left, value) && isSubtreeLesser(temp->right, value) )
	   return true; 
	else
	   return false;
	}
	
	//Check if a Binary tree is greater than Root
	bool isSubtreeGreater(node*temp, int value)
	{
	// int value = value of Root node of any binary tree
	// if node is greater than root value, and its left, right subtree are also > than Root
	if(temp == NULL)
		return true;
	if(temp->info > value && isSubtreeGreater(temp->left, value) && isSubtreeGreater(temp->right, value) )
	   return true; 
	else
	   return false;
	}
	//Check if a Binary tree is BST or NOT: use above two functions
	bool isBST(node*temp)
	{
	if(temp == NULL)
		return true;
	if(isSubtreeLesser(temp->left, temp->info) 	//check left subtree is lesser
	   && isSubtreeGreater(temp->right, temp->info) // check right subtree is greater
	   && isBST(temp->left)				// goto all the left subtree nodes
	   && isBST(temp->right)  			// goto all the right subtree nodes
	  )
	   return true; 
	else
	   return false;
	}

};
//-----------------------------
int main()
{

  BST obj;

  
  int num;
  cout<<"Enter '1' for Insertion\n";
  cout<<"Enter '2' for Print (inOrder)\n";
  cout<<"Enter '3' for Search\n";
  cout<<"Enter '4' for Deletion\n";
  cout<<"Enter '5' for binary tree is BST or NOT:\n";
  cout<<"Any other number to End the Program\n";

  do
  {
  	cout<<"Enter your choice: ";  cin>>num;
  	if(num==1)
  		{int x; cout<<"Enter node value: ";  cin>>x; obj.insertIerative(obj.root,x);}
  	else if(num==2)
  		obj.in_order(obj.root);
  	else if(num==3)
  		{int x; cout<<"Enter search value: "; cin>>x; obj.find(obj.root,x);}
  	else if(num==4)
  		{int x; cout<<"Enter delete value: "; cin>>x; obj.deleteNode(obj.root,x);}
  	else if(num==5)
  		{cout<<"Tree is BST : "<<obj.isBST(obj.root)<<endl;}
  	else
  		break;
  		
  }
  while(num>=1 and num<6);
  
return 0;
}//-----------------------------------------------

BST::BST()
{
  root=temp=NULL;
}
//--------------------------------------------------------
void BST::insertIerative(node *temp, int number)
{
	node*n = new node;
	n->info = number;
	n->left = n->right = NULL;
	
	if(root == NULL )
	{  root = n; return;}
	
	while(temp != NULL)
	{
		if(number < temp->info)
		{
			if(temp->left != NULL)
				temp=temp->left;
			else
				{temp->left = n; return;}
		}
		else if(number > temp->info)
		{
			if(temp->right != NULL)
				temp=temp->right;
			else
				{temp->right = n; return;}
		}
		else
		{ cout<<"number already exists"<<endl; return;}
	}
}

//--------------------------------------------------------
void BST::insertRecursive(node *temp, int number)
{
  if( root==NULL )
   {
     temp=new node;
     temp->info = number;
     temp->left=temp->right=NULL;
     root=temp;
     return;
   }

  if( temp->info==number )
   { cout<<" \n Given number is already present in tree.\n"; return; }

  if(number < temp->info)
   {
      if( temp->left!=NULL )
       {
		 insertRecursive(temp->left, number);
		 //return;
       }
       else
       {
    	 temp->left=new node;
    	 temp->left->info = number;
    	 temp->left->left=NULL;
    	 temp->left->right=NULL;
    	 return;
       }
   }
   if(number > temp->info)
   {
      if( temp->right!=NULL )
       {
		 insertRecursive( temp->right,number );
		 //return;
       }
       else
       {
    	 temp->right=new node;
    	 temp->right->info = number;
    	 temp->right->left=NULL;
    	 temp->right->right=NULL;
    	 return;
       }
   }

} 
//-------------------- -------------------    
bool BST :: find(node * temp, int num)
    {
    	bool found=false;
        if(root==NULL) { cout<<"Empty tree"<<endl; return false;}
        
        if(temp->info==num)
        {
            cout<<"Yes, number found!"<<endl; 
            found=true; 
            return found;
        }    
        else if(num < temp->info && temp->left!=NULL)
        {
    		found=find(temp->left, num);
        }
        else if(num > temp->info && temp->right!=NULL)
        {
       		found=find(temp->right, num);
        }
        else {}
        return found;      
}
//---------------------------------------
bool BST :: findIterative(node * temp, int num)
    {
    	bool found=false;
        if(root==NULL) { cout<<"Empty tree"<<endl; return false;}
        
        while(temp!=NULL && !found)
        {
        	if(num < temp->info)
        		temp=temp->left;
        	else if(num > temp->info)
        		temp=temp->right;
        	else
        	{
        	    cout<<"Yes, number found!"<<endl; 
		    found=true; 
        	}
        }
        return found;      
}

//---------------------------------------
void BST::in_order(node *temp)
{
  if(root==NULL)
    {
	cout<<" Tree is empty.\n";
	return;
    }
  cout<<temp->info<<"  ";
  if( temp->left!=NULL )
    		 in_order(temp->left);
  if( temp->right!=NULL )
		 in_order(temp->right);
  return;
}
//---------------------------------------
void BST::deleteNode(node* &temp, int key)
{
	if(root == NULL)
	{ cout<<"Tree is Empty"<<endl; return;}
	
	if(temp == NULL)
	{ cout<<"Number not found"<<endl; return;}
	
	if(key < temp->info)
	{
		cout<<"Copy of node: "<<temp->info;
		deleteNode(temp->left, key);
	}
	else if(key > temp->info)
	{
		cout<<"Copy of node: "<<temp->info;
		deleteNode(temp->right, key);		
	}
	else	//key==temp->info
	{
		if(temp->left == NULL && temp->right == NULL)	//case-1
		{
			cout<<"Case-1: Leaf\n";		
			delete temp; temp=NULL;	return;
		}
		else if(temp->left != NULL && temp->right == NULL)	//case-2
		{
			cout<<"Case-2: Right=Null\n";		
			node*t1 = temp; temp=temp->left; delete t1; return;
		}
		else if(temp->left == NULL && temp->right != NULL)	//case-3
		{
			cout<<"Case-3: Left=Null\n";
			node*t1 = temp; temp=temp->right; delete t1; return;
		}
		else	//both childs != NULL
		{
			cout<<"Case-4: Both childs exists\n";
			// a) either find min from right subtree  OR
		       //  b) max from left subtree
		       node*t1,*parent;
		       t1 = temp->right;	 // move one step right
		       if(t1->left == NULL)
		       {
		       		temp->right = t1->right;
		       }
		       else
		       {
				while(t1->left != NULL)		//goto left nodes untill last found
				 	{parent = t1; t1=t1->left;}
			       parent->left = t1->right;
			       temp->info = t1->info;	//swap value of last node and delete
		       }
		       
		       delete t1;
		       return;
		}
		
	}
	
}
//----------------------------    PROGRAM ENDS HERE  ---------------------------------------



