#include "pch.h"
#include "Vector3.h"
#include <iostream>

Vector3::Vector3(double x, double y, double z) { // Constructor 
	x_ = x;
	y_ = y;
	z_ = z;
}

Vector3 Vector3::operator+(const Vector3& v) {
	return Vector3(x_ + v.x_, y_ + v.y_, z_ + v.z_);
}

double Vector3::operator*(const Vector3& v) {
	return (x_ * v.x_ + y_ * v.y_ + z_ * v.z_);
}

Vector3 Vector3::axb(const Vector3& v) { //vectornoe proizvedenie 
	return
		Vector3(
			y_ * v.z_ - v.y_ * z_,
			z_ * v.x_ - v.z_ * x_,
			x_ * v.y_ - v.x_ * y_
		);
}
void Vector3::operator=(Vector3& v) { 
	x_ = v.x_;
	y_ = v.y_;
	z_ = v.z_;
}

double Vector3::mixed_pros(Vector3& v2, const Vector3& v3) { //smeshannoe proizvedenie
	Vector3 tmp = v2.axb(v3);
	return (x_ * tmp.x_ + y_ * tmp.y_ + z_ * tmp.z_);
}



void Vector3::print() {
	std::cout << x_ << " " << y_ << " " << z_ << "\n";
}

double Vector3::operator[](int i) { //peregruzka dlya ispolzovanya vne classa
	if (i == 0)
		return x_;
	if (i == 1)
		return y_;
	if (i == 2)
		return z_;
	if (i < 0 || i > 2)
		std::cout << "i haven,t this coordinate\n";
}
Vector3 Vector3::normalization(Vector3& v) {
	double length = sqrt(v.x_ * v.x_ + v.y_ * v.y_ + v.z_ * v.z_);

	return Vector3(v.x_ / length, v.y_ / length, v.z_ / length);
}

Vector3::~Vector3() {

}