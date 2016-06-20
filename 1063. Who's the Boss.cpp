// Problem#: 1063
// Submission#: 4655886
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1063
// Submission#: 1042450
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>
#include <algorithm>
using namespace std;

struct Employee {
    int ID, salary, height;
    int boss;
    int count;
};
bool cmp1( const Employee& e1, const Employee& e2 ) { return e1.salary < e2.salary; }
bool cmp2( const Employee& e1, const Employee& e2 ) { return e1.ID < e2.ID; }

int main()
{
    int n, m, q;
    int i, j;
    int bot, top;
    int id;
    Employee data[ 30000 ];

    scanf( "%d", &n );
    while ( n-- ) {
        scanf( "%d%d", &m, &q );

        for ( i = 0; i < m; i++ ) {
            scanf( "%d%d%d", &data[ i ].ID, &data[ i ].salary, &data[ i ].height );
            data[ i ].boss = 0;
            data[ i ].count = 0;
        }
        sort( data, data + m, cmp1 );

        for ( i = 0; i < m; i++ ) {
            for ( j = i + 1; j < m; j++ ) {
                if ( data[ j ].height >= data[ i ].height ) {
                    data[ i ].boss = data[ j ].ID;
                    data[ j ].count += data[ i ].count + 1;
                    break;
                }
            }
        }
        sort( data, data + m, cmp2 );

        for ( i = 0; i < q; i++ ) {
            scanf( "%d", &id );
            bot = 0;
            top = m - 1;
            while ( bot <= top ) {
                j = ( bot + top ) / 2;
                if ( data[ j ].ID == id )
                    break;
                else if ( data[ j ].ID < id )
                    bot = j + 1;
                else
                    top = j - 1;
            }
            printf( "%d %d\n", data[ j ].boss, data[ j ].count );
        }
    }
    
    return 0;

}                                 
