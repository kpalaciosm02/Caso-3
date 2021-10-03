#include <iostream>
using namespace std;
#include <string.h>

#ifndef PALLET
#define PALLET

struct pallet{
    //Struct that simulates a pallet full of a product
    string name;
    int amount;
    string unit;

    pallet(){
        //Constructor method
        name = "";
        amount = 0;
        unit = "";
    }

    pallet(string _name, int _amount, string _unit){
        //Constructor method
        name = _name;
        amount = _amount;
        unit = _unit;
    }

    void print(){
        //Prints the data of the pallet
        cout << "Nombre del producto: " << name << " Cantidad: " << amount << " " << unit << endl;
    }
};

#endif