#include <stdio.h>
#include <math.h>

int main(void) {
    printf("\n1 круг r1, x1, y1\n");
    int r1, x1, y1;
    scanf("%i %i %i", &r1, &x1, &y1);

    printf("\n2 круг r2, x2, y2\n");
    int r2, x2, y2;
    scanf("%i %i %i", &r2, &x2, &y2);

    if (r1 < 0 || r2 < 0) {
        printf("\nневерно\n");
    } else {

    int r_max, r_min;

    if (r1 > r2) {
        r_max = r1;
        r_min = r2;
    } else {
        r_max = r2;
        r_min = r1;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = dx * dx + dy * dy;

    int summa = r1 + r2;
    int razn = r_max - r_min;
   

    if (r1 == r2 && x1 == x2 && y1 == y2) {
        printf("\nсовпадение\n");
    } else if (razn * razn == d) {
        printf("\nодно внутреннее касание\n");
    } else if (razn * razn > d) {
        printf("\nодна внутри другой без касаний\n");
    } else if (d == summa * summa) {
        printf("\nодно внешнее касание\n");
    } else if (d > summa * summa) {
        printf("\nнет касаний\n");
    } else {
        printf("\nдва касания\n");
    }
    return 0;
}
}