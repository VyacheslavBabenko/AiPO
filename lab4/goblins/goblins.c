#include <stdio.h>
#include <math.h>
#define EPS	1e-5
#define ABS(x)	((x) > 0 ? (x) : -(x))

double integrate(double a, double b, double c, double (*f)(double), int n) {
	double s = 0;
	double h = (b - a) / n;
	double xi;
	for (xi = a; xi < b; xi += h)
		s += (f(xi) - c) * h;
	return s;
}

double space(double a, double b, double c, double (*f)(double)) {
	int n = 32;
	double s1 = integrate(a, b, c, f, n);
	n *= 2;
	double s2 = integrate(a, b, c, f, n);
	while (ABS(s1 - s2) > EPS) {
		s1 = s2;
		n *= 2;
		s2 = integrate(a, b, c, f, n); 
	}
	return s1;
}

double xcos(double x) {
	return x * cos(x);
}

double sqx_plus_x_minus_tg(double x) {
	return pow(x, 2) + x - tan(x);
}

double exp_plus_3(double x) {
	return exp(x) + 3;
}

double search(double s, double a, double b, double c) {
	double (*f[4])(double) = {sin, xcos, sqx_plus_x_minus_tg, exp_plus_3};
	double max = -1.0;
	int i;
	for (i = 0; i < 4; i++) {
		double t = space(a, b, c, f[i]);
		printf("%lf\n", t);
		if (s >= t && t > max)
			max = t;
	}
	return max;
}

int main(void) {
	double s, a, b, c;
	scanf("%lf%lf%lf%lf", &s, &a, &b, &c);
	printf("%lf\n", search(s, a, b, c));
	return 0;
}

