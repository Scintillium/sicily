#include <iostream>
#include <cstring>
using namespace std;
int q,m,dest;
int a[6];
bool used[6];
void dfs(int k)
{
    for (int i=1; i<=5; i++)
        if (!used[i] && a[i]<=dest && dest-a[i]<q)
        {
            q=dest-a[i];
            m=a[i];
        }
    for (int i=1; i<=5; i++)
        if (!used[i])
            for (int j=i+1; j<=5; j++)
                if (!used[j])
                {
                    int tmp=a[i];
                    a[i]=a[i]+a[j];
                    used[j]=true;
                    dfs(k-1);
                    used[j]=false;
                    a[i]=tmp;
                    a[i]=a[i]-a[j];
                    used[j]=true;
                    dfs(k-1);
                    used[j]=false;
                    a[i]=tmp;
                    a[i]=a[j]-a[i];
                    used[j]=true;
                    dfs(k-1);
                    used[j]=false;
                    a[i]=tmp;
                    a[i]=a[i]*a[j];
                    used[j]=true;
                    if (k!=2 ||(k==2 && tmp>=0 && tmp<=100000)) dfs(k-1);
                    used[j]=false;
                    a[i]=tmp;
                    if (a[j]!=0 && a[i]%a[j]==0)
                    {
                        a[i]=a[i]/a[j];
                        used[j]=true;
                        dfs(k-1);
                        used[j]=false;
                        a[i]=tmp;
                    }
                    if (a[i]!=0 && a[j]%a[i]==0)
                    {
                        a[i]=a[j]/a[i];
                        used[j]=true;
                        dfs(k-1);
                        used[j]=false;
                        a[i]=tmp;
                    }
                }
}

int main()
{
    int cases;
    cin>>cases;
    for (int o=0; o<cases; o++)
    {
        for (int i=1; i<=5; i++)
            cin>>a[i];
        cin>>dest;
        memset(used,0,sizeof(used));
        q=1000;
        dfs(5);
        cout<<m<<endl;
    }
    return 0;
}

