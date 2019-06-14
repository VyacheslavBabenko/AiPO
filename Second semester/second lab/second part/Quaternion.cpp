#include "pch.h"
#include "Quaternion.h"
#include "Vector3.h"
#include <iostream>
#include <complex>

Quaternion::Quaternion(Vector3& rotation_vector, double rotation_alpha){ //construktor ugol+vector
	rotation_vector.normalization(rotation_vector);
	w_ = cos(rotation_alpha / 2);
	x_ = rotation_vector[0] * sin(rotation_alpha / 2);
	y_ = rotation_vector[1] * sin(rotation_alpha / 2);
	z_ = rotation_vector[2] * sin(rotation_alpha / 2);
}

Quaternion::Quaternion(std::complex< double > z1, std::complex< double > z2) { // construktor cherez komlp
	w_ = z1.real();
	x_ = z1.imag();
	y_ = z2.real();
	z_ = z2.imag();
}

Quaternion::Quaternion(double w = 0, double x = 0, double y = 0, double z = 0) {// consturktor cherez koordinati
	w_ = w;
	x_ = x;
	y_ = y;
	z_ = z;
}
const Quaternion& Quaternion::operator/=(double len) { // peregruzka /= (Seriosly?)
	w_ /= len;
	x_ /= len;
	y_ /= len;
	z_ /= len;
	return *this; 
}
Quaternion Quaternion::invert() {
	Quaternion res(w_, -x_, -y_, -z_);
	double length = sqrt(w_ * w_ + x_ * x_ + y_ * y_ + z_ * z_);
	res /= length;
	return res;
}

Quaternion Quaternion::operator*(const Quaternion& q) {
	Quaternion res;
	res.w_ = w_ * q.w_ - x_ * q.x_ - y_ * q.y_ - z_ * q.z_;
	res.x_ = w_ * q.x_ + x_ * q.w_ + y_ * q.z_ - z_ * q.y_;
	res.y_ = w_ * q.y_ - x_ * q.z_ + y_ * q.w_ + z_ * q.x_;
	res.z_ = w_ * q.z_ + x_ * q.y_ - y_ * q.x_ + z_ * q.w_;
	return res;
}

Quaternion Quaternion::pros_vector(Vector3& v) { //proizvedenie quaterniona na vector
	Quaternion res(0, 0, 0, 0);
	res.w_ = -x_ * v[0] - y_ * v[1] - z_ * v[2];
	res.x_ = w_ * v[0] + y_ * v[2] - z_ * v[1];
	res.y_ = w_ * v[1] - x_ * v[2] + z_ * v[0];
	res.z_ = w_ * v[2] + x_ * v[1] - y_ * v[0];
	return res;
}

void Quaternion::operator=(const Quaternion& q) {
	w_ = q.w_;
	x_ = q.x_;
	y_ = q.y_;
	z_ = q.z_;
}

double Quaternion::operator[](int i) {
	if (i == 0) return w_;
	if (i == 1) return x_;
	if (i == 2) return y_;
	if (i == 3) return z_;
	if (i < 0 || i > 3) std::cout << "i havent this coordinate\n";
}

void Quaternion::print() {
	std::cout << w_ << " " << x_ << " " << y_ << " " << z_ << "\n";
}

Quaternion::~Quaternion() {

}