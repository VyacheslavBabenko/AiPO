#include "pch.h"
#include"Quaternion.h"
#include"Vector3.h"
#include <iostream>
#include <complex>
#include <cmath>


Vector3 quat_trans_vector(Quaternion q,Vector3 v) { //povorot vectora quaternionom
	Quaternion tmp(0, 0, 0, 0);
	tmp = q.pros_vector(v);
	tmp = tmp * q.invert();
	Vector3 res(tmp[1], tmp[2], tmp[3]);
	return res;
}

int main() {
	Vector3 a(4, 3, 2);
	Vector3 b(5, 4, 1);
	a.print();
	b.print();
	Vector3 c = a + b;
	c.print();
	std::complex <double> z1(3, 4);
	std::complex <double> z2(1, 7);
	double d = a * b;
	std::cout << d << "\n";
	Vector3 e = a.axb(b);
	e.print();
	double f = a.mixed_pros(b, c);
	Vector3 g = e;
	Quaternion s(a, 90);
	s.print();
	Quaternion k = s.invert();
	k.print();
	Quaternion l = s * k;
	l.print();
	Quaternion m = l.pros_vector(e);
	m.print();
	Quaternion n(z1, z2);
	std::cout << g[0] << " " << g[1] << " " << g[2] << "\n";
	std::cout << n[0] << " " << n[1] << " " << n[2] << " " << n[3] << "\n";
	return 0;
}
