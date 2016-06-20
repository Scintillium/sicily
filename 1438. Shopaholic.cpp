#include "iostream"
#include "algorithm"
using namespace std ;
int prices[20000+1] ;
int main()
{
    int T ;
    cin >> T ;
    while (T--) {
        int num;
        cin >> num;
        for (int i = 0; i < num; i++) 
            cin >> prices[i];
        sort(prices, prices + num);
        int discount = 0;
        for (int i = num % 3; i < num; i += 3) 
	   {
            discount += prices[i];
        }
        cout << discount << endl;
    }
    return 0;
}
