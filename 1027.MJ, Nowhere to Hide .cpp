// Problem#: 1027
// Submission#: 4598161
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 16718
// Submission#: 4250063
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
struct majia   //把找到的主要帐号和马甲帐号存放在结构体中
{
          string id1,id2;
};
bool cmp(const majia& mj1,const majia& mj2)
{
     return mj1.id1<mj2.id1;    //进行字符串比较
}
 
int main()
{
    int i,j,k,n;
    majia mj[11];
    string id[21],ip[21];
    while(cin>>n && n)
    {
        for(i=0;i<n;i++)
            cin>>id[i]>>ip[i]; //输入ID 和 IP 
        k=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
               if(ip[j]==ip[i]) // 如果两个ID的Ip相同，则将其放入同个结构体中 
               {
                   mj[k].id1=id[j];
                   mj[k++].id2=id[i];
                   break;
               }
            }
        }
        sort(mj,mj+k,cmp);  // 进行排序 
        for(i=0;i<k;i++)
            cout<<mj[i].id2<<" is the MaJia of "<<mj[i].id1<<endl;
        cout<<endl;
    }
    return 0;
}                                 
