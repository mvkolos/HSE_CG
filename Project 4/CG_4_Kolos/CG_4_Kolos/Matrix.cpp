#include "Matrix.h"

//void Matrix::invert()
//{
//	Matrix out(1);
//	for (int i = 0; i < 4; i++)
//	{
//		float d = x[i][i];
//		if (d != 1)
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				out.x[i][j] /= d;
//				x[i][j] /= d;
//			}
//		}
//		for (int j = 0; j < 4; j++)
//		{
//			if (j != i)
//			{
//				if (x[j][i] != 0)
//				{
//					float mulBy = x[j][i];
//					for (int k = 0; k < 4; k++)
//					{
//						x[j][k] -= mulBy * x[i][k];
//						out.x[j][k] -= mulBy * out.x[i][k];
//					}
//				}
//			}
//		}
//	}
//	*this = out;
//
//
//
//}

Matrix Matrix::translate(const Vector3d &loc)
{
	Matrix res(1);
	res.x[0][3] = loc.x;
	res.x[1][3] = loc.y;
	res.x[2][3] = loc.z;
	return res;

}

Matrix Matrix::scale(const Vector3d &v)
{
	Matrix res(1);
	res.x[0][0] = v.x;
	res.x[1][1] = v.y;
	res.x[2][2] = v.z;

	return res;

}

Matrix Matrix::rotateX(float angle)
{
	Matrix res (1);
	float cosine = cos(angle);
	float sine = sin(angle);
	res.x[1][1] = cosine;
	res.x[1][2] = -sine;
	res.x[2][1] = sine;
	res.x[2][2] = cosine;
	return res;

}

Matrix Matrix::rotateY(float angle)
{
	Matrix res (1);
	float cosine = cos(angle);
	float sine = sin(angle);
	res.x[0][0] = cosine;
	res.x[0][2] = -sine;
	res.x[2][0] = sine;
	res.x[2][2] = cosine;
	return res;

}

Matrix Matrix::rotateZ(float angle)
{
	Matrix res (1);
	float cosine = cos(angle);
	float sine = sin(angle);
	res.x[0][0] = cosine;
	res.x[0][1] = -sine;
	res.x[1][0] = sine;
	res.x[1][1] = cosine;
	return res;

}

Matrix Matrix::mirrorX()
{
	Matrix mirror = Matrix(1);
	mirror[0][0] = -1;
	return mirror;
}
Matrix Matrix::mirrorY()
{
	Matrix mirror = Matrix(1);
	mirror[1][1] = -1;
	return mirror;
}
Matrix Matrix::mirrorZ()
{
	Matrix mirror = Matrix(1);
	mirror[2][2] = -1;
	return mirror;
}


Vector3d Matrix::perspectiveProjection(Vector3d & v, float z)
{
	Matrix persp = Matrix(1);
	persp[2][2] = 0;
	persp[3][2] = -1/z;
	Vector3d res = persp*v;
	return res;
}

Vector3d Matrix::orthographicProjection(Vector3d & v)
{
	Matrix ort = Matrix(1);
	ort[2][2] = 0;
	Vector3d res = ort*v;
	return res;
}

Matrix::Matrix(float v)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			x[i][j] = (i == j) ? v : 0;
		}
	x[3][3] = 1;	

}

Matrix operator*(const Matrix &a, const Matrix &b)
{
	Matrix res;
	for (register int i = 0; i < 4; i++)
	{
		for (register int j = 0; j < 4; j++)
		{
			float sum = 0;
			for (register int k = 0; k < 4; k++)
			{
				sum += a.x[i][k] * b.x[k][j];				
			}
			res.x[i][j] = sum;
		}
	}
	return res;

}

Vector3d operator*(const Matrix &m, const Vector3d &v)
{
	Vector3d res;
	res.x = m.x[0][0] * v.x + m.x[0][1] * v.y +
		m.x[0][2] * v.z + m.x[0][3];
	res.y = m.x[1][0] * v.x + m.x[1][1] * v.y +
		m.x[1][2] * v.z + m.x[1][3];
	res.z = m.x[2][0] * v.x + m.x[2][1] * v.y +
		m.x[2][2] * v.z + m.x[2][3];
	float denom = m.x[3][0] * v.x + m.x[3][1] * v.y +
		m.x[3][2] * v.z + m.x[3][3];
	if (denom != 1.0)
		res /= denom;
	return res;

}
