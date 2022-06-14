#include <stdio.h>
#include "ntlib.h"
#include "tester.h"

int main() {

    dotests();

    return 0;
}

/*
#include <iostream>

void test_fib_speed();
void gen_fib();
void test_dio();

void test_dio() {
    i64 a, b, x, y;
    std::cout << "Please provide numbers a and b > ";
    std::cin >> a >> b;
    std::cout << "Solving ax + by = gcd(a, b) ...\n";
    diophantine(a, b, &x, &y);
    std::cout << "The numbers x and y < " << x << " " << y << "\n";
}

void gen_fib() {
    const u64 Q = 1e9 + 7;
    std::cout << "{\n";
    for(u64 i = 0; i < 8; ++i) {
        std::cout << "    {";
        for(u64 x = 0; x < 256; ++x) {
            u64 itr = x << (8 * i);
            std::cout << "{" << fib(itr - 1, Q) << "," << fib(itr, Q) << "," << fib(itr + 1, Q) << "}";
            if(x != 255) std::cout << ",";
        }
        if(i != 7) std::cout << "},\n";
    }
    std::cout << "}\n";
}

void test_fib_speed() {
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
}*/