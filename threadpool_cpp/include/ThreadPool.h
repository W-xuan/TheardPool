#pragma once
#include "TaskQueue.h"
#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>

class ThreadPool
{
public:
    ThreadPool(int min, int max);

    ~ThreadPool();

    void addTask(Task task);

    int getBusyNumber();

    int getAliveNumber();

private:
    static void *worker(void *arg);
    static void *manager(void *arg);
    void threadExit();

private:
    TaskQueue *taskQ;

    pthread_t managerID;
    pthread_t *threadIDs;
    int minNum;
    int maxNum;
    int busyNum;
    int liveNum;
    int exitNum;
    pthread_mutex_t mutexPool;
    pthread_cond_t notEmpty;
    static const int NUMBER = 2;

    int shutdown;
};
