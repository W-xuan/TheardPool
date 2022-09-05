#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER 2
typedef struct ThreadPool ThreadPool;

ThreadPool *threadPoolCreate(int min, int max, int queueSize);

int threadPoolDestroy(ThreadPool* pool);

void threadPoolAdd(ThreadPool* pool, void(*func)(void*), void* arg);

int threadPoolBusyNum(ThreadPool* pool);

int threadPoolAliveNum(ThreadPool* pool);

void* worker(void* arg);
void* manager(void* arg);
void threadExit(ThreadPool* pool);
#endif