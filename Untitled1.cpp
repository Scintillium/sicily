// knapsackSa.cpp : �������̨Ӧ�ó������ڵ㡣
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
void knapsackSa(int w[],int c[],int n,int M) //n����Ʒ���������ͼ�ֵ�ֱ�Ϊw[i]��c[i]��Ѱ�ҽ���װ������ΪM�ı�������Ʒ������ֵ
{	int i,j,df,dm;
 int *x=new int[n]; //�����ռ�
 for(i=0;i<n;i++) //��ʼ���� Ϊ0
 {
  x[i]=0;
 }
 int f=0,m=0;
 for(i=0;i<n;i++)
 {
  f=f+c[i]*x[i]; //��ʼ���ܼ�ֵ
  m=m+w[i]*x[i];	 //��ʼ��������
 }
 float t0=500; //���Ʋ���t�ĳ�ֵ
 float t=t0;
 float a=0.95f; //˥��������ϵ��
 float e=0.00001f;
 int L=100*n; // Mapkob ����
 while(t>e)	 //ֹͣ׼��
 {
  srand((unsigned)time(NULL));//��ʼ������������ӣ�srand((unsigned)time(NULL));����ϵͳʱ����Ϊ���ӣ�����ʱ���Ǳ仯�ģ����ӱ仯�����Բ�������ͬ���������
  for(int k=0;k<L;k++)
  {
   i=rand()%n; //���ѡȡ��i����Ʒ
   if(x[i]==0)	//��i���ڱ�����
   {
    if(m+w[i]<=M)	//�Ҽ����������󲻳�������M,��ֱ�ӷ��뱳����
    {
     x[i]=1;
     f=f+c[i];
     m=m+w[i];
    }
    else
    {
     j=rand()%n;	//���ȡ����Ʒj
     while(x[j]==0){j=rand()%n;} //ֱ��x[j]Ϊ1
      df=c[i]-c[j];
      dm=w[i]-w[j];
     if(m+dm<=M)	//�����������󲻳�������M
      if(df>0||(exp(df/t)>(double)(rand()/(double)RAND_MAX)))	 //��ֵ�����0����exp(df/T)�Ľ��ܸ��ʽ����½�
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
      if(df>0||(exp(df/t)>(double)(rand()/(double)RAND_MAX)))	 //��ֵ�����0����exp(df/T)�Ľ��ܸ��ʽ����½�
      {
       x[i]=0;
       x[j]=1;
       f=f+df;
       m=m+dm;
      }
   }
  }
   t=t*a; //˥������
 }
   cout<<"��0/1������������Ž�Ϊ�� ";
         for(i=0;i<=n-1;i++) cout<<x[i]<<" ";
         cout<<endl<<"����ܼ�ֵΪ��"<<f<<endl;
}
int _tmain()
{	int n,M;
 void knapsackSa(int w[],int c[],int n,int M);//n����Ʒ���������ͼ�ֵ�ֱ�Ϊw[i]��c[i]��Ѱ�ҽ���װ������ΪM�ı�������Ʒ������ֵ
 cout<<"��������Ʒ����n:"<<endl;
 cin>>n;
 cout<<"�����뱳������M:"<<endl;
 cin>>M;
 int *w=new int[n];
 cout<<"������������Ʒ����:"<<endl;
 for(int i=0;i<n;i++)
 {
  cin>>w[i];
 }
 int *c=new int[n];
 cout<<"������������Ʒ��ֵ:"<<endl;
 for(int i=0;i<n;i++)
 {
  cin>>c[i];
 }
 knapsackSa(w,c,n,M);
 system("pause");
 return 0;
}
