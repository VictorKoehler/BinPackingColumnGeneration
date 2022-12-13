typedef unsigned int uint;

extern unsigned long long getNextSeed();

extern char const *const GIT_COMMIT;

#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
