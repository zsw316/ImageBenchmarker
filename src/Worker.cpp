#include "Worker.h"

void *run(void *ptr)
{
    Worker *worker = (Worker *)ptr;
    ImageHelper *helper = worker->getImageHelper();
    helper->init();
    helper->loadImage();

    while(true)
    {
        helper->processImage();
        worker->increaseStatistic();
        usleep(5);
    }
}

Worker::Worker(uint32_t id, ImageHelper *helper)
{
    this->workerId = id;
    this->imageHelper = helper;
    this->statistic.processCount = 0;
    this->statistic.sizeSum = 0;
}

Worker::~Worker()
{
    if (NULL != imageHelper)
    delete imageHelper;
}

void Worker::start()
{
    pthread_mutex_init(&mutex, NULL);
    int ret=pthread_create(&this->threadId,NULL,run,this);

    if(ret!=0)
    {
        error_log("Failed to create thread: ret=%d", ret);
        return;
    }
}

void Worker::stop()
{
    pthread_join(this->threadId,NULL);
}

void Worker::obtainMutex()
{
    pthread_mutex_lock(&this->mutex);
}

void Worker::releaseMutex()
{
    pthread_mutex_unlock(&this->mutex);
}

uint64_t Worker::GetTimeStamp()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec*(uint64_t)1000000+tv.tv_usec;
}

void Worker::getStatisticAndClear(uint32_t &count)
{
    obtainMutex();
    count += this->statistic.processCount;
    this->statistic.processCount = 0;
    releaseMutex();
}

void Worker::increaseStatistic()
{
    obtainMutex();
    this->statistic.processCount++;
    releaseMutex();
}


