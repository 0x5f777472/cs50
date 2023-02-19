#include <stdio.h>
#include <stdlib.h>
long long cltz(long long x);

int main() {
    long long n;
    int sign, loop;
    char input[256];
    while (1) {
        printf("Enter a positive or negative integer (0 to quit): ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        if (sscanf(input, "%lld", &n) != 1) continue;
        if (n == 0) break;
        sign = n < 0 ? 1 : 0;
        long long on = n, slow = n, fast = n;
        while (sign) {
            slow = cltz(slow);
            fast = cltz(fast);
            fast = cltz(fast);
            if (fast == slow) {
                loop = 1; 
                break;
            }
        }
        if (on == slow && sign) printf("( ");
        while (n != 1) {
            printf("%lld ", n);
            n = cltz(n);
            if (n == 1) {
                printf("1");
                break;
            } else if (n == slow) break;
        }
        long long c_slow = cltz(slow);
        if (loop && sign && slow != on) {
            printf("( %lld ", slow);
            while (c_slow != slow) {
                printf("%lld ", c_slow);
                c_slow = cltz(c_slow);
            }
            printf(")");
        } else if (sign && slow == on) printf(")");
        printf("\n");
    }
    return 0;
}
long long cltz(long long x) {
    return x % 2 == 0 ? x >> 1 : (x << 1) + x + 1;
}
