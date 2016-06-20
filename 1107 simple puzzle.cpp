// Problem#: 1107
// Submission#: 4722342
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// 1107.cpp
#include <iostream>
#include <memory.h>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
string numbers[20];
int counter, sum, len;
struct Node{
    int index, digit;
};
Node digits[20]; // �����ÿ������������λ�ü�ֵ
vector<int> ans[100];
int ans_counter;
bool vis[20], vis2[20]; // vis����ĳ���Ƿ���������֣� vis2����ĳ�����Ƿ��Ѿ�������
void cal()
{
    int total = 0;
    vector<int> v;
    bool valid = true;
    for (int i = 0; i < counter; i++)
    {
        int temp = 0;
        // �����ж���λ����Ϊ0��
        //��Ȼ��֤����ӵ�����Ϊ��һ����ʱ��Ϊ0��������Ĳ�������������0��Ϊ0�������ֻ����0��ǰ�����ϲ�Ϊ0�����֣�
        if (numbers[i][0] == '0' && digits[i].index > 0) 
        {
            valid = false;
            break;
        }
        // ���㵱ǰ��i������ֵ
        for (int j = 0; j < digits[i].index; j++)
        {
            temp *= 10;
            temp += (int) (numbers[i][j] - '0');
        }
        temp *= 10;
        temp += digits[i].digit;
        for (int j = digits[i].index; j < len; j++)
        {
            temp *= 10;
            temp += (int) (numbers[i][j] - '0');
        }
        v.push_back(temp);
        total += temp;
    }
    if (total == sum && valid)
    {
        ans[ans_counter ++] = v;
    }
}
void dfs(int k)
{
    if (k == counter) // �Ѿ�������n����
    {
        cal();
        return;
    }
    for (int i = 0; i <= len; i++)
    {
        if (vis[i]) // �жϸ����Ƿ��Ѿ���������
            continue;
        vis[i] = true;
        for (int j = 0; j <= 9; j++)
        {
            if (i == 0 && j == 0) // ��λ����Ϊ0
              continue;
            if (vis2[j]) // �жϸ������Ƿ����� 
                continue;
            else{
                digits[k].index = i;
                digits[k].digit = j;
                vis2[j] = true;
                dfs(k + 1);
                vis2[j] = false;
            }
        }
        vis[i] = false;
    }
}
bool cmp(vector<int> a, vector<int> b)
{
    for (int i = 0; i < counter; i ++)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return true;
}
int main()
{
    int test;
    while (scanf ("%d", &test) && test != 0)
    {
        char ch;
        getchar();
        string num = ""; 
        counter = 0;
        ans_counter = 0;
        memset(vis, false, sizeof(vis));
        memset(vis2, false, sizeof(vis2));
        memset(ans, 0, sizeof(ans));
        memset(digits, 0, sizeof(digits));
        // �����������ݣ���n����������numbers������
        do{
            ch = getchar();
            if (ch == ' ')
            {
                numbers[counter++] = num;
                num = "";
            }
            else if (ch != '\n'){
                num += ch;
            }
        } while (ch != '\n');
        // �����������counterֵ��Ϊ��Ŀ�е�n
        len = numbers[0].size(); // len�ǲ��������ĳ��ȣ�����k - 1
        sum = 0; // ��������n�����ܺ�
        for (int i = 0; i < num.size(); i++)
        {
            sum *= 10;
            sum += (int) (num[i] - '0');
        }
        dfs(0); // ö��״̬
        sort(ans, ans + ans_counter, cmp); // �Խ����������
        if (ans_counter == 0)
            cout << test << ' ' << 0 << endl;
        else{
            // ע�������ʽ
            for (int i = 0; i < ans_counter; i++)
            {
                cout << test;
                for (int j = 0; j < counter; j++)
                    cout << ' ' << ans[i][j];
                cout << endl;
            }
        }
    }
    return 0;
}                                 
