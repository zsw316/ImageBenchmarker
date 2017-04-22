#ifndef IMAGE_BENCHMARKER_H
#define IMAGE_BENCHMARKER_H

#include "Worker.h"
#include "def.h"
#include "ImageHelperFactory.h"

#define MAX_WORKER_NUM 100

class ImageBenchmarker 
{
public:
    ImageBenchmarker();
    ~ImageBenchmarker();

    bool initWorkers(uint32_t num, ImageHelperType type, ImageOperation &op);

    void startBenchmarker();
    void runStatisticer();

    uint32_t getWorkerNum() {return workerNum;}
    Worker*  getWorker(uint32_t index);

    uint64_t GetTimeStamp();

private:
    
    Worker* workerArray[MAX_WORKER_NUM];
    uint32_t workerNum;
    ImageHelperFactory* factory;

    pthread_t statisticer;
};

#endif