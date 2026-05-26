typedef union {
  float f;
  unsigned int i;
} U;

#define makefloat(s,e,f) (((s) & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))

float int2float(int i) {
    U u;
    unsigned int s = 0;
    unsigned int e, frac;
    unsigned int abs_i;
    int k = 31;

    if (i == 0) {
        u.i = 0;
        return u.f;
    }

    if (i < 0) {
        s = 1;
        abs_i = (unsigned int)(-i);
    } else {
        abs_i = (unsigned int)i;
    }

    while ((abs_i & (1U << k)) == 0) {
        k--;
    }

    e = k + 127;
    abs_i = abs_i & ~(1U << k);

    if (k <= 23) {
        frac = abs_i << (23 - k);
    } else {
        frac = abs_i >> (k - 23);
    }

    u.i = makefloat(s, e, frac);
    return u.f;
}