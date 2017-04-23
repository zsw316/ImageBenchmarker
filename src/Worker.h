#ifndef WORKER_H
#define WORKER_H

#include <cstring>
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include<sys/time.h>
#include "def.h"
#include "ImageHelper.h"

using namespace std;

typedef struct 
{
    uint32_t processCount;
    uint32_t sizeSum;
} WorkerStatistic;

class Worker
{
public:
    Worker(uint32_t id, ImageHelper *helper);
    ~Worker();

    void start();
    void stop();

    void obtainMutex();
    void releaseMutex();

    void increaseStatistic();
    void getStatisticAndClear(uint32_t &count, uint32_t &sum);

    ImageHelper *getImageHelper() {return this->imageHelper;}

private:
    uint64_t GetTimeStamp();

private:
    uint32_t workerId;
    pthread_t threadId;   
    pthread_mutex_t mutex; 

    ImageHelper *imageHelper;

    WorkerStatistic statistic;
};

#endif