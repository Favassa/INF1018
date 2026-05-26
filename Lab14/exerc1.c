typedef union {
  float f;
  unsigned int i;
} U;

#define makefloat(s,e,f) (((s) & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))
#define getsig(x) ((x)>>31 & 1)
#define getexp(x) ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)

float float2(float f) {
    U u;
    unsigned int s, e, frac;

    u.f = f;
    
    s = getsig(u.i);
    e = getexp(u.i);
    frac = getfrac(u.i);

    if (e == 0) {
        frac = frac << 1;
    } else if (e < 255) {
        e = e + 1;
    }

    u.i = makefloat(s, e, frac);
    return u.f;
}