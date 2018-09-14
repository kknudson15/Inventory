#include <iostream>
using namespace std;

class BST {

public:
    typedef int Item;

    BST();

    ~BST();

    bool empty();

    void insert(Item, string, Item, double);

    void remove(Item);

    void report();

    int length();

    bool present(Item);

    void print(Item);

    double value();

private:
    struct Node {
//Item data; //remove after testing
        int id;
        string name;
        int quantity;
        double price;
        Node *left;
        Node *right;
    };

    Node *root;

    void destroy(Node *);
    int find_length(Node *);
    void help_remove(Node * &, Item);
    void help_report(Node *&);
    void remove_node(Node * &);
    double total_value(Node * );
    void help_print(Node * &t, Item target);
	void help_insert(Node * &t, Item entry, string name, Item quantity, double price);

};

