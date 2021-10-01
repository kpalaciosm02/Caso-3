#include <iostream>
using namespace std;

#ifndef NODE
#define NODE

struct node{
    int data;
    node * next;

    node(){
        data = 0;
        next = NULL;
    }

    node(int _data){
        data = _data;
        next = NULL;
    }

    void print(){
        cout << "Node data: " << data << endl;
    }
};

#endif