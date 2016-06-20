// Problem#: 1215
// Submission#: 4722339
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int n, m;

//状态
struct state
{
    int P_x, P_y, H_x, H_y;
    int step;
    bool ismeet() {
        return P_x == H_x && P_y == H_y;
    }//判断两个是否到达同一个
    bool isvalid() {
        return P_x > 0 && P_x <= n &&  P_y > 0 && P_y <= m
        && H_x > 0 && H_x <= n && H_y > 0 && H_y <= m ;
    }//判断坐标是否合法
    bool iscollision(state s)
    {
        return P_x == s.H_x && P_y == s.H_y && H_x == s.P_x && H_y == s.P_y;
    }//检测两个人是否相遇
    state(int P_x, int P_y, int H_x, int H_y) {
        this->H_x = H_x; this->H_y = H_y; this->P_x = P_x; this->P_y = P_y; step = 0;
    }
    state() {
        step = 0;
    }
};

enum direction{N, S, W, E};

//N,S,W,E移动方向
int mov[4][2] = {{-1, 0},{1, 0}, {0, -1}, {0, 1}};
int match[4];
char maze[21][21];
bool isvisit[21][21][21][21];

int P_x, P_y, H_x, H_y;

void bfs();

int main()
{
    char c;
    while (cin >> n >> m)
    {
        memset(isvisit, false, sizeof(isvisit));

        for (int i = 1; i <= n; i++)    
            for (int j = 1; j <= m; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 'P')
                {
                    P_x = i;
                    P_y = j;
                    maze[i][j] = '.';
                }
                if (maze[i][j] == 'H')
                {
                    H_x = i;
                    H_y = j;
                    maze[i][j] = '.';
                }
            }

            //匹配方向
            for (int i = 0; i < 4; i++)
            {
                cin >> c;
                switch (c)
                {
                case 'N':
                    match[i] = N;
                    break;
                case 'S':
                    match[i] = S;
                    break;
                case 'W':
                    match[i] = W;
                    break;
                case 'E':
                    match[i] = E;
                    break;
                }
            }
            bfs();
    }
    return 0;
}

void bfs()
{
    queue <state> Q;
    Q.push(state(P_x, P_y, H_x, H_y));

    state tmp, hold;

    while (!Q.empty())
    {
        tmp = Q.front();
        Q.pop();
        if (tmp.step > 255)
        {
            cout << "Impossible" << endl;
            return;
        }
        //从N,S,W,E开始更新状态
        for (int i = 0; i < 4; i++)
        {
            hold.P_x = tmp.P_x + mov[i][0];
            hold.P_y = tmp.P_y + mov[i][1];
            hold.H_x = tmp.H_x + mov[match[i]][0];
            hold.H_y = tmp.H_y + mov[match[i]][1];
            hold.step = tmp.step + 1;
        
            if (hold.isvalid() && 
                maze[hold.H_x][hold.H_y] != '!' && 
                maze[hold.P_x][hold.P_y] == '.' ) //每次把合法的状态放到队列
            {
                if (maze[hold.H_x][hold.H_y] == '#')
                {
                    hold.H_x -= mov[match[i]][0];
                    hold.H_y -= mov[match[i]][1];
                }
                if (!isvisit[hold.P_x][hold.P_y][hold.H_x][hold.H_y])
                {
                    isvisit[hold.P_x][hold.P_y][hold.H_x][hold.H_y] = true;
                    if (hold.ismeet() || tmp.iscollision(hold))
                    {
                        cout << hold.step << endl;
                        return ;
                    }
                    else
                        Q.push(hold);
                }
            }
        }

    }
    cout << "Impossible" << endl;
}                                 
