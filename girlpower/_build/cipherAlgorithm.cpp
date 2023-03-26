#include "cipherAlgorithm.h"
#include "pch.h"

using namespace std;

const char hx[] = {
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    'A',
    'B',
    'C',
    'D',
    'E',
    'F'
};

char toUpper(char input)
{
    return char(input - 32);
}

string HexToBinary(string input, string bin)
{
    size_t size = input.size();
    bin = string(size * 4, '0');

    for (size_t i = 0; i < size; i++)
    {
        if ((int)input[i] > 90)
        {
            toUpper(input[i]);
        }
        unsigned int offset = i * 4;
        string dec;
        dec[0] = input[i];
        int todec = stoi(dec, nullptr, 16);

        for (size_t j = 0; j < 4; j++)
        {
            bin[offset + 3 - j] = ((todec & (1 << j)) != 0) ? '1' : '0';
        }
    }
    return bin;
}
int findRandom()
{
    int bin = ((int)rand() % 2);

    return bin;
}

string IV(string iv, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++) {

        int x = findRandom();

        iv += to_string(x);
    }
    return iv;
}

string encryptXor(string str, string encrypt)
{
    char key[3] = { 'K', 'C', 'Q' };

    for (int i = 0; i < encrypt.size(); i++)
    {
        str += encrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
    }
    return str;
}