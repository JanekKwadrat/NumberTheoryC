#include <iostream>
#include <ctime>
#include "ntlib.h"

void test();
void test_fib();
void gen_fib();

int main() {

    test_fib();
    test();
    
    return 0;
}

void gen_fib() {
    const u64 Q = 1e9 + 7;
    std::cout << "{\n";
    for(u64 i = 0; i < 8; ++i) {
        std::cout << "    {";
        for(u64 x = 0; x < 256; ++x) {
            u64 itr = x << (8 * i);
            std::cout << "{" << fib(itr - 1, Q) << ", " << fib(itr, Q) << ", " << fib(itr + 1, Q) << "}, ";
        }
        std::cout << "},\n";
    }
    std::cout << "}\n";
}

void test_fib() {
    const u64 mod = 1e9 + 7;
    i32 n = 10'000'000;
    u64 f0 = 0, f1 = 1, f2;
    bool fib_ok = true;
    bool fib1_ok = true;
    bool fibQ_ok = true;
    for(i32 i = 0; i < n; ++i) {
        if(f0 != fib(i, mod)) fib_ok = false;
        if(f0 != fib1(i, mod)) fib1_ok = false;
        if(f0 != fibQ(i)) fibQ_ok = false;
        
        f2 = f0 + f1;
        f0 = f1 % mod;
        f1 = f2 % mod;
    }
    std::cout << "fib " << (fib_ok ? "is correct" : "was wrong") << " on the first " << n << " numbers\n";
    std::cout << "fib1 " << (fib1_ok ? "is correct" : "was wrong") << " on the first " << n << " numbers\n";
    std::cout << "fibQ " << (fibQ_ok ? "is correct" : "was wrong") << " on the first " << n << " numbers\n";
}

void test() {
    i32 seed = 2137;
    i32 cases = 100'000'000;
    clock_t beg, end;

    seeder(seed);
    beg = clock();
    for(i32 q = cases; q--;) {
        u64 k = rand64() % (u64)1e12;
        u64 fib_ans = fibQ(k);
    }
    end = clock();

    std::cout << "fibQ finsished " << cases << " cases in " << (double)(end - beg) / CLOCKS_PER_SEC << " s\n";
    std::cout << "fibQ computes one case in " << (double)(end - beg) / CLOCKS_PER_SEC / (double)cases << " s on average\n";
    
    seeder(seed);
    beg = clock();
    for(i32 q = cases; q--;) {
        u64 k = rand64() % (u64)1e12;
        u64 M = rand64() % (u64)3e9;
        u64 fib_ans = fib(k, M);
    }
    end = clock();

    std::cout << "fib finsished " << cases << " cases in " << (double)(end - beg) / CLOCKS_PER_SEC << " s\n";
    std::cout << "fib computes one case in " << (double)(end - beg) / CLOCKS_PER_SEC / (double)cases << " s on average\n";

    seeder(seed);
    beg = clock();
    for(i32 q = cases; q--;) {
        u64 k = rand64() % (u64)1e12;
        u64 M = rand64() % (u64)3e9;
        u64 fib_ans = fib1(k, M);
    }
    end = clock();

    std::cout << "fib1 finsished " << cases << " cases in " << (double)(end - beg) / CLOCKS_PER_SEC << " s\n";
    std::cout << "fib1 computes one case in " << (double)(end - beg) / CLOCKS_PER_SEC / (double)cases << " s on average\n";
    
    seeder(seed);
    beg = clock();
    for(i32 q = cases; q--;) {
        u64 k = rand64() % (u64)1e12;
        u64 M = rand64() % (u64)3e9;
    }
    end = clock();

    std::cout << "rng finsished " << cases << " cases in " << (double)(end - beg) / CLOCKS_PER_SEC << " s\n";
    std::cout << "rng randomizes one case in " << (double)(end - beg) / CLOCKS_PER_SEC / (double)cases << " s on average\n";
}