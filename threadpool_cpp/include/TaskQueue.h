#pragma once
#include <queue>
#include <pthread.h>

using callback = void (*)(void *);
struct Task
{
    Task()
    {
        this->function = nullptr;
        this->arg = nullptr;
    }
    Task(callback f, void *arg)
    {
        this->function = f;
        this->arg = arg;
    }
    callback function;
    void *arg;
};

class TaskQueue
{
public:
    TaskQueue();

    ~TaskQueue();

    void addTask(Task task);
    void addTask(callback f, void *arg);

    Task getTask();

    inline int gettaskNumber()
    {
        return m_taskQ.size();
    }

private:
    std::queue<Task> m_taskQ;
    pthread_mutex_t m_mutex;
};
