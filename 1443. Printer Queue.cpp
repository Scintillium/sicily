// Problem#: 1443
// Submission#: 4655868
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1443
// Submission#: 3016334
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <iterator>
using namespace std;

struct elem
{
    int index;
    int num;
};

bool findBig(list<elem>& ls)
{
    list<elem>::iterator it = ls.begin();
    int first = (*it).num;
    for ( ; it != ls.end(); it++)
    {
        if ((*it).num > first)
            return true;
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        list<elem> q;
        list<elem>::iterator it;
        for (int i = 0; i < n; i++)
        {
            elem temp;
            cin >> temp.num;
            temp.index = i;
            q.push_back(temp);
        }

        int res = 0;
        it = q.begin();
        int count = 0;
        while (res == 0)
        {
            if (findBig(q)) // ?????????, ?????????????
            {
                it = q.begin();
                elem temp = *it;
                q.pop_front();
                q.push_back(temp);
                it = q.begin();
            }
            else if( (*it).index == m )// ?????????, ???????count??res,????
            {
                res = count+1;
                break;
            }
            else // ???????????,?????count??
            {
                q.pop_front();
                count++;
                it = q.begin();
            }
        }
        cout << res << endl;
    }
    return 0;
}                                 
