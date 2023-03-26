#include "cipherAlgorithm.h"
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
            (ascii % 2) ? bin.push_back('1') :
                bin.push_back('0');
            ascii /= 2;
        }
        reverse(bin.begin(), bin.end());
    }return bin;
}

int findRandom()
{
    int bin = ((int)rand() % 2);

    return bin;
}

string IV(string iv, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {

        int x = findRandom();
        iv += to_string(x);
    }
    return iv;
}
string encryptXor(string text, int key)
{

    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
        {
            text[i] = char(int(text[i] + key - 65) % 26 + 65);
        }
        else
        {
            text[i] = char(int(text[i] + key - 97) % 26 + 97);
        }
    }
    return text;
}
string xoring(string str, string iv, int size) {
    string x = "";

    for (int i = 0; i < size; i++)
    {
        if (str[i] == iv[i])
            x += "0";
        else
            x += "1";
    }
    return x;
}
string Peppering(string encrypt, string iv)
{
    int count = ((int)rand() % 4);
    srand(time(NULL));

    for (int i = encrypt.size(); i < encrypt.size() * 2; i++)
    {
        encrypt += iv[count];
    }
    return encrypt;
}
string Salting(string encrypt, string iv)
{
    int count = ((int)rand() % 4);
    srand(time(NULL));

    for (size_t i = 0; i < encrypt.size(); i + 2)
    {
        encrypt[i] += iv[count];
    }return encrypt;
}