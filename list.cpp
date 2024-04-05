//Shreya Gogini
//list.cpp
//Desc: Holds the logic and methods to run the TodoList class

#include "list.h"
#include <iostream>
#include <sstream>


using namespace std;

//desc : Constructor for the TodoList class
//pre : a head pointer should be created and initialized
//post : sets head to null
TodoList::TodoList(){
    head = nullptr;
}

//desc : copy constructor that copies the current instance of the
//       class' list to the new one
//pre : the current list must exist and should go through
//      the overloaded assignment operator 
//post : updates the current instance with the new copy
TodoList :: TodoList (TodoList const &other){
    head = other.head;
}

//desc : Assigns the values from the list being copied to the new list
//pre : A valid list from TodoList should exist
//post : Only the values from the list should be copied over, not the pointers
void TodoList :: operator = (TodoList const &other){ 
    //de-allocates the list to use "other"
   while(head != nullptr){
    Node *for_deletion = head;
    head = head -> next;
    delete for_deletion;
   }
    //creates a node pointing to the head of the other
   Node *other_iter = other.head;

    //copies the current list to a new one to store
   while(other_iter != nullptr){
    Node *temp = new Node;
    temp->name = other_iter->name;
    temp->text = other_iter->text;
    temp->checked = other_iter->checked;
    temp->next = head;
    other_iter = other_iter->next;
    head = temp;
   }
   
}

//Destructor to deallocate the pointers at the end of the run
TodoList::~TodoList(){ 
    while (head != nullptr) {
        Node *for_deletion = head;
        head               = head->next;
        delete for_deletion;
    }
}

//desc : prints out the list after each command
//pre : head is initialized
//post : none
void TodoList :: display(){
   //iterates through the list and stops when it reaches nullptr
   Node *iter = head;
    while(iter != nullptr){
        char checker = ' ';
        if(iter->checked == true){
            checker = 'X';
        }
        cout << "[" << checker << "]" << iter->name << " " << iter -> text << endl;
        iter = iter -> next;
    }
    cout << endl;
    
}

//desc : adds a new node to the list alphabetically
//pre : head exists
//post : produces an alphabetically ordered list
void TodoList :: add (string item, string desc){
    Node *iter = head;
    
    //while iter is not nullptr
    while(iter && iter -> name != item){
        iter = iter->next;
    }

    //if the name already exists, the text is replaced
    if(iter != nullptr){
        iter -> text = desc;
    }
    else{
        Node *add_new = new Node();
        add_new -> name = item;
        add_new ->text = desc;
        add_new -> checked = false;
        add_new -> next = nullptr;
        //checks if head is empty and is alphabetically less than the others
        if(!head || item < head->name){
            add_new -> next = head;
            head = add_new;
        }
        else{
            Node *current = head;
            //if the name is greater than everything, it is placed after
            while(current -> next && item > current->next->name){
                current = current -> next;
            }
            add_new->next = current->next;
            current->next = add_new;
        }
    }
	
}

//desc : removes a specific node from the list
//pre : user provides a name and the list exists
//post : the list no longer has the node
void TodoList::remove(string name){
    Node *temp = new Node();
    //if the first node is the chosen one
    if(head ->name == name){
        temp = head;
        head = head -> next;
    }
    else{
        //iterates through the list to find the node
        //and creates a new link to keep the list together
        Node *current = head;
        while(current -> next != nullptr){
            if(current->next->name == name){
                temp = current -> next;
                current -> next = current -> next -> next;
            }
            else{
                current = current -> next;
            }
        }
    }
}

//desc : sets the checked member of the node to true
//pre : user provides a name and the list exists
//post : none
void TodoList::check(string name){
    Node *iter = head;
    while(iter != nullptr){
        if(iter -> name == name){
            iter->checked = true;
        }
        iter = iter->next;
    }
    
}

//desc : sets the checked member of the node to false
//pre : user provides a name and the list exists
//post : none
void TodoList::uncheck(string name){
    Node *iter = head;
    while(iter != nullptr){
        if(iter -> name == name){
            iter->checked = false;
        }
        iter = iter->next;
    }
   
} 

bool TodoList ::check_arguments(stringstream& stream){
    string extra = " ";
    if(stream >> extra){
        cout << "Too many arguments" << endl;
        return false;
    }
    else{
        return true;
    }
}

