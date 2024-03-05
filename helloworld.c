#include <stdio.h>

main() {

    int x = 3, y = 2, r1, r2, r3;
    r1 = x > y ? 2 : 6;
    r2 = x > y ? x : y;
    r3 = x % 2 == 0 ? 0 : 1;

    printf("%d %d %d\n", r1,r2,r3);
}