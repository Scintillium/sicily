#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int col;
    string str;
    while(cin>>col&&col)
    {
        char a[201][201];
        cin>>str;
        int len = str.length();
        int rows = len/col;
        for(int i=0;i<rows;i++)
        {
            if(i%2==0) //�����ҵ����
            {
                for(int j=0;j<col;j++) //ÿ�ζ�ȡn��
                     a[i][j]=str[i*col+j];
            }
            else  //���ҵ���
            {
                for(int j=0;j<col;j++)
                     a[i][j]=str[i*col+col-1-j];
            }
        } 

        for(int j=0;j<col;j++)
            for(int i=0;i<rows;i++)
                cout<<a[i][j]; //��һ���е�����Ϳ��Եõ�����
         cout << endl ;
    }
    return 0;
}
