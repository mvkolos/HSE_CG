#pragma once
#include <math.h> 


public class Vector3d {

public:
	float x, y, z;
	int Scale=100;
	Vector3d() {
		x = 0;
		y = 0;
		z = 0;
	}
	Vector3d(float px, float py, float pz) {
		x = px;
		y = py;
		z = pz;
	}
	Vector3d(const Vector3d& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}
	Vector3d& operator = (const Vector3d& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}
	Vector3d operator + () const
	{
		return *this;
	}
	Vector3d operator - () const
	{
		return Vector3d(-x, -y, -z);
	}
	Vector3d& operator += (const Vector3d& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	Vector3d& operator -= (const Vector3d& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	Vector3d& operator *= (const Vector3d& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}

	Vector3d& operator *= (float f)
	{
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}
	Vector3d& operator /= (const Vector3d& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		return *this;
	}
	Vector3d& operator /= (float f)
	{
		x /= f;
		y /= f;
		z /= f;

		return *this;
	}
	float& operator [] (int index)
	{
		return *(index + &x);
	}
	int operator == (const Vector3d& v) const
	{
		return x == v.x && y == v.y && z == v.z;
	}
	int operator != (const Vector3d& v) const
	{
		return x != v.x || y != v.y || z != v.z;
	}
	int operator < (const Vector3d& v) const
	{
		return (x < v.x) || ((x == v.x) && (y < v.y));
	}
	int operator > (const Vector3d& v) const
	{
		return (x > v.x) || ((x == v.x) && (y > v.y));
	}
	float length() const
	{
		return (float)sqrt(x*x + y*y + z*z);
	}
	Vector3d WordldToScreen(int h, int w)
	{
		Vector3d res;// = Vector3d(, ;
		res[0] = x*Scale+ w / 2;
		res[1] = y*Scale +h / 2;
		return res;
	}
	Vector3d ScreenToWorld(int h, int w)
	{
		Vector3d res;// = Vector3d(, ;
		res[0] = (x - w / 2) / Scale;
		res[1] = (y - h / 2) / Scale;
		return res;
	}
	friend Vector3d operator + (const Vector3d&, const Vector3d&);
	friend Vector3d operator - (const Vector3d&, const Vector3d&);
	friend Vector3d operator * (const Vector3d&, const Vector3d&);
	friend Vector3d operator * (float, const Vector3d&);
	friend Vector3d operator * (const Vector3d&, float);
	friend Vector3d operator/ (const Vector3d&, float);
	friend Vector3d operator / (const Vector3d&, const Vector3d&);
	friend float operator & (const Vector3d&, const Vector3d&);
	friend Vector3d operator ^ (const Vector3d&, const Vector3d&);
};
	
	inline Vector3d operator + (const Vector3d& u, const Vector3d& v)
	{
		return Vector3d(u.x + v.x, u.y + v.y, u.z + v.z);
	}
	inline Vector3d operator - (const Vector3d& u, const Vector3d& v)
	{
		return Vector3d(u.x - v.x, u.y - v.y, u.z - v.z);
	}
	inline Vector3d operator * (const Vector3d& u, const Vector3d& v)
	{
		return Vector3d(u.x*v.x, u.y*v.y, u.z * v.z);
	}
	inline Vector3d operator * (const Vector3d& v, float a)
	{
		return Vector3d(v.x*a, v.y*a, v.z*a);
	}
	inline Vector3d operator * (float a, const Vector3d& v)
	{
		return Vector3d(v.x*a, v.y*a, v.z*a);
	}
	inline Vector3d operator / (const Vector3d& u, const Vector3d& v)
	{
		return Vector3d(u.x / v.x, u.y / v.y, u.z / v.z);
	}
	inline Vector3d operator / (const Vector3d& v, float a)
	{
		return Vector3d(v.x / a, v.y / a, v.z / a);
	}
	inline float operator & (const Vector3d& u, const Vector3d& v)
	{
		return u.x*v.x + u.y*v.y + u.z*v.z;
	}
	inline Vector3d operator ^ (const Vector3d& u, const Vector3d& v)
	{
		return Vector3d(u.y*v.z - u.z*v.y, u.z*v.x - u.x*v.z,
			u.x*v.y - u.y*v.x);
	}
	class Vector4d {
	public:
		float x, y, z,s;
		Vector4d() {}
		Vector4d(float px, float py, float pz,float ps) {
			x = px;
			y = py;
			z = pz;
			s = ps;
		}
	};

