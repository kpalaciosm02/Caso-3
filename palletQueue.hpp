#include "palletNode.hpp"

#ifndef PALLET_QUEUE
#define PALLET_QUEUE

struct palletQueue{
    //Struct that simulates a queue of pallets
    palletNode * firstNode;

    palletQueue(){
        //Constructor method
        firstNode = NULL;
    }

    bool isEmpty(){
        //Checks if the queue is empty
        return firstNode == NULL;
    }

    int size(){
        //Returns an intiger with the size of the queue
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
    void add(string _name, int _amount, string _unit){
        //Puts a new node at the start of the queue
        palletNode * tmp = new palletNode(_name,_amount, _unit);
        if (isEmpty()){
            firstNode = tmp;
        }
        else{
            tmp->next = firstNode;
            firstNode = tmp;
        }
    }

    void addNode(palletNode * tmpNode){
        if (isEmpty()){
            firstNode = tmpNode;
        }
        else{
            tmpNode->next = firstNode;
            firstNode = tmpNode;
        }
    }

    palletNode * front(){
        //Returns the last node from a queue, but it does delete it
        if (isEmpty()){
            cout << "Empty stack given, there is no data in this queue."<< endl;
            return NULL;
        }
        else{
            palletNode * tmp = firstNode;
            while (tmp->next != NULL){
                tmp = tmp->next;
            }
            return tmp;
        }
    }

    palletNode * dequeue(){
        //Returns the last node from a queue, it also deletes it
        if (isEmpty()){
            cout << "Empty stack given, there is no data to dequeue." << endl;
            return NULL;
        }
        else{
            palletNode * tmp = firstNode;
            while (tmp->next != NULL){
                tmp = tmp->next;
            }
            palletNode * tmp2 = firstNode;
            while (tmp2->next != tmp){
                tmp2 =  tmp2->next;
            }
            palletNode * res = tmp2->next;
            tmp2->next = NULL;
            return res;
        }
    }

    palletNode * dequeue2(){
        if (isEmpty()){
            cout << "Empty stack given, there is no data to dequeue." << endl;
            return NULL;
        }
        else{
            palletNode * tmp = firstNode;
            firstNode = tmp->next;
            tmp->next = NULL;
            return tmp;
        }
    }

    void print(){
        //Prints the data from every node in the queue
        if (isEmpty()){
            cout << "Empty queue given." << endl;
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