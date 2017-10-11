#include "SplinesForm.h"
#include <Windows.h>

using namespace CG_3_Kolos;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew SplinesForm);
	return 0;
}

void CG_3_Kolos::SplinesForm::NBezier(System::Drawing::Graphics ^ g)//����� ���������
{
	bezier.Clear();
	if (deCasteljau)
	{
		BezierDeCasteljau(g);
	}
	else 
	{
		Bezier(g);
	}
}
void CG_3_Kolos::SplinesForm::clear()//������� ������
{
	Graphics^g = Graphics::FromImage(bm);

	g->Clear(Color::FromArgb(192));
	pictureBox->Invalidate();
	//points.Clear();
	bezier.Clear();
}
void CG_3_Kolos::SplinesForm::Bezier(System::Drawing::Graphics ^g)//������������ ����������
{
	int n = points.Count;
	float** coord = new float*[Utils::DIMENSIONS];
	float** coeffs = new float*[n];
	
	for (int i = 0; i < Utils::DIMENSIONS; i++)
	{
		coord[i] = new float[n];
	}
		
	for (int i = 0; i < n; i++)
	{
		coord[0][i] = points[i].X;
		coord[1][i] = points[i].Y;
		coeffs[i] = new float[n];

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int k = Utils::BinCoeff(i, j, n-1);
			coeffs[i][j] = k;
		}
	}
	int shape1[2] = { Utils::DIMENSIONS, n };
	int shape2[2] = { n, n };
	float** step1 = Utils::MatMul(coord, coeffs, shape1, shape2);
	//float **step2 =
	float t = 0;
	int t_shape[2] = { n,1 };
	while (t < 1)
	{
		float**tt = new float*[n];
		for (int i = 0; i < n; i++)
		{
			tt[i] = new float[1] {(float)Math::Pow( t,i)};
			
			float h = tt[i][0];
		}
		
		float** res = Utils::MatMul(step1, tt, shape1, t_shape);
		bezier.Add(Point(res[0][0], res[1][0]));
		t += 0.01f;
	}
	drawBezier(g);
	
}

void CG_3_Kolos::SplinesForm::CubicBezier(System::Drawing::Graphics ^ g,  int offset)//���������� ������
{
	bezier.Clear();
	int n = 4;
	float** coord = new float*[Utils::DIMENSIONS];
	
	for (int i = 0; i < Utils::DIMENSIONS;i++)
	{
		coord[i] = new float[n];
	}
	for (int i = 0; i < n; i++)
	{
		if (offset < 0)
		{
			coord[0][i] = closure[i].X;
			coord[1][i] = closure[i].Y;
		}
		else {
			coord[0][i] = points[i + offset].X;
			coord[1][i] = points[i + offset].Y;
		}
	}
	int shape1[2] = { Utils::DIMENSIONS, n };
	int shape2[2] = { n, n };
	float** step1 = Utils::MatMul(coord, CubicMatrix, shape1, shape2);

	float t = 0;
	int t_shape[2] = { n,1 };
	while (t < 1)
	{
		float**tt = new float*[n];
		for (int i = 0; i < n; i++)
		{
			tt[i] = new float[1]{ (float)Math::Pow(t,i) };

			float h = tt[i][0];
		}

		float** res = Utils::MatMul(step1, tt, shape1, t_shape);
		//g->DrawRectangle(Pens::Black, (int)res[0][0], (int)res[1][0], 1, 1);
		bezier.Add(Point(res[0][0], res[1][0]));
		t += 0.01f;
	}
	drawBezier(g);
}

void CG_3_Kolos::SplinesForm::ComposedBezier(System::Drawing::Graphics ^ g)//��������� ������ � ���������� ������
{
	int n = points.Count;
	
	for (int i = 0; i <n-3; i+=3)
	{
		CubicBezier(g, i);
	}
}

void CG_3_Kolos::SplinesForm::ContinueLine()//���������� ����� ��� ���������� ������� ���������
{
	Point last = points[points.Count - 1];
	Point prelast = points[points.Count - 2];

	float deltaX = last.X - prelast.X;
	float deltaY = last.Y - prelast.Y;

	Point next = Point(last.X + deltaX, last.Y + deltaY);
	Graphics^g = Graphics::FromImage(bm);
	g->FillEllipse(Brushes::Red, next.X, next.Y, 2, 2);
	pictureBox->Invalidate();
	points.Add(next);
}


void CG_3_Kolos::SplinesForm::CloseBezier(System::Drawing::Graphics ^ g)//��������� � ������� ���������� �����
{
	if (pointCount % 2 != 0)
	{
		ContinueLine();
	}

	float deltaX = points[0].X - points[1].X;
	float deltaY = points[0].Y - points[1].Y;

	Point next = Point(points[0].X+ deltaX, points[0].Y+ deltaY);

	closure.Clear();
	closure.Add(points[0]);
	closure.Add(next);
	closure.Add(points[points.Count - 1]);
	closure.Add(points[points.Count - 2]);

	CubicBezier(g, -1);
	
}

void CG_3_Kolos::SplinesForm::drawBezier(System::Drawing::Graphics ^ g)//��������� ������ �� �������
{
	int n = bezier.Count;
	for (int i = 0; i < n-1; i++)
	{
		g->DrawLine(Pens::Black, bezier[i], bezier[i + 1]);
	}

}



/*����������� �������� ��������� �������� �� ��� ����� ��-�� ������ �������� ���������� �� X � Y*/
void CG_3_Kolos::SplinesForm::BezierDeCasteljau(System::Drawing::Graphics ^ g)//���������� ���������
{
	bezier.Clear();
	float delta = 0.01f;
	int order = points.Count-1;
	for (float t = 0; t <= 1; t += delta) {
		
		bezier.Add(Point(deCasteljauX(order, 0, t), deCasteljauY(order, 0, t)));
	}
	drawBezier(g);

}




float CG_3_Kolos::SplinesForm::deCasteljauX(int i, int j, float t)//����������� ����� �� X
{
	if (i == 1) {
		return (1 - t) * points[j].X + t * points[j + 1].X;
	}
	return (1 - t) * deCasteljauX(i - 1, j, t) + t * deCasteljauX(i - 1, j + 1, t);
}

float CG_3_Kolos::SplinesForm::deCasteljauY(int i, int j, float t)//����������� ����� �� Y
{
	if (i == 1) {
		return (1 - t) * points[j].Y + t * points[j + 1].Y;
	}
	return (1 - t) * deCasteljauY(i - 1, j, t) + t * deCasteljauY(i - 1, j + 1, t);
}






