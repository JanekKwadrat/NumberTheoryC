 // Jan Zakrzewski - implementacja rozszerzonego algorytmu Euklidesa
typedef long long i64;
i64 diophantine(i64 a, i64 b, i64* x, i64* y) {
    i64 ap = 1, aq = 0;
    i64 bp = 0, bq = 1;
    while(1) {
        if(b == 0) {
            *x = ap, *y = aq;
            return a;
        }
        i64 m = a / b;
        a %= b;
        ap -= bp * m;
        aq -= bq * m;
        if(a == 0) {
            *x = bp, *y = bq;
            return b;
        }
        i64 n = b / a;
        b %= a;
        bp -= ap * n;
        bq -= aq * n;
    }
}