//  main.cpp
//  BST
//  Created by Hina Khalid  on 17/06/2020.
//  Copyright © 2020 Hina Khalid . All rights reserved.
//used by HabibaAtique
//edited by Habiba Atique
// Binary Search Tree
//Datastructures and Algorithms

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/////////////////BST

class treeNode
{
public:
    treeNode * left;
    treeNode * right;
    string  data;
    treeNode* parent;
};


class BST
{
    
public:
    
    treeNode * root;
    
    BST()
    {
        root=NULL;
    }
    
    ////////// Inorder Traversal
    
    void InorderTraverse(treeNode *n )
    {
        if (n!=NULL)
        {
            InorderTraverse(n->left);
            cout<<n->data<<" ";
            InorderTraverse(n->right);
        }
    }
    
    ////////// Postorder Traversal
    
    void PostorderTraverse(treeNode *n)
    {

       if (n!=NULL)
        {
	   		PostorderTraverse(n->left);
			PostorderTraverse(n->right);
			cout << n->data<<" ";
    	}
        
        
        
    }
    
    ////////// Preorder Traversal
    
    void PreorderTraverse(treeNode *n)
    {
        
        if (n!=NULL)
        {
        	            cout<<n->data<<" ";
            PreorderTraverse(n->left);

            PreorderTraverse(n->right);
        }
        
        
        
    }
    
    ////////// Insert in Tree
    
    void insert( string m)
    {
        treeNode *z=new treeNode();
        z->data=m;
        z->left=NULL;
        z->right=NULL;
        
        treeNode *y=NULL;
        treeNode *x=root;
        
        while(x!=NULL)
        {
            
            y=x;
            if(x->data.compare(z->data)>0)
                x=x->left;
            else
                x=x->right;
            
        }
        z->parent=y;
        if(root==NULL)
            root=z;
        else if(y->data.compare(z->data)<0)
            y->right=z;
        else
            y->left=z;
    }
    
    ////////// Min Tree
    
    string TreeMin(treeNode* x=NULL)
    {
        if (x==NULL)         //  to make function usable for both kind of function calls use in this code
            x=root;
        while(x->left!=NULL)
        {
        	
            x=x->left;
		}
        
        return x->data;
    }
    
    ////////// Max Tree

     string TreeMax(treeNode* x=NULL)
    {
         if (x==NULL)         //  to make function usable for both kind of function calls use in this code
            x=root;
            while(x->right!=NULL)
		{
        	
            x=x->right;
        }
        return x->data;
        
    }
    
    /////////// Tree Search
    
    treeNode* search(string s)
    {
    	treeNode *x;
    	x=root;
    	if (root==NULL)
    	{
    		cout<<"tree is empty"<<endl;
		}
        else if(root!=NULL)
		{
			while(x->data!=s )
			{
			
			if(s<x->data)
			{
				
				if(x->left==NULL)
				{
					cout<<"...NO MATCH"<<endl;
					break;
				}
				x=x->left;
			}
			else
			{
				
				if(x->right==NULL)
				{
					cout<<"...NO MATCH"<<endl;
					break;
				}
				x=x->right;
			}
			}
		}	
		
        return x;
    }
    
    
    
  //Predecessor of x
    
    
    treeNode* Predecessor(string x)
    {
        treeNode * c=search(x);
        
        if(c->left!=NULL)
        {
            string val=TreeMax(c->left);
            
            // TreeMin will return the minimum value not node containing that value, but this function has to return the node. How to handle it without changing TreeMin
          cout<<val;
		  return search(val);
           
        }
        else
        {	
        	if(c->data<c->parent->data)
            {return c;}
          	if(c->data>c->parent->data)
            {return c->parent;}
        }
        
    }
    ////SUCCESSOR oF x
    string Successor(string x)
    {
        treeNode * c=search(x);
        if(c->right!=NULL)
        {
            string val=TreeMin(c->right);
            
            // TreeMin will return the minimum value not node containing that value, but this function has to return the node. How to handle it without changing TreeMin
		  return val;
           
        }
        else
        {
        	if(c->data>c->parent->data)
            {return c->data;}
          	if(c->data<c->parent->data)
            {return c->parent->data;}
        }
        
    }
    
 
    
  //Delete from tree
    
    void del( string x)
    {
    	treeNode* val=search(x);
		if(val->left!=NULL && val->right!=NULL)//LEFT & RIGHT both exist then, we'll not check if the value is left or right child of its parent
        {
			treeNode *t=search(Successor(x));
			string temp=Successor(x);
        	search(Successor(x))->data=x;
        	val->data=temp;
			t->parent->left=NULL;
		}
		else 									//Either LEFT or RIGHT or BOTH are NULL, we'll have to check if the value is LEFT OR RIGHT child of its parents
		{
	       	if(val->data<val->parent->data) //VALUE is LEFT child
			{
		        if(val->left==NULL && val->right==NULL) //LEAF NODE 
		        {
		        	val->parent->left=NULL;
				}
		        else if(val->left!=NULL  )//Left is not NULL
		        {
		        	val->parent->left=val->left;
		        	
				}
				else if(val->right!=NULL)//RIGHT is not NULL
		        {
		        	val->parent->left=val->right;	
				}
			}
			else 						//VALUE is RIGHR child
			{
		        if(val->left==NULL && val->right==NULL) //LEAF NODE
		        {
		        	val->parent->right=NULL;
				}
		        else if(val->left!=NULL ) //Left is not NULL
		        {
		        	val->parent->right=val->left;
				}
				else if( val->right!=NULL)	//Left is not NULL
		        {
		        	val->parent->right=val->right;
				}
	   		}
		}
		cout<<"DELETION COMPLETE"<<endl;
	}

};

int main()
{
    BST St;
    St.insert("pat");
    St.insert("use");
    St.insert("zoo");
    St.insert("try");
    St.insert("bat");
    St.insert("hay");
    St.insert("key");
    St.insert("jig");
    
    cout<<St.TreeMin();
    St.InorderTraverse(St.root);
    cout<<endl;
    St.PreorderTraverse(St.root);
    cout<<endl;
    
    cout<<"Treemin is: "<<St.TreeMin()<<endl;
    cout<<endl;
    St.del("pat");
    cout<<endl;
    St.PostorderTraverse(St.root);
	cout<<endl;
	cout<<"successor of hay is: "<<St.Successor("hay")<<endl;
    St.PreorderTraverse(St.root);
 /*   cout<<St.TreeMax()<<endl;
    
    treeNode* scNode=Predecessor("");
    cout<<scNode->data<<endl;
    cout<<St.Successor("")<<endl;
    
    
    St.PreorderTraverse();
    cout<<endl;
    St.PostorderTraverse();
    cout<<endl;
    
    treeNode* sNode=St.search("");
    if(sNode!=NULL)
        cout<<sNode->data<<endl;
    else
        cout<<"Data not found"<<endl;
    
    St.del("jig");
    St.InorderTraverse(St.root);
    cout<<endl;
    
    St.del("bat");
    St.InorderTraverse(St.root);
    cout<<endl;
    
    St.del("use");
    St.InorderTraverse(St.root);
    cout<<endl;
 */
    
}

