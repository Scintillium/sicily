// Problem#: 1020
// Submission#: 4596217
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include "iostream"
#include "algorithm"
#include "cmath"
#include "string"
using namespace std ;
string ll ; // ����int���͵Ĵ�С����������ʹ��string���� 
int main()
{
    int T , n , len , b[1000];
    cin >> T ;
    while(T --)
    {
          cin >>  n ;
          for(int i = 0 ; i < n ; i ++)
          {
            cin >> b[i] ;
          }
          cin >> ll ; 
          len = ll.length() ;
          cout << "(" ;
          for(int i = 0 ; i < n ; i ++)
          {
            int tmp  = 0 ;
            for(int j = 0 ; j < len ; j ++)
            {
                 tmp = (tmp * 10 + ll[j] - '0') % b[i] ; // ÿһλ���㶼ȡģʹ��tmp������� 
            }
            cout << tmp % b[i];
            if(i != n - 1)
                cout << "," ;
          }
          cout << ")" << endl ;
    }
    return  0 ;
}                                 
