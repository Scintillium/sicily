// knapsackSa.cpp : 定义控制台应用程序的入口点。
//
//#include "stdafx.h"
#include "ctime"
#include "windows.h"
#include "stdio.h"
#include "cmath"
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
void knapsackSa(int w[],int c[],int n,int M) //n件物品，其重量和价值分别为w[i]和c[i]，寻找将其装入容量为M的背包中物品的最大价值
{	int i,j,df,dm;
 int *x=new int[n]; //定义解空间
 for(i=0;i<n;i++) //初始化解 为0
 {
  x[i]=0;
 }
 int f=0,m=0;
 for(i=0;i<n;i++)
 {
  f=f+c[i]*x[i]; //初始化总价值
  m=m+w[i]*x[i];	 //初始化总重量
 }
 float t0=500; //控制参数t的初值
 float t=t0;
 float a=0.95f; //衰减函数的系数
 float e=0.00001f;
 int L=100*n; // Mapkob 链长
 while(t>e)	 //停止准则
 {
  srand((unsigned)time(NULL));//初始化随机函数种子，srand((unsigned)time(NULL));是拿系统时间作为种子，由于时间是变化的，种子变化，可以产生不相同的随机数。
  for(int k=0;k<L;k++)
  {
   i=rand()%n; //随机选取第i件物品
   if(x[i]==0)	//若i不在背包中
   {
    if(m+w[i]<=M)	//且加入总重量后不超过容量M,则直接放入背包中
    {
     x[i]=1;
     f=f+c[i];
     m=m+w[i];
    }
    else
    {
     j=rand()%n;	//随机取出物品j
     while(x[j]==0){j=rand()%n;} //直到x[j]为1
      df=c[i]-c[j];
      dm=w[i]-w[j];
     if(m+dm<=M)	//加入总重量后不超过容量M
      if(df>0||(exp(df/t)>(double)(rand()/(double)RAND_MAX)))	 //价值差大于0或以exp(df/T)的接受概率接受新解
      {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
       x[i]=1;
       x[j]=0;
       f=f+df;
       m=m+dm;
      }
    }
   }
   else
   {
     j=rand()%n;
     while(x[j]==1) { j=rand()%n;}
     df=c[j]-c[i];
     dm=w[j]-w[i];
     if(m+dm<=M)
      if(df>0||(exp(df/t)>(double)(rand()/(double)RAND_MAX)))	 //价值差大于0或以exp(df/T)的接受概率接受新解
      {
       x[i]=0;
       x[j]=1;
       f=f+df;
       m=m+dm;
      }
   }
  }
   t=t*a; //衰减函数
 }
   cout<<"该0/1背包问题的最优解为： ";
         for(i=0;i<=n-1;i++) cout<<x[i]<<" ";
         cout<<endl<<"最大总价值为："<<f<<endl;
}
int _tmain()
{	int n,M;
 void knapsackSa(int w[],int c[],int n,int M);//n件物品，其重量和价值分别为w[i]和c[i]，寻找将其装入容量为M的背包中物品的最大价值
 cout<<"请输入物品件数n:"<<endl;
 cin>>n;
 cout<<"请输入背包容量M:"<<endl;
 cin>>M;
 int *w=new int[n];
 cout<<"请依次输入物品重量:"<<endl;
 for(int i=0;i<n;i++)
 {
  cin>>w[i];
 }
 int *c=new int[n];
 cout<<"请依次输入物品价值:"<<endl;
 for(int i=0;i<n;i++)
 {
  cin>>c[i];
 }
 knapsackSa(w,c,n,M);
 system("pause");
 return 0;
}
