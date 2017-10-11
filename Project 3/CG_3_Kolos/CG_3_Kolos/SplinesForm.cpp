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

void CG_3_Kolos::SplinesForm::Bezier(System::Drawing::Graphics ^g)
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
		g->DrawRectangle(Pens::Black, (int)res[0][0], (int)res[1][0], 1, 1);
		bezier.Add(Point(res[0][0], res[1][0]));
		t += 0.01f;
	}
	
}

void CG_3_Kolos::SplinesForm::CubicBezier(System::Drawing::Graphics ^ g,  int offset)
{
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
		g->DrawRectangle(Pens::Black, (int)res[0][0], (int)res[1][0], 1, 1);
		//bezier.Add(Point(res[0][0], res[1][0]));
		t += 0.01f;
	}
}

void CG_3_Kolos::SplinesForm::ComposedBezier(System::Drawing::Graphics ^ g)
{
	int n = points.Count;
	
	for (int i = 0; i <n-3; i+=3)
	{
		CubicBezier(g, i);
	}
}

void CG_3_Kolos::SplinesForm::ContinueLine()
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

void CG_3_Kolos::SplinesForm::checkClosure()
{
	int n = points.Count;
	float ratio1 = (points[0].X - points[n - 2].X) *(points[0].Y - points[n - 2].Y);
	float ratio2 = (points[1].X - points[n - 2].X) * (points[1].Y - points[n - 2].Y);
	textBoxDebug->Text = ratio1.ToString() + " "+ratio2.ToString();
	readyToClose = (ratio1 == ratio2);


}

void CG_3_Kolos::SplinesForm::CloseBezier(System::Drawing::Graphics ^ g)
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
	g->DrawEllipse(Pens::Magenta, next.X, next.Y, 5,5);
	pictureBox->Invalidate();
}





