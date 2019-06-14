#ifndef greg
#define greg
class Vector3 {

private:
	double x_;
	double y_;
	double z_;

public:
	
	Vector3(double x, double y, double z);
	Vector3 operator+(const Vector3& v);
	double operator*(const Vector3& v);
	Vector3 axb(const Vector3& v); //vectornoe prozvedenie
	double mixed_pros(Vector3& v2, const Vector3& v3); //smeshannoe prozivedenie
	void operator=(Vector3& v);
	void print();
	double operator[](int i); //peregruzka
	~Vector3();
	Vector3 normalization(Vector3& v); 
};
#endif