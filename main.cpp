//Shreya Gogini
//p4.cpp
//Desc : holds the main function for calling the methods from TodoList

#include <iostream>
#include "list.h"
#include <sstream>

using namespace std;

int main(){
    //Initializing the variables
    string line;
    string name;
    string text;

    string extra;

    //Initiallizing the checks
    bool done = false;
    bool bad_input = false; 
    
    //creating two class instances to store two linked lists
    TodoList task;
    TodoList saved;

    //while the user wants to continue and there is an input
    while(!done && getline(cin, line)){
        stringstream stream (line);
        string word;
        stream >> word;
        bad_input = false; 

        //if the user wants to quit     
        if (word == "quit"){
            if(!task.check_arguments(stream)){
                done = false;
            }
            else{
                done = true;
            }

        }
        else if(word == "add"){
            if(stream >> name){
                if(getline(stream, text)){
                    task.add(name, text);
                    task.display();   
                }
                else{
                    task.add(name, " ");
                }
            }
            else{
                cout << "Error: No Name" << endl;
                bad_input = true;                
            }
        }
        
        else if(word == "check"){
            if(stream >> name){
                task.check(name);
                
                 
                
                task.display();
                task.check_arguments(stream);
                   
            }
            else{
                cout << "Error: No name" << endl;
                bad_input = true;
            }
        }
        else if(word == "uncheck"){
           
            if(stream >> name){
                if(task.check_arguments(stream)){
                    task.uncheck(name);
                    
                }
                task.display();
            }
            
            
            else{
                cout << "Error: No name" << endl;
                bad_input = true;
            }
        }
        else if(word == "remove"){
            if(stream >> name){
                if(task.check_arguments(stream)){
                    task.remove(name);
                    task.display();
                }
            }
            else{
                bad_input = true;
            }
        }
        //save and load:
        //save makes a copy of the current list
        //load makes a copy of the saved list to the current one
        else if(word == "save"){
            if(task.check_arguments(stream)){
                saved = task;
                task.display();
            }
        }
        else if(word == "load"){
            
            if(getline(stream, name)){
                cout << "Error: Too many arguments" << endl;
            }
            else{
                task = saved;
                task.display();
            }
            
        }

        //if the input is invalid, user is prompted again
        if(bad_input == true){
           // cout << "Error, enter again" << endl;
            stringstream stream(line);
            string word;
            stream >> word;
            
        }
        
    }
    
    return 0;  
   
}
