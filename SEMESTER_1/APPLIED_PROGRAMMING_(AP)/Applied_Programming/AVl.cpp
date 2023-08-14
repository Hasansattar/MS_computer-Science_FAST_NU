//AVL - Rotations
	node* singleRightRotate(node* &t);
	node* singleLeftRotate(node* &t);
	node* doubleRightLeftRotate(node* &t);
	node* doubleLeftRightRotate(node* &t);
	int getBalance(node* t);





node* insertRecursive(node* &t, int val )
{
	if (t==NULL)
	{
		 t = new node(val);
	}
	else if (t->info == val){
		cout<<"Record already exist"<<val<<endl;
	}
	else if (val < t->info) // insert on left subtree
	{
	    Insert(t->left , val );
	    int bf= height(t->left) - height(t->right);
	    if(bf == 2)
            {
                if(val < t->left->info)
                    singleRightRotate(t);
                else
                    doubleLeftRightRotate(t);
            }
	}
	else if (val > t->info) // Right side
	{
	    Insert( t->right,val);
	    int bf=height(t->left) - height(t->right); 
	    if(bf == -2)
            {
                if(val > t->right->info)
                    singleLeftRotate(t);
                else
                    doubleRightLeftRotate(t);
            }
	}
}









int treeHeight(node *t)
{
	int l_height=0;
	int r_height=0;
	    if (t == NULL)
		return -1;
	    else
	    {
	       l_height = treeHeight(t->left);
	       r_height = treeHeight(t->right);
		if (l_height > r_height)
		    return (l_height + 1);
		else
		    return (r_height + 1);
	    }
}






    node* BST doubleRightLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }
    
    
    node* BST doubleLeftRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }
    
    node* BST singleRightRotate(node* &t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        return u;
    }
    node* BST singleLeftRotate(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        return u;
    }