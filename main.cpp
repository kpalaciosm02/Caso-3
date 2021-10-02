#include <iostream>
#include "node.hpp"
using namespace std;
#include "stack.hpp"
#include "palletStack.hpp"

int main(){
    palletStack * pila = new palletStack();
    cout << "Empty: " << pila->isEmpty() << endl;
    pila->print();
    pila->push("Arroz", 15, "kg");
    pila->push("Carne", 10, "kg");
    pila->push("Agua", 20, "l");
    cout << "Empty: " << pila->isEmpty() << endl;
    pila->print();
    cout << "Creando nodo" << endl;
    palletNode * nodo = pila->top();
    nodo->print();
    cout << "Probando top" << endl;
    pila->print();
    cout << "Size: " << pila->size() << endl;
    pila->pop();
    pila->print();
}