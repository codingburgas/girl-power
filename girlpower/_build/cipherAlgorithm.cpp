#include "pch.h"
using namespace std;

void Remove(string& str, int size)
{
    for (int i = 0; i < size; i++)
    {
        str = str + "0";
    }
}

string GetXOR(string str, string is)
{

    int strSize = str.length();
    int isSize = is.length();

    if (strSize > isSize)
    {
        Remove(is, strSize - isSize);
    }
    else if (isSize > strSize)
    {
        Remove(str, isSize - strSize);
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