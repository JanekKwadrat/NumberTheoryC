/*
 * TO DO
 * reversing mod sth
 * checking whether prime
 * computing fibonacci numbers
 * getting number of coprimes below some value
 * 2D matrices computations
 * eratosthenes sieve and factorization
 */

#include "rustlike.h"

u64 gcd(u64, u64);

u64 reverse(u64, u64);

u64 pow(u64, u64, u64);
u64 fib(u64, u64);

u64 sqrt(u64);

void mov_matrix2d(u64[2][2], u64[2][2]);
void add_matrix2d(u64[2][2], u64[2][2]);
void mul_matrix2d(u64[2][2], u64[2][2]);
void mod_matrix2d(u64[2][2], u64);

u8 fact(u64, u64*, u8*);
void primality(u32, u8*);