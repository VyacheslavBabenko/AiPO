#include "pch.h"
#include "Vector3.h"
#include<complex>
class Quaternion {
private:
	double w_;
	double x_;
	double y_;
	double z_;
public:
	~Quaternion();
	Quaternion(Vector3& rotation_vector, double rotation_alpha);
	Quaternion(std::complex< double > z1, std::complex< double > z2);
	Quaternion(double w, double x, double y, double z);
	const Quaternion& operator/=(double len);
	Quaternion invert();
	Quaternion operator*(const Quaternion& q);
	Quaternion pros_vector(Vector3& v);
	void operator=(const Quaternion& q);
	double operator[](int i);
	void print();
};

