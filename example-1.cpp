#include <iostream>
#include "mingw.thread.h"
#include "mingw.mutex.h"

using namespace std;

const unsigned int N = 256;
mutex g_lock;

void read(int *arr)
{
    while (true)
    {
        for (int i = 0; i < N; i++)
        {
            g_lock.lock();
            cout << arr[i] << endl;
            g_lock.unlock();
        }
    }
}

void write(int *arr)
{
    while (true)
    {
        for (int i = 0; i < N; i++)
        {
            g_lock.lock();
            arr[i] += 1;
            g_lock.unlock();
        }
    }
}

int main()
{
    int *array = new int[N];

    // Init
    for (int i = 0; i < N; i++)
    {
        array[i] = 0;
    }

    // Run
    thread t1(read, ref(array));
    thread t2(write, ref(array));

    t1.join();
    t2.join();

    return 0;
}