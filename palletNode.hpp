#include <iostream>
using namespace std;
#include "pallet.hpp"
#include <string.h>

#ifndef PALLET_NODE
#define PALLET_NODE

struct palletNode{
    pallet * data;
    palletNode * next;

    palletNode(){
        data = new pallet();
        next = NULL;
    }

    palletNode(string _name, int _amount, string _unit){
        data = new pallet(_name, _amount, _unit);
        next = NULL;
    }

    void print(){
        data->print();
    }
};

#endif