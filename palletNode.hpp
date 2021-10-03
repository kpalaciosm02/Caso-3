#include <iostream>
using namespace std;
#include "pallet.hpp"
#include <string.h>

#ifndef PALLET_NODE
#define PALLET_NODE

struct palletNode{
    //Node with a pallet as data
    pallet * data;
    palletNode * next;

    palletNode(){
        //Constructor method
        data = new pallet();
        next = NULL;
    }

    palletNode(string _name, int _amount, string _unit){
        //Constructor method
        data = new pallet(_name, _amount, _unit);
        next = NULL;
    }

    void print(){
        //Prints the data of the node
        data->print();
    }
};

#endif