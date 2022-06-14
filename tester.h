#include <stdio.h>
#include <time.h>
#include "ntlib.h"

void announce(int id, int g, double t, const char* s) {
    if(id == -1) { printf(" ( %s )\n", s); return; }
    printf("The test \e[0;33m#%03d\e[0m went ", id);
    if(g) printf("\e[0;32m WELL\e[0m ");
    else printf("\e[0;31mWRONG\e[0m ");
    printf("taking \e[35m%5.3fs\e[0m ", t);
    printf("[ %s ]\n", s);
    // The test #000 went  WELL taking 0.000s [ function announce test ]
}

double clockme() {
    static clock_t t;
    clock_t t1 = t;
    t = clock();
    return (double)(t - t1) / CLOCKS_PER_SEC;
}

void dotests() {
    announce(-1, 0, .0, "doing tests");
    announce(0, 1, .0, "function announce test");
    static const double nan = .0/.0;
    char* str;

    /*announce(-1, 0, .0, "fibonacci");
    {
        const int n = 3'000'000;
        const u64 mod = 1e9 + 7; //should not be changed
        u64 f0 = 0, f1 = 1, f2;
        int fib_ok = 1;
        int fib1_ok = 1;
        int fibQ_ok = 1;
        for(int i = 0; i < n; ++i) {
            if(f0 != fib(i, mod)) fib_ok = 0;
            if(f0 != fib1(i, mod)) fib1_ok = 0;
            if(f0 != fibQ(i)) fibQ_ok = 0;
            f2 = f0 + f1;
            f0 = f1 % mod;
            f1 = f2 % mod;
        }
        announce(1, fib_ok, nan, "fib with numbers 0..3'000'000");
        announce(2, fib1_ok, nan, "fib1 with numbers 0..3'000'000");
        announce(3, fibQ_ok, nan, "fibQ with numbers 0..3'000'000");
    }*/

    announce(-1, 0, .0, "primes");
    {   
        int ok;
        clockme();
        ok = is_prime(1'000'000'007) && is_prime(7'385'305'309'546'123);
        announce(5, ok, clockme(), "is_prime with two big primes");
        
        const int n = 3'000'000;
        int * arr = (int*)calloc(n, sizeof(int));
        arr[0] = 1, arr[1] = 1;
        for(int i = 2; i * i < n; ++i) {
            if(arr[i]) continue;
            for(int j = 2 * i; j < n; j += i) arr[j] = 1;
        }
        ok = 1;
        clockme();
        for(int i = 0; i < n; ++i) {
            if(!arr[i] != is_prime((u64)i)) {
                printf("problem with %d\n", i);
                ok = 0;
                break;
            }
        }
        announce(4, ok, clockme(), "is_prime with numbers 0..3'000'000");
    }

    announce(-1, 0, .0, "complete");
}