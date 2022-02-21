#include "ntlib.h"

u64 gcd(u64 a, u64 b) {
    while(1) {
        if(b == 0) return a;
        a %= b;
        if(a == 0) return b;
        b %= a;
    }
}

u64 pow(u64 a, u64 k, u64 M) {
    u64 ans = 1ULL;
    while(k) {
        if(k % 2) ans =  ans * a % M;
        a = a * a % M;
        k /= 2;
    }
    return ans;
}

u8 fact(u64 n, u64* primes, u8* exps) {
    u8 top = 0;
    for(u64 d = 2; d * d <= n; ++d) {
        if(n % d) continue;
        primes[top] = d;
        exps[top] = 0;
        while(n % d == 0) {
            ++exps[top];
            n /= d;
        }
        ++top;
    }
    if(n > 1) {
        primes[top] = n;
        primes[top] = 1;
        ++top;
    }
    return top;
}

u64 sqrt(u64 n) {
    u64 p = 0, q = u32_max;
    while(q - p > 1) {
        u64 mid = (p + q) / 2;
        if(mid * mid > n) q = mid;
        else p = mid;
    }
    return p;
}

void eratosthenes(u32 n, b2* array) {
    array[0] = no;
    array[1] = no;
    for(u32 i = 2; i < n; ++i) array[i] = yes;
    for(u32 i = 2; i * i <= n; ++i) {
        if(!array[i]) continue;
        for(u32 j = 2 * i; j < n; j += i) array[j] = no;
    }
}

