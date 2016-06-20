#include <iostream>
#include <cstdio>
using namespace std;

int countEven(int num, long long L) {                    
    long long result = num;

    while (num) {
        result = (result << 1) | (num & 1);
        num >>= 1;  
    }
    return result && result <= L ? 1 : 0;
}

int countOdd(int num, long long L) {             
    long long a = num, b = num;
    int hold = 0, bits = 0;

    while (num) {
        hold = (hold << 1) | (num & 1);
        num >>= 1;
        bits ++;
    }
    a = (a << (bits + 1)) | hold;
    b = (((b << 1) | 1) << bits) | hold;
    return (a && a <= L ? 1 : 0) + (b && b <= L ? 1 : 0);
}

int main() {
  
    long long L ,ans = 0 ;
    scanf("%lld", &L);

    for (int i = 0; i < (1 << 16); i ++) {
        ans += countEven(i, L);
        if (i < (1 << 15)) ans += countOdd(i, L);
    }
    printf("%lld\n", ans);
  
    return 0;
}
