#include "pch.h"
using namespace std;

const char lookuparrbin2hex[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

char LeftShift(string bits)
{
	unsigned int result = 0;
	unsigned int shifter0 = 0;
	unsigned int shifter1 = 1;

	for (int n = 0; n < bits.length(); n++)
	{
		result <<= 1; //shift result to the left by 1
		if (bits[n] == '1') result = (result | shifter1);
		else result = (result | shifter0);
	}
	return lookuparrbin2hex[result];
}

string BinToHex(string rowresult)
{
	string endresult = "";
	for (int i = 0; i < rowresult.size(); i = i + 4)
	{
		endresult += LeftShift(rowresult.substr(i, 4));
	}
	return endresult;
}