#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std ;

long long mod ;

long long cube3(long long cur)
{
    long long temp = cur ;
    long long last ;
    last = (temp % mod) * ( temp % mod ) % mod * ( temp % mod ) % mod ;
    return last ;
}


int main()
{
    int c ;
    cin >> c ;
    while(c--)
    {
        int len = 0 ;
        long long num , temp;
        cin >> num ;
        temp = num ;
        mod = 1 ;
        while(temp!=0)
        {
            mod *= 10 ;
            len ++ ;
            temp /= 10 ;
        }

        long long cur_mod = 10 ;
        long long result = 1 ;
        for(int i = 0 ; i < len ; i ++ )               //一位一位地向左计算
        {
            long long add = cur_mod / 10 ;
            long long last_n = num % cur_mod ;

            while( cube3(result) % cur_mod != last_n )  //找到后n位满足的数result
            {
                result += add  ;
            }
            cur_mod *= 10 ;
        }
        result %= mod ;
        cout << result << endl;
    }
}
