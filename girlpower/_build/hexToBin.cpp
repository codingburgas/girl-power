#include "pch.h"
using namespace std;

char toUpper(char input)
{
    return char(input - 32);
}

string HexToBinary(string input, string bin)
{
    int size = input.size();

    bin = "";

    for (int i = 0; i <= size; i++)
    {
        int ascii = int(input[i]);

        while (ascii > 0)
        {
            (ascii % 2) ? bin.push_back('1') : bin.push_back('0');
            ascii /= 2;
        }
        reverse(bin.begin(), bin.end());
    }
    return bin;
}
int binToHex(int hex, string binary)
{
    int size = binary.size();

    for (int i = 0; i < size; i++)
    {
        hex += (binary[size - i - 1] - 48) * pow(2, i);
    }
    return hex;
}