#include "palletNode.hpp"

#ifndef PALLET_STACK
#define PALLET_STACK

struct palletStack{
    //Struct that simulates a stack of pallets
    palletNode * firstNode;

    palletStack(){
        //Constructor method
        firstNode = NULL;
    }

    bool isEmpty(){
        //Checks if the stack is empty
        return firstNode == NULL;
    }

    int size(){
        //Returns an intiger with the size of the stack
        if (isEmpty()){
            return 0;
        }
        else{
            int palletAmount = 0;
            palletNode * tmp = firstNode;
            while (tmp != NULL){
                palletAmount += 1;
                tmp = tmp->next;
            }
            return palletAmount;
        }
    }

    void push(string _name, int _amount, string _unit){
        //Puts a new node on top of the stack
        palletNode * tmp = new palletNode(_name, _amount, _unit);
        if (isEmpty()){
            firstNode = tmp;
        }
        else{
            tmp->next = firstNode;
            firstNode = tmp;
        }
    }

    palletNode * pop(){
        //Takes out the first node of the stack and returns it(top)
        if (isEmpty()){
            cout << "Empty stack given, there is no data to pop." << endl;
            return NULL;
        }
        else{
            palletNode * tmp = firstNode;
            firstNode = firstNode->next;
            return tmp;
        }
    }

    palletNode * top(){
        //Returns the first node of the stack(top)
        if (isEmpty()){
            cout << "Empty stack given, there is no data to pop." << endl;
            return NULL;
        }
        else{
            return firstNode;
        }
    }

    void print(){
        //Prints the info of every node of the stack
        if (isEmpty()){
            cout << "Empty stack given." << endl;
        }
        else{
            palletNode * tmp = firstNode;
            while (tmp != NULL){
                tmp->print();
                tmp = tmp->next;
            }
        }
    }
};

#endif