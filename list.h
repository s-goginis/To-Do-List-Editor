//Shreya Gogini
//list.h
//file that holds the headers of the methods and the constructors
#include <iostream>

using namespace std;

//Struct for creating nodes
struct Node{
    string name;
    string text;
    bool checked=false;
    Node *next;        
};

class TodoList{
    //creates a head node
    private:
    Node *head = new Node();
    
    public:
    //default constructor: initializes the constructing instance to have an empty linked list
    TodoList();

    //copy constructor: initializes the constructing instance to match the input, 
    //with a head pointer ppinting to a linked list that with the 
    //same sequence of entries as the input instance but which uses a entirely
    //independent set of node instances to compose the list
    TodoList(TodoList const &other);
    
    //assignment operator: overwrites the assignee to match the assigned instance
    void operator=(TodoList const &other);
    
    //destructor: frees all outstanding memory allocations used by the destructing instance
    ~TodoList();

   // user based methods
    void add(string, string);
    void remove(string);
    void check(string);
    void uncheck(string);

    bool check_arguments (stringstream&);
    
    //prints the list
    void display();
    
}; 
