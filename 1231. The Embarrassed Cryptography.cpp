#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
using namespace std ;
 
void getPrimeNumber(int *& list , int & len , int num)
{
	len = 0 ;
	int * array = new int[num + 1] ;
	for(int i = 0 ; i <= num ; i ++)array[i] = 0 ;
	for(int i = 2 ; i <= num ; i ++)
    {
		if(!array[i])
		{
			list[len ++] = i ;
			for(int j = i ; j <= num ; j += i)
			array[j] = 1 ;
		}
	}
}
 
bool is_mod(string s,int n)           
{  
    int ans = 0;  
    for(int i = 0;i < s.size();i++)  
        ans = (ans*10 + (s[i]-'0')) % n ;  
    if(ans == 0)    return true;  
    else            return false;  
}  

int main()
{
	int L , len ,ans;
	string K ;
	int * list = new int[1000000] ;
	getPrimeNumber(list , len , 1000000) ;
	while(cin >> K >> L , (K[0] !='0' || L))
	{
	    int flag = 1  ;
	    for(int i = 0 ; i < len ; i ++)
	    {
	    	if(list[i] < L && is_mod(K , list[i]))
	    	{
	    		ans = list[i] ;
	    		flag = 0 ;
	    		break ;
			}
		}
		if(!flag)        cout<<"BAD"<<" "<<ans<<endl;  
        else             cout<<"GOOD"<<endl; 
	}
}

