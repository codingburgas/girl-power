#pragma once
using namespace std;

string encryptXor(string text, int key);

void remove(string& str, int size);

string getXOR(string str, string is);

string Peppering(string encrypt, int size);

string Salting(string encrypt, int size);