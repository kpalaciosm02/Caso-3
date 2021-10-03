#include "node.hpp"

#ifndef STACK
#define STACK

struct stack{
    //Struct that simulates a stack of intigers
    node * firstNode;

    stack(){
        //Constructor method
        firstNode = NULL;
    }

    bool isEmpty(){
        //Checks if the stack is empty
        return firstNode == NULL;
    }

    void push(int _data){
        //Puts a new node on top
        node * tmp = new node(_data);
        if (isEmpty()){
            firstNode = tmp;
        }
        else{
            tmp->next = firstNode;
            firstNode = tmp;
        }
    }

    node * pop(){
        //Deletes the first node and returns it
        if (isEmpty()){
            cout << "Empty Stack given, there is no data to pop." << endl;
            return NULL;
        }
        else{
            node * tmp = firstNode;
            firstNode = firstNode->next;
            return tmp;
        }
    }

    node * top(){
        //Returns the first node
        if (isEmpty()){
            cout << "Empty stack given, there is no data to pop." << endl;
            return NULL;
        }
        else{
            return firstNode;
        }
    }

    void print(){
        //Prints the data of every node of the stack
        if (isEmpty()){
            cout << "Empty Stack given:" << endl;
        }
        else{
            node * tmp = firstNode;
            while (tmp != NULL){
                cout << tmp->data << "-> ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }
        
};


#endif