// Problem#: 1021
// Submission#: 4597653
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include "cstdio"
#include "stack"
using namespace std ;
int couple[1000000] ; // 储存 couple 关系 
bool match(int n) ;  // 判断是否能全部移除的函数 

int main()
{
    int n , husb , wife ;
    while(scanf("%d" , & n) && n != 0)
    {
        for(int i = 0 ; i < n ; i ++)
        {
            scanf("%d%d" , &husb , &wife) ;
            couple[husb] = wife ;  // 储存一对夫妇中另一个的编号 
            couple[wife] = husb ;
        }
        printf(match(n) ? "Yes\n" : "No\n") ; //根据结果输出yes或no 
    }
    return 0 ;
} 

bool match(int n)
{
    stack <int> st ; // 用stack来储存将要移除的人 
    for(int i = 1; i < 2 * n + 1 ; i ++)
    {
        if(st.empty() || st.top() != couple[i])  //  如果stack 为空或者stack的顶部与当前不是夫妇，则将其一如stack中 
        st.push(i) ;
        else
        st.pop() ;  // 若为一对，则就将顶部弹出 
    } 
    return st.empty() ;
}                                 
