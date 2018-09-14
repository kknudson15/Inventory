#include <iostream>
#include "BST.h"
using namespace std;

//Precondition: a class BST must exist.
//Postcondition: the Node * pointer for root is set to NULL.
BST::BST()
{
    root = NULL;
}

//Precondition: A class BST must exist.
//Postcondition: The nodes in the tree are removed from memory.
BST:: ~BST()
{
    destroy(root);
}

//Precondition: A BST class object must exist
//Postcondition: Returns true if the tree is empty, and false if there is a NODE in the tree.
bool BST:: empty()
{
    return root == NULL;
}

//Precondition: A BST class must exist and a variable of type Item, string, Item and double must be passed to the function
//Postcondition: This function inserts the variable into the binary search tree.
void BST:: insert (Item id, string name, Item quantity, double price)
{
	help_insert(root, id, name, quantity, price);
}

//Precondition: A BST class must exist and a variable of type Item, string, Item and double must be passed to the function
//Postcondition: This function inserts the variable into the binary search tree.
void BST:: help_insert(Node * &t, Item id, string name, Item quantity, double price)
{
	if(t==NULL)
	{
		t = new Node;
		t->id = id;
		t->name = name;
		t->quantity = quantity;
		t->price = price;
		t->left = NULL;
		t->right = NULL;
	}
	else if (id < t-> id) 
		help_insert(t->left, id, name, quantity, price);
	else 
		help_insert(t->right, id, name, quantity, price);
}


//Precondition: A BST class object must exist and a variable of type ITEM must be passed to the function.
//Postcondition: The variable is removed from the Binary Search Tree.
void BST:: remove(Item target)
{
		help_remove(root,target);
}


//Precondition: A BST class object must exist and a pointer to a node must be passed by reference
//Postcondition: THe node that the pointer points to is removed and the adjacent nodes are attached.
void BST:: remove_node(Node *&t)
{
    Node * ptr;
    Node * back;

    if(t->left == NULL && t->right == NULL)
    {
        delete t;
        t= NULL;
    }
    else if (t->left == NULL)
    {
        ptr = t;
        t= t->right;
        delete ptr;
    }
    else if (t->right == NULL)
    {
        ptr = t;
        t = t->left;
        delete ptr;
    }
    else
    {
        back = t;
        ptr = t->right;
        while(ptr->left != NULL)
        {
            back = ptr;
            ptr =ptr->left;

        }
		t->id = ptr ->id;
		t->name = ptr->name;
		t->quantity = ptr ->quantity;
		t->price = ptr->price;
       // t->data = ptr->data;
        if(back ==t)
            remove_node(back->right);
        else
            remove_node(back->left);

    }
}

//Precondition: A BST class object must exist.
//Postcondition: THe contents of the entire inventory is printed.
void BST:: report()
{
    cout << "ID\t" << "Name\t" << "quantity\t" << "price\n";
    cout << "_________________________________" << endl;
    help_report(root);
}

//Precondition: A BST class object must exist
//Postcondition: THe value of the inventory is returned as a double.
double BST :: value()
{
	Node * p = root;
    return total_value(p);
}

//Precondition: A BST class object must exist.
//Postcondition: the total value of the items in the quantity is returned.
double BST:: total_value(Node * p)
{
    double sum = 0;
    if(p!= NULL)
    {
        sum = (p->price * p->quantity) + total_value(p->left) + total_value(p->right);
    }
		return sum;
}

//Precondition: A BST class object must exist.
//Precondition: The total length of the search tree is returned.
int BST:: length()
{
    return find_length(root);
}

//Precondition: A BST class object must exist and a variable of the type Item must be passed to the function.
//Postcondition: Returns true if the target item is in the tree, otherwise returns false.
bool BST:: present(Item target)
{
    Node * p = root;
    while (true)
    {
        if (p== NULL)
            return false;
        else if (target<p->id)
            p = p->left;
        else if (target = p->id)
            return true;
        else // target >p -> data
        p = p ->right;
    }
}

//Precondition: A BST class object must exist and a variable of the type Item must be passed to the function.
//Postcondition: Prints out the data associated with the item that is passed to the function.
void BST:: print(Item target)
{
	Node * p = root;
  
    help_print(p, target);
}


//Precondition: A BST class object must exist and a pointer to a Node must be passed to the function.
//Postcondition: The Node and its subtree is removed from the Binary Search Tree.
void BST :: destroy(Node *p)
{
    if(p!= NULL)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}


//Precondition: A BST class object must exist and a pointer to a Node must be passed to the function.
//Postcondition: Returns the length of the Binary search tree.
int BST :: find_length(Node *r)
{
    if(r==NULL)
        return 0;
    else
        return find_length( r->left) + find_length(r->right) + 1;
}

//Precondition: A BST class object must exist and a pointer to a Node must be passed along with a variable of type Item.
//Postcondition: The Node that the pointer points to is removed from the Binary Search Tree.
void BST:: help_remove(Node *&t, Item target)
{
    if(t->id == target)
        remove_node(t);
    else if(target<t->id)
        help_remove(t->left,target);
    else
        help_remove(t->right, target);
}

//Precondition: A BST class object must exist and a pointer to a Node must be passed to the function
//Postcondition: The contents of each node are printed out.
void BST:: help_report(Node * &t)
{
    if(t != NULL) 
	{
        cout << t->id << "\t";
		cout << t->name << "\t";
        cout << t->quantity << "\t\t";
        cout << t->price << "\n";
		
		help_report(t->right);
        help_report(t->left);
    }
	

  //  else;
        //cout << "The inventory is empty";
}

//Precondition: A BST class object must exist and a pointer to a Node must be passed along with a variable of type Item.
//Postcondition: Prints out the content of the Node that the pointer points to.
void BST:: help_print(Node * &t, Item target)
{
    if(t->id == target)
    {
        cout << "ID\t" << "Name\t" << "quantity\t" << "price\n";
        cout << "_________________________________" << endl;
        cout << t->id << "\t";
		cout << t->name << "\t";
        cout << t->quantity << "\t\t";
        cout << t-> price << "\n";
    }

    else if(target < t->id)
	{
      help_print(t->left, target);
	}
    else
	{
        help_print(t->right, target);
	}
}