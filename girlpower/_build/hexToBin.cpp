#include <string>
#include <iostream>
using namespace std;

const char lookuparrbin2hex[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

char convert_bin2hex(string bits)
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

std::string getHexRowFails(string rowresult)
{
	std::string endresult = "";
	for (int i = 0; i < rowresult.length(); i = i + 4)
	{
		endresult += convert_bin2hex(rowresult.substr(i, 4));
	}
	return endresult;
}

int main()
{
	std::string rowresult = "101001010101";
	cout << rowresult << " in hex is " << getHexRowFails(rowresult) << endl;
}