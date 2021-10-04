#include "palletQueue.hpp"

#ifndef LIFTTRUCK
#define LIFTTRUCK

struct liftTruck{
    //Representation of a lifttruck
    int timeForJob;
    palletQueue * queue;

    liftTruck(){
        //Constructor method
        timeForJob = 0;
        queue = new palletQueue();
    }

    liftTruck(int _timeForJob, palletQueue * _queue){
        //Constructor method
        timeForJob = _timeForJob;
        queue = _queue;
    }

    void addJob(string _name, int _amount, string _unit){
        //Adds a job to the queue
        queue->add(_name, _amount, _unit);
    }

    void deleteJob(){
        //Deletes a job from the queue
        queue->dequeue();
    }

    int work(){
        //Calculates how much time it takes to do all the work in the queue
        int fullTime = 0;
        while (queue->firstNode != NULL){
            fullTime += timeForJob;
            queue->dequeue();
        }
        return fullTime;
    }
};

#endif