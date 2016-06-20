// Problem#: 1156
// Submission#: 4655878
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1156
// Submission#: 1172813
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char content;
    int left, right;
};

Node node[ 1001 ];
bool exist[ 1001 ];
bool root[ 1001 ];

void preorder( int n ) {
    if ( n != 0 ) {
        cout << node[ n ].content;
        preorder( node[ n ].left );
        preorder( node[ n ].right );
    }
}

int main()
{
    int n, i;

    while ( cin >> n ) {
        memset( exist, false, sizeof( exist ) );
        memset( root, true, sizeof( root ) );
        while ( n-- ) {
            cin >> i;
            cin >> node[ i ].content >> node[ i ].left >> node[ i ].right;
            exist[ i ] = true;
            root[ node[ i ].left ] = false;
            root[ node[ i ].right ] = false;
        }

        for ( i = 1; i <= 1000; i++ ) {
            if ( exist[ i ] && root[ i ] )
                break;
        }
        preorder( i );
        cout << endl;
    }

    return 0;

}                                 
