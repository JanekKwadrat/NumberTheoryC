#include "ntlib.h"

u64 gcd(u64 a, u64 b) {
    while(1) {
        if(b == 0) return a;
        a %= b;
        if(a == 0) return b;
        b %= a;
    }
}

u64 reverse(u64 a, u64 M) {
    if(!a) return 0;
    if(!M) return a == 1;
    return ((M * (a - reverse(M % a, a)) + 1) / a) % M;
}

u64 pow(u64 a, u64 k, u64 M) {
    u64 ans = 1;
    while(k) {
        if(k % 2) ans =  ans * a % M;
        a = a * a % M;
        k /= 2;
    }
    return ans;
}

u64 fib(u64 k, u64 M) {
    u64 ans[2][2] = {{1, 0}, {0, 1}};
    u64 mat[2][2] = {{1, 1}, {1, 0}};
    while(k) {
        if(k % 2) {
            mul_matrix2d(ans, mat);
            mod_matrix2d(ans, M);
        }
        mul_matrix2d(mat, mat);
        mod_matrix2d(mat, M);
        k /= 2;
    }
    return ans[1][0];
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

void mov_matrix2d(u64 A[2][2], u64 B[2][2]) {
    A[0][0] = B[0][0];
    A[0][1] = B[0][1];
    A[1][0] = B[1][0];
    A[1][1] = B[1][1];
}

void add_matrix2d(u64 A[2][2], u64 B[2][2]) {
    A[0][0] += B[0][0];
    A[0][1] += B[0][1];
    A[1][0] += B[1][0];
    A[1][1] += B[1][1];
}

void mul_matrix2d(u64 A[2][2], u64 B[2][2]) {
    u64 Z[2][2];
    Z[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    Z[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    Z[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    Z[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    mov_matrix2d(A, Z);
}

void mod_matrix2d(u64 A[2][2], u64 M) {
    A[0][0] %= M;
    A[0][1] %= M;
    A[1][0] %= M;
    A[1][1] %= M;
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

void primality(u32 n, u8* array) {
    array[0] = 0;
    array[1] = 0;
    for(u32 i = 2; i < n; ++i) array[i] = 1;
    for(u32 i = 2; i * i <= n; ++i) {
        if(!array[i]) continue;
        for(u32 j = 2 * i; j < n; j += i) array[j] = 0;
    }
}

