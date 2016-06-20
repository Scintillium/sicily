#include <stdio.h>
#include <math.h>
long long extend_gcd(long long a,long long b,long long& x,long long& y) {
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    long long d=extend_gcd(b,a%b,x,y);
    long long temp=x;
    x=y;
    y=temp-a/b*y;
    return d;
}
bool ok(long long a,long long b,long long c,long long& x,long long& y) {
    long long d=extend_gcd(a,b,x,y);
    if(c%d) 
        return true;

    long long k=c/d;
    x*=k;
    y*=k;
    return false;
}
int main() {
    long long x,y;
    long long cA,cB,pA,pB;
    long long n;
    long long u1,l1;
    long long d;
    int case_ctr=1;
    
    scanf("%lld", &n);
    while (n!=0) {
        scanf("%lld%lld", &cA, &pA);
        scanf("%lld%lld", &cB, &pB);
        if (ok(pA, pB, n, x, y))
            printf("Data set %d: cannot be flown\n", case_ctr++);
        else {
            d=extend_gcd(pA, pB, l1, u1);
            u1=floor((double)y/(pA/d));        
            l1=ceil((double)-x/(pB/d));
            if (cA*pB<=cB*pA) 
                printf("Data set %d: %lld aircraft A, %lld aircraft B\n", case_ctr++, x+pB/d*u1, y-pA/d*u1);
            else
                printf("Data set %d: %lld aircraft A, %lld aircraft B\n", case_ctr++, x+pB/d*l1, y-pA/d*l1);
        }
        
        scanf("%lld",&n);
    }
    return 0;
}                         
