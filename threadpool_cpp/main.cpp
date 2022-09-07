#include "./include/ThreadPool.h"

void taskFunc(void *arg)
{
    int num = *(int *)arg;
    std::cout << "thread " << pthread_self() << " num = " << num << std::endl;
    sleep(1);
}

int main(void)
{
    ThreadPool pool(3, 10);
    for (int i = 0; i < 100; ++i)
    {
        int *num = new int(i + 100);
        *num = i + 100;
        pool.addTask(Task(taskFunc, num));
    }

    sleep(30);
    return 0;
}
