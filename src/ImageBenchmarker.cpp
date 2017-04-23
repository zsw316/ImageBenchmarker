#include "ImageBenchmarker.h"

void ImageBenchmarker::runStatisticer()
{
    uint64_t lastTimestamp = this->GetTimeStamp();
    uint64_t currentTimestamp = lastTimestamp;

    sleep(2);

    while(true)
    {
        uint32_t processCount = 0;
        uint32_t sizeSum = 0;
        
        for(uint32_t i=0; i<getWorkerNum(); i++)
        {
            Worker *worker = getWorker(i);
            if (worker != NULL)
            {
                worker->getStatisticAndClear(processCount, sizeSum);
            }
        }

        currentTimestamp = this->GetTimeStamp();
        double countPerSecond = 1000000.00 * ((double) processCount/(double)(currentTimestamp-lastTimestamp));
        double sizePerSecond = 1000000.00 * ((double) sizeSum/(double)(currentTimestamp-lastTimestamp))/1024.00/2014.00;

        printf("Benchmark: totoal %.2f images, %.2f MByte files processed per second\n", countPerSecond, sizePerSecond);
        
        lastTimestamp = this->GetTimeStamp();

        // Collect statistics in every 5 seconds
        sleep(10);
    }
}

ImageBenchmarker::ImageBenchmarker()
{
    for(uint32_t i=0; i<MAX_WORKER_NUM; i++)
    {
        workerArray[i] = NULL;
    }

    factory = new ImageHelperFactory();
}

bool ImageBenchmarker::initWorkers(uint32_t num, ImageHelperType type, ImageOperation &op)
{
    if (num>MAX_WORKER_NUM)
    {
        error_log("Workers num shall less than %d", MAX_WORKER_NUM);
        return false;
    }

    this->workerNum = num;

    for(uint32_t i=0; i<num; i++)
    {
        // Build image helper
        ImageHelper *helper = this->factory->buildImageHelper(type, op);
        workerArray[i] = new Worker(i, helper);
    }

    return true;
}

void ImageBenchmarker::startBenchmarker()
{
    for(uint32_t i=0; i<this->workerNum; i++)
    {
        workerArray[i]->start();
    }

    runStatisticer();
}

ImageBenchmarker::~ImageBenchmarker()
{
    for(uint32_t i=0; i<MAX_WORKER_NUM; i++)
    {
        if(NULL != workerArray[i])
        {
            workerArray[i]->stop();
            delete workerArray[i];
        }
    }

    delete factory;
}

Worker* ImageBenchmarker::getWorker(uint32_t index)
{
    if (index<this->workerNum)
    {
        return workerArray[index];
    }

    return NULL;
}

uint64_t ImageBenchmarker::GetTimeStamp()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec*(uint64_t)1000000+tv.tv_usec;
}