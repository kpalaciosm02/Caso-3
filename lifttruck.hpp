#include "palletQueue.hpp"

#ifndef LIFTTRUCK
#define LIFTTRUCK

struct lifttruck{
    int timeForJob;
    palletQueue * queue;

    lifttruck(){
        timeForJob = 0;
        queue = new palletQueue();
    }

    void addJob(string _name, int _amount, string _unit){
        queue->add(_name, _amount, _unit);
    }

    void deleteJob(){
        queue->dequeue();
    }

    int work(){
        int fullTime = 0;
        while (queue->firstNode != NULL){
            fullTime += timeForJob;
            queue->dequeue();
        }
        return fullTime;
    }
};

#endif