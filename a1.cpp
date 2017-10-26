#include <iostream>
#include <thread>

using namespace std;

const unsigned int N = 256;

void read(int *arr)
{
    while (true)
    {
        for (int i = 0; i < N; i++)
        {
            cout << arr[i] << endl;
        }
    }
}

void write()
{
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
    // thread first(read, ref(array));
    // thread second(write, 0);

    return 0;
}