// Problem#: 1024
// Submission#: 1137874
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Road {
    int to;
    int distance;
    Road( int t, int d ) { to = t; distance = d; }
};

int longest;
bool visited[ 10001 ];
vector<Road> road[ 10001 ];

void DFS( int n, int dist ) {
    bool deeper = false;
    for ( vector<Road>::iterator it = road[ n ].begin(); it != road[ n ].end(); it++ ) {
        if ( !visited[ it->to ] ) {
            visited[ it->to ] = true;
            deeper = true;
            DFS( it->to, dist + it->distance );
        }
    }
    road[ n ].clear();
    if ( !deeper && dist > longest )
        longest = dist;
}


int main()
{
    int N, K;
    int X, Y, D;

    while ( scanf( "%d%d", &N, &K ) != EOF ) {
        for ( int i = 1; i < N; i++ ) {
            scanf( "%d%d%d", &X, &Y, &D );
            road[ X ].push_back( Road( Y, D ) );
            road[ Y ].push_back( Road( X, D ) );
        }

        longest = 0;
        memset( visited, false, sizeof( visited ) );
        visited[ K ] = true;
        for ( vector<Road>::iterator it = road[ K ].begin(); it != road[ K ].end(); it++ ) {
            if ( !visited[ it->to ] ) {
                visited[ it->to ] = true;
                DFS( it->to, it->distance );
            }
        }
        road[ K ].clear();
        printf( "%d\n", longest );
    }

    return 0;

}                                 
