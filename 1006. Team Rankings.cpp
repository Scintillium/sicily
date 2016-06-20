// Problem#: 1006
// Submission#: 4655815
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n,len = 5;
    string str[101];
    int pos[6]; 
    while(cin>>n,n)
    {
        string ans;
        for(int i = 0;i < n;++i)
            cin>>str[i];
        char next[] = "ABCDE";int min = 1000;
        do
        {
            for(int i = 0;i < len;++i)
                pos[next[i] - 'A'] = i;
            int value = 0;
            for(int i = 0;i < n;++i)
            {
                for(int j = 0;j < len;++j)
                    for(int l =j + 1;l < len;++l)
                        if(pos[str[i][j] - 'A'] > pos[str[i][l] - 'A']) value++; 
            }
            if(value < min)
            {
                min = value;
                ans = next;
            }
        }while(next_permutation(next,next + 5));
        cout<<ans<<" is the median ranking with value "<<min<<"."<<endl;
    }
    return 0;
}                                 
