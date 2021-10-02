#include <iostream>
using namespace std;
#include <string.h>

#ifndef PALLET
#define PALLET

struct pallet{
    string name;
    int amount;
    string unit;

    pallet(){
        name = "";
        amount = 0;
        unit = "";
    }

    pallet(string _name, int _amount, string _unit){
        name = _name;
        amount = _amount;
        unit = _unit;
    }

    void print(){
        cout << "Nombre del producto: " << name << " Cantidad: " << amount << " " << unit << endl;
    }
};

#endif