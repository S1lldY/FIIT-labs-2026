#include <stdio.h>
#include <math.h>

int main() {
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

    double d = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
   

    if (r1 == r2 && x1 == x2 && y1 == y2) {
        printf("\nсовпадение\n");
    } else if (r_max - r_min == d) {
        printf("\nодно внутреннее касание\n");
    } else if (r_max > d + r_min) {
        printf("\nодна внутри другой без касаний\n");
    } else if (d == r1 + r2) {
        printf("\nодно внешнее касание\n");
    } else if (d > r1 + r2) {
        printf("\nнет касаний\n");
    } else if (d < r1 + r2) {
        printf("\nдва касания\n");
    }
    return 0;
}
}