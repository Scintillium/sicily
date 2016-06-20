// Problem#: 1021
// Submission#: 4597653
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include "cstdio"
#include "stack"
using namespace std ;
int couple[1000000] ; // ���� couple ��ϵ 
bool match(int n) ;  // �ж��Ƿ���ȫ���Ƴ��ĺ��� 

int main()
{
    int n , husb , wife ;
    while(scanf("%d" , & n) && n != 0)
    {
        for(int i = 0 ; i < n ; i ++)
        {
            scanf("%d%d" , &husb , &wife) ;
            couple[husb] = wife ;  // ����һ�Է�����һ���ı�� 
            couple[wife] = husb ;
        }
        printf(match(n) ? "Yes\n" : "No\n") ; //���ݽ�����yes��no 
    }
    return 0 ;
} 

bool match(int n)
{
    stack <int> st ; // ��stack�����潫Ҫ�Ƴ����� 
    for(int i = 1; i < 2 * n + 1 ; i ++)
    {
        if(st.empty() || st.top() != couple[i])  //  ���stack Ϊ�ջ���stack�Ķ����뵱ǰ���Ƿ򸾣�����һ��stack�� 
        st.push(i) ;
        else
        st.pop() ;  // ��Ϊһ�ԣ���ͽ��������� 
    } 
    return st.empty() ;
}                                 
