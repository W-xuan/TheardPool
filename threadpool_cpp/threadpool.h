#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <iostream>
#include <queue>
#include <thread>
using callback = void(*)(void*);
struct Task
{
    Task()
    {
        function = nullptr;
        arg = nullptr;
    }
    Task(callback f, void* arg)
    {
        function = f;
        this->arg = arg;
  
    }
    callback function; 
    void* arg;
};

class TaskQueue
{
public:
    TaskQueue();
    ~TaskQueue();

    void addTask(Task& task);
    void addTask(callback func, void* arg);

    Task takeTask();
    inline int taskNumber()
    {
        return m_queue.size();
    }
private:
    pthread_mutex_t m_mutex;
    std::queue<Task> m_queue;
};

#endif