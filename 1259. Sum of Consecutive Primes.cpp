#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std ;

void getPrimeList(int* & list , int & len , int num)
{
   len = 0 ;
   int* array = new int[num + 1] ; 
   for(int i = 0 ; i <= num ; i ++) array[i] = 0 ;
   for(int i = 2 ; i < num ; i ++)
   {
   	  if(!array[i])
   	  {
   	  	list[len ++] = i ;
   	  	for(int j = i ; j < num ; j += i)
   	  	array[j] = 1 ;
	  }
   }
}

int main()
{
	int n ;
	int * list = new int[10000 + 1] ;
	int len ;
	getPrimeList(list, len , 10000) ;
	
	while(scanf("%d" , &n) != EOF && n)
	{
		int ans = 0 ;
		for(int i = 0 ; list[i] <= n ; i ++)
		{
			int sum = 0  , ptr = i ;
			while(sum < n)
			{
				sum += list[ptr ++] ;
				if(sum == n)
				{
					ans ++ ;
					break ;
				}
			}
		}
		printf("%d\n" , ans) ;
	}
	
	return 0 ;
}

