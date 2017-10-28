#include "Shape.h"

void Tetrahedron::ApplyTranslation()
{
	 GlobalPosition=transform.PositionMatrix*Pivot;
}

void Tetrahedron::ApplyMirror()
{
	for (int i = 0; i < 4; i++)
	{
		vertices[i] = transform.MirrorMatrix*vertices[i];
	}
	Pivot = transform.MirrorMatrix*Pivot;
}

void Tetrahedron::ApplyScale()
{
	for (int i = 0; i < 4; i++)
	{
		vertices[i] = transform.ScaleMatrix*vertices[i];
	}
}

void Tetrahedron::RecomputeProjection(float z, int width, int height)
{
	for (int i = 0; i < 4; i++)
	{
		Display[i] = _recomputeProjection(vertices[i] + GlobalPosition, z, width, height);
	}
	PivotDisplay = _recomputeProjection(Pivot + GlobalPosition, z, width, height);
}

Tetrahedron::Tetrahedron()
{
	GlobalPosition = Vector3d();

	float sq = System::Math::Sqrt(3) / 3;
	float sq_S = System::Math::Sqrt(6) / 4;

	vertices[0] = Vector3d(0, sq_S / 3, sq);
	vertices[1] = Vector3d(0.5, sq_S / 3, -sq / 2);
	vertices[2] = Vector3d(-0.5, sq_S / 3, -sq / 2);
	vertices[3] = Vector3d(0, -sq_S, 0);

	facets[0] = Vector3d(0, 1, 2);
	facets[1] = Vector3d(0, 1, 3);
	facets[2] = Vector3d(0, 2, 3);
	facets[3] = Vector3d(1, 2, 3);

}

void Tetrahedron::ApplyRotation()
{
	for (int i = 0; i < 4; i++)
	{
		vertices[i] = transform.RotationMatrix*vertices[i];
	}
}

void Tetrahedron::RecomputePivot()
{
	Vector3d pivot = Vector3d();
	float x_=0;
	float y_ = 0;
	float z_ = 0;
	for (int i = 0; i < N; i++)
	{
		pivot += vertices[i];
		
	}
	Pivot = pivot / N;
}

Vector3d Tetrahedron::_recomputeProjection(Vector3d & v, float z, int width, int height)
{
	Vector3d res = v;
	if (perspective) {
		res = Matrix::perspectiveProjection(v, z);
	}
	else {
		res = Matrix::orthographicProjection(v);
	}

	res = res.WordldToScreen(width, height);

	return res;
}

void Transform::RotateX(float alpha)
{
	RotationMatrix = Matrix::rotateX(LocalRotation.x-alpha);
	LocalPosition = RotationMatrix*LocalPosition;
	LocalRotation.x = alpha;
	
}

void Transform::RotateY(float alpha)
{
	RotationMatrix = Matrix::rotateY(LocalRotation.y-alpha);
	LocalPosition = RotationMatrix*LocalPosition;
	LocalRotation.y = alpha;
}

void Transform::RotateZ(float alpha)
{
	RotationMatrix = Matrix::rotateZ(LocalRotation.z-alpha);
	LocalPosition = RotationMatrix*LocalPosition;
	LocalRotation.z = alpha;
}

void Transform::MirrorX()
{
	MirrorMatrix = Matrix::mirrorX();
	//Position = m*Position;
}

void Transform::MirrorY()
{
	MirrorMatrix = Matrix::mirrorY();
}
void Transform::MirrorZ()
{
	MirrorMatrix = Matrix::mirrorZ();
}

void Transform::Scale(Vector3d scale)
{
	ScaleMatrix = Matrix::scale(scale);
	LocalScale = scale;
}


void Transform::Translate(Vector3d position)
{
	PositionMatrix = Matrix::translate(position);
	LocalPosition = PositionMatrix*LocalPosition;
		
}
