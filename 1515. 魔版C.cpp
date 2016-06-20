#include <cstdio>
#include <string>
#include <queue>
#include <map>
using namespace std;

void changeA( const string &s, string &t );
void changeB( const string &s, string &t );
void changeC( const string &s, string &t );

int main()
{
    int M;
    string now, target;
    int i, j;

    map<string, string> m;
    target = "12345678";
    m[ target ].clear();
    queue<string> q;
    q.push( target );
    while ( !q.empty() ) {
        now = q.front();
        changeA( now, target ); 
        if ( m.find( target ) == m.end() ) {
            m[ target ] = m[ now ] + 'A';
            q.push( target );
        }
        changeB( now, target );
        if ( m.find( target ) == m.end() ) {
            m[ target ] = m[ now ] + 'B';
            q.push( target );
        }
        changeC( now, target );
        if ( m.find( target ) == m.end() ) {
            m[ target ] = m[ now ] + 'C';
            q.push( target );
        }
        q.pop();
    }

    while ( scanf( "%d", &M ) && M != -1 ) {
        for ( i = 0; i < 8; i++ ) {
            scanf( "%d", &j );
            target[ i ] = '0' + j;
        }
        if ( m.find( target ) == m.end() || m[ target ].size() > M )
            printf( "-1\n" );
        else
            printf( "%d %s\n", m[ target ].size(), m[ target ].c_str() );
    }
    
    return 0;

}


void changeA( const string &s, string &t ) {
    t[ 0 ] = s[ 2 ];
    t[ 1 ] = s[ 3 ];
    t[ 2 ] = s[ 0 ];
    t[ 3 ] = s[ 1 ];
    t[ 4 ] = s[ 6 ];
    t[ 5 ] = s[ 7 ];
    t[ 6 ] = s[ 4 ];
    t[ 7 ] = s[ 5 ];
}

void changeB( const string &s, string &t ) {
    t[ 0 ] = s[ 1 ];
    t[ 1 ] = s[ 2 ];
    t[ 2 ] = s[ 3 ];
    t[ 3 ] = s[ 0 ];
    t[ 4 ] = s[ 5 ];
    t[ 5 ] = s[ 6 ];
    t[ 6 ] = s[ 7 ];
    t[ 7 ] = s[ 4 ];
}

void changeC( const string &s, string &t ) {
    t[ 0 ] = s[ 0 ];
    t[ 1 ] = s[ 2 ];
    t[ 2 ] = s[ 6 ];
    t[ 3 ] = s[ 3 ];
    t[ 4 ] = s[ 4 ];
    t[ 5 ] = s[ 1 ];
    t[ 6 ] = s[ 5 ];
    t[ 7 ] = s[ 7 ];
}                                 
