#include <iostream>
#include <vector>
#include "mingw.thread.h"
#include "mingw.mutex.h"

template <typename T, unsigned int size>
class MThArrAssist
{
  public:
    MThArrAssist()
    {
        _array = new T[size];
        for (auto i = 0; i < size; i++)
        {
            _array[i] = 0;
        }
    }

    ~MThArrAssist()
    {
        delete[] _array;
    }

    T read(unsigned int n)
    {
        if (size > n)
        {
            _lock.lock();
            T res = _array[n];
            _lock.unlock();

            return res;
        }

        return 0;
    }

    write(unsigned int n, T record)
    {
        if (size > n)
        {
            _lock.lock();
            _array[n] = record;
            _lock.unlock();
        }
    }

  private:
    std::mutex _lock;
    T *_array;
};

const unsigned int N = 256;

void threadWrite(MThArrAssist<int, N> &arr)
{
    while (true)
    {
        arr.write(rand() % N, rand() % 100);
    }
}

void threadRead(MThArrAssist<int, N> &arr)
{
    while (true)
    {
        for (unsigned int i = 0; i < N; i++)
        {
            std::cout << arr.read(i) << std::endl;
        }
    }
}

int main()
{
    MThArrAssist<int, N> array;
    std::vector<std::thread> th;

    // Run
    auto i = 0;
    for (; i < rand() % 4; i++)
    {
        th.push_back(std::thread(threadWrite, std::ref(array)));
    }

    std::cout << "init " << i << " thread of write" << std::endl;

    std::thread reader(threadRead, std::ref(array));
    reader.join();

    for (auto &t : th)
    {
        t.join();
    } 

    return 0;
}