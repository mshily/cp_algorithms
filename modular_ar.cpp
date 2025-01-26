// ..modular arithmetic
int mult (int a, int b) {
    return 1LL * a * b % mod;
}

int add (int a, int b) {
    return a + b >= mod ? a + b - mod : a + b;
}

int sub (int a, int b) {
    return a - b < 0 ? a - b + mod : a - b;
}

int bpow (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mult (res, a);
        b >>= 1;
        a = mult (a, a);
    }
    return res;
}

int del (int a, int b) {
    return mult (a, bpow (b, mod - 2));
}
//