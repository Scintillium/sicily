#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
#include <stack>
using namespace std;

struct Node{
    char ch;
    int pos;
    Node(char c, int p): ch(c), pos(p){}
};
bool cmp(Node a, Node b){
    return a.ch < b.ch;
}
int main(){
    string key, str;
    while(cin >> key && key != "THEEND"){
        cin >> str;
        vector<Node> v;
        for(int i = 0; i < key.size(); i++)
            v.push_back(Node(key[i], i));
        sort(v.begin(), v.end(), cmp);

        char mat[105][15];
        int row = str.size() / key.size();
        int cnt = 0;
        for(int t = 0; t < v.size(); t++)
            for(int j = 0; j < row; j++)
                mat[j][v[t].pos] = str[cnt++];

        for(int i = 0; i < row; i++)
            for(int j = 0; j < key.size(); j++)
                cout << mat[i][j];
        cout << endl;
    }
}                         
