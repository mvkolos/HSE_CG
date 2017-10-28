#pragma once
#include "Matrix.h"


class Shape {
public:
	int N = 4;//vertices
	int M = 2 * N - 4;//edges

	Matrix Transform;

	Vector3d* edges;
	Vector3d vertices[8];



};

class Transform
{
public:
	Transform() {
		LocalPosition = Vector3d();
		LocalRotation = Vector3d();
		MirrorMatrix = Matrix(1);
	}
	//local transform
	Vector3d LocalPosition;
	Vector3d LocalRotation;	
	Vector3d LocalScale;

	//Matrices of basic transformations
	Matrix ScaleMatrix;
	Matrix RotationMatrix;
	Matrix PositionMatrix;
	Matrix MirrorMatrix;

	//rotation
	void RotateX(float alpha);
	void RotateY(float alpha);
	void RotateZ(float alpha);

	//mirroring
	void MirrorX();
	void MirrorY();
	void MirrorZ();

	void Scale(Vector3d scale);
	void Translate(Vector3d position);
};
class Tetrahedron {
public:
	int N = 4;//vertices
	int M = 4;
	//Matrix Transform;
	Transform transform;
	Vector3d facets[4];
	Vector3d vertices[4];
	Vector3d Pivot;
	Vector3d GlobalPosition;

	Vector3d Display[4]; 
	Vector3d PivotDisplay;
	bool perspective = false;
	bool translate = false;

	//default constructor for regular tetrahedron
	Tetrahedron();

	//transform changes handlers
	void ApplyTranslation();
	void ApplyMirror();
	void ApplyScale();
	
	void RecomputeProjection(float z, int width, int height);	
	void ApplyRotation();
	void RecomputePivot();
private:
	Vector3d _recomputeProjection(Vector3d &v, float z, int width, int height);
	
	
	
};



