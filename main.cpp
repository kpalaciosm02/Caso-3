#include <iostream>
#include "node.hpp"
using namespace std;
#include "stack.hpp"

int main(){
    node * tmp = new node(2);
    stack * pila = new stack();
    cout << "vacia: " << pila->isEmpty() << endl;
    pila->push(1);
    cout << "Numer 1 Inserted: " << endl;
    cout << "vacia: " << pila->isEmpty() << endl;
    pila->print();
    pila->push(2);
    pila->push(3);
    pila->print();
    node * borrado = pila->pop();
    borrado->print();
    pila->print();
}