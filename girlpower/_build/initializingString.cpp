#include "pch.h"
using namespace std;

int FindRandom()
{
    size_t bin = ((int)rand() % 2);

    return bin;
}

string IS(string is, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {

        int x = FindRandom();
        is += to_string(x);
    }
    return is;
}