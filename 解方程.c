#include <stdio.h>
#include <math.h>
#include <math.h>

double func(double x) {
    return pow(x, 4) + 5 * pow(x, 3) + 6 * pow(x, 2) + 7 * x + 4;
}

double solve_equation(double y) {
	double l, r, m;
    l = 0, r = 100;
    if (y < func(l) || y > func(r)) return -1;
    while (r - l >= 1e-3) {
        m = (r + l) / 2.0;
        func(m) < y ? l = m : (r = m);
    }
    return r;
}
int main() {
	double y;
	scanf("%lf", &y);
	printf("%.10f\n", solve_equation(y));
}
