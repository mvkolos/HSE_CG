#pragma once
//#include <mem.h> 
#include "Vector3d.h" 
class Matrix {
public:
	float x[4][4];
	Matrix() {}
	Matrix(float);
	
	/*Matrix& operator += (const Matrix&);
	Matrix& operator -= (const Matrix&);
	Matrix& operator *= (const Matrix&);
	Matrix& operator *= (float);
	Matrix& operator /= (float);*/

	float * operator [] (int i)
	{
		return &x[i][0];
	}
	//void invert();
	friend Vector3d operator * (const Matrix&, const Vector3d&);

	static Matrix translate(const Vector3d&);
	static Matrix scale(const Vector3d&);
	static Matrix rotateX(float);
	static Matrix rotateY(float);
	static Matrix rotateZ(float);
	//Matrix rotate(const Vector3d&v, float);
	static Matrix mirrorX();
	static Matrix mirrorY();
	static Matrix mirrorZ();
	static Vector3d perspectiveProjection(Vector3d&v,float z);
	static Vector3d orthographicProjection(Vector3d&v);


};