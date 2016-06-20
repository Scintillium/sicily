#include "iostream"
#include "string" 
using namespace std ;

string add(string str1 , string str2)
{
	int carry = 0 ;
	if(str1.length() > str2.length())
	swap(str1 , str2) ;
	
	string result(str1.length() , '0') ;
	
	for(int i = str1.length() - 1 ; i >= 0 ; i--)
	{
		result[i] = '0' + (((str[i] - '0') + (str[i] - '0') + carry) % 10) ;
		carry = ((str1[i] - '0') + (str2[i] - '0') + carry) / 10 ;
	}
	return carry? "1" + result : result ;
 } 
 
 string mlt(string str1  ,string str2)
 {
 	string product = "0" ;
 	int LSB ;
 	if(str1.length() > str2.length())
 	swap(str1  ,str2) ;
 	int len = str1.length() ;
 	while(1)
 	{
 		LSB = str1[len-- - 1] - '0' ;
 		for(int i = 1 ; i <= LSB ; i ++)
 		product = add(b , product) ;
 		
 		if(len)
 		b += "0" ;
 		else break ;
	 }
	 return product ;
 }
 
 int main()
 {
 	string a , b ;
 	int T ;
 	cin >> T ;
 	while(T --)
 	{
 		cin >> a >> b ;
 		cout << mlt(a , b ) << endl ;
	 }
 }
