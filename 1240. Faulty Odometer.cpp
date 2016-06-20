#include "cstdio"
#include "cmath"
#include "string"
#include "iostream"
using namespace std ;
int realNumber(string str)
{
	int sum = 0 ;
	int len = str.length() ;
	for(int i = 0 ; i < len ; i ++)
	{
		sum += str[i] - '0' > 4 ? (str[i] - '0' - 1) * pow(9 , len - i - 1) : (str[i] - '0') * pow(9 , len - i - 1) ;
	}
	return sum ;
}

int main()
{
	string n ;
	while(cin >> n && !(n.length() == 1 && n[0] - '0' == 0))
		cout << n << ": " << realNumber(n) << endl;
	return 0 ;
}

