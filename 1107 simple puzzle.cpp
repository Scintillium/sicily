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
Node digits[20]; // 保存给每个数填充的数的位置及值
vector<int> ans[100];
int ans_counter;
bool vis[20], vis2[20]; // vis保存某列是否已填充数字， vis2保存某数字是否已经被填了
void cal()
{
    int total = 0;
    vector<int> v;
    bool valid = true;
    for (int i = 0; i < counter; i++)
    {
        int temp = 0;
        // 这里判断首位不是为0，
        //虽然保证了添加的数字为第一个的时候不为0，但输入的不完整的数可能0（为0的情况就只能在0的前面填上不为0的数字）
        if (numbers[i][0] == '0' && digits[i].index > 0) 
        {
            valid = false;
            break;
        }
        // 计算当前第i个数的值
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
    if (k == counter) // 已经填完了n个数
    {
        cal();
        return;
    }
    for (int i = 0; i <= len; i++)
    {
        if (vis[i]) // 判断该列是否已经填了数字
            continue;
        vis[i] = true;
        for (int j = 0; j <= 9; j++)
        {
            if (i == 0 && j == 0) // 首位不能为0
              continue;
            if (vis2[j]) // 判断该数字是否被填了 
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
        // 处理输入数据，将n个数保存在numbers数组里
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
        // 处理完输入后，counter值即为题目中的n
        len = numbers[0].size(); // len是不完整数的长度，即是k - 1
        sum = 0; // 用来保存n个数总和
        for (int i = 0; i < num.size(); i++)
        {
            sum *= 10;
            sum += (int) (num[i] - '0');
        }
        dfs(0); // 枚举状态
        sort(ans, ans + ans_counter, cmp); // 对结果进行排序
        if (ans_counter == 0)
            cout << test << ' ' << 0 << endl;
        else{
            // 注意输出格式
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
