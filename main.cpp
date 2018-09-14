/* 
Kyle Knudson
CSCI 591
cs301188
Project 11
due: 4/17/18
This project utilizes Binary search trees to work with an inventory.  This program
uses a menu driven system in the client program to allow a user to manipulate a binary 
tree that implements an ordered list ADT.  The various functions associated with the 
tree are used throughout this program to demonstrate this type of implementation.  The 
class methods rely heavily upon recursion to traverse the tree. 
*/


#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;



int main()
{
    BST bst;
    char choice;
    int target, id, quantity;
    string name;
    double price =0.0;
    char ch;
    string filename;
    ifstream in_file;

    cout << "f -- Read an inventory from a file." << endl;
    cout << "i -- Insert an item into the inventory." << endl;
    cout << "r -- Remove an item from the inventory." << endl;
    cout << "e -- Report if the inventory is empty." << endl;
    cout << "a -- Report an item's information." << endl;
    cout << "v -- Report the inventory's total value." << endl;
    cout << "p -- Print the inventory to the terminal."  << endl;
    cout << "h -- See this menu."  << endl;
    cout << "q -- Quit the program."  << endl;

    cin>> choice;

    while (choice != 'q')
    {
        switch (choice) {
            case 'f':
                cout << "Enter Inventory file name:" << endl;
                cin >>filename;
                in_file.open(filename.c_str());

                    in_file >> id;
					
                    while(in_file)
                    {
						in_file >> name;
						in_file >> quantity;
						in_file >> price;
						bst.insert(id, name, quantity, price); 
						in_file >> id;
                    }


                //read file
                in_file.close();
                cin >> choice;
                break;
            case 'i':
              cout << "Enter the description of an item:" << endl;
              cout << "Number:";
              cin >> id;

              cout << endl <<  "Name:";
              cin >> name;

              cout << endl << " Quantity:";
              cin >> quantity;

              cout << endl << "Price:";
              cin >> price;
                //call insert
                bst.insert(id, name, quantity, price);

                cin>> choice;
                break;
            case 'r':
                cin>>target;
				if(bst.present(target))
				{
					bst.remove(target);
					cout << "The item with the id number " << target << " was removed\n";
				}
				else
					cout << " The item is not in the list" << endl;
                //call remove
                cin>>choice;
                break;
            case 'e':
                if (bst.empty() == true)
                    cout << "The inventory is empty.";
                else
                    cout << "The inventory is not empty";
                //call empty
                cin>>choice;
                break;
            case 'a':
                cin>>target;
				cout << bst.present(target);
				if (bst.present(target))
					bst.print(target);
				else
					cout << "Item not found in the inventory" << endl;
                //call print for one item
                cin>>choice;
                break;
            case 'v':
                cout << "The total Value of the inventory is: " << bst.value();
                //call total value
                cin>>choice;
                break;
            case 'p':
                bst.report();
                //print the inventory
                cin>>choice;
                break;
            case 'h':
                cout << "f -- Read an inventory from a file." << endl;
                cout << "i -- Insert an item into the inventory." << endl;
                cout << "r -- Remove an item from the inventory." << endl;
                cout << "e -- Report if the inventory is empty." << endl;
                cout << "a -- Report an item's information." << endl;
                cout << "v -- Report the inventory's total value." << endl;
                cout << "p -- Print the inventory to the terminal."  << endl;
                cout << "h -- See this menu."  << endl;
                cout << "q -- Quit the program."  << endl;
                cin>>choice;
                break;
            case 'q':
                //quits
                break;
			case 'z':
				cout << "enter an id to search for" << endl;
				cin >> target;
				if (bst.present(target))
				cout << " Item present";
				else
					cout << "item not";
        }


    }

}