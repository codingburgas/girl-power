#include "pch.h"
using namespace std;

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

void remove(string& str, int size)
{
    for (int i = 0; i < size; i++)
    {
        str = str + "0";
    }
}

string getXOR(string str, string is)
{

    int strSize = str.length();
    int isSize = is.length();

    if (strSize > isSize)
    {
        remove(is, strSize - isSize);
    }
    else if (isSize > strSize)
    {
        remove(str, isSize - strSize);
    }

    int len = max(strSize, isSize);

    string result = "";
    for (int i = 0; i < len; i++)
    {
        if (str[i] == is[i])
        {
            result += "0";
        }
        else
        {
            result += "1";
        }
    }
    return result;
}
string Peppering(string encrypt, int size)
{
    string peppering = IS(encrypt, size);
    return peppering;
}
string Salting(string encrypt, int size)
{
    int sizePeppering = encrypt.size();
    string salting = IS(encrypt, size);
    for (int i = salting.size() - sizePeppering; i < salting.size(); i++)
    {
        size_t salt = ((int)rand() % sizePeppering);
        srand(time(NULL));
        swap(salting[i], salting[salt]);
    }
    return salting;
}