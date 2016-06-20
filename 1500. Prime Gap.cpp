#include "iostream"
#include "cmath"
using namespace std ;
bool isPrime(int x)
{
	for(int i = 2 ; i * i <= x ; i ++)
	if(x % i == 0) return 0 ;
	return 1 ;
}
int primeGap(int k)
{
	int p1 = k , p2 = k ;
	while(p1 && !isPrime(p1))p1 -- ;
	while(!isPrime(p2))p2 ++ ;
	return !p1 ? 0 : p2 - p1 ;
}
int main()
{
	int n ;
	while(cin >> n && n)
	{
		cout << primeGap(n) << endl;
	}
}
