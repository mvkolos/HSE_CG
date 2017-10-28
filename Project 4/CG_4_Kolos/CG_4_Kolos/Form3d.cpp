#include "Form3d.h"
#include <Windows.h>

using namespace CG_4_Kolos;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Form3d);
	return 0;
}

void CG_4_Kolos::Form3d::Rotate()
{
	//Vector3d axis = counter % 3 == 0 ? Vector3d(0, 1, 0) : (counter % 3 == 1 ? Vector3d(1, 0, 0) : Vector3d(0, 0, 1));
	
	int z = trackBarZ->Value;
	float r = trackBarR->Value*DEG_TO_RAD;
	tetr->RecomputePivot();
	Matrix m = Matrix();

	Graphics ^g = Graphics::FromImage(bm);
	
	Vector3d v;
	Matrix rot;
	Vector3d vert[4];
	//Vector3d pivot = m.perspectiveProjection(tetr->Pivot, z);
	switch (axis)
	{
	case 0:
		tetr->transform.RotateX(r);
		//rot = m.rotateX(r);			
		break;
	case 1:
		tetr->transform.RotateY(r);
		//rot = m.rotateY(r);
		break;
	case 2:
		tetr->transform.RotateZ(r);
		//rot = m.rotateZ(r);
		break;
	default:
		break;
	}
	tetr->ApplyRotation();
	tetr->RecomputeProjection(z, pictureBox->Width, pictureBox->Height);
	//pivot = pivot.WordldToScreen(pictureBox->Width, pictureBox->Height);
	reDraw(g, tetr);
	
	
}

void CG_4_Kolos::Form3d::reDraw(Graphics ^ g, Tetrahedron * t)
{
	g->Clear(Color::White);
	for (int i = 0; i < 3; i++)
	{
		//Vector3d res = v.WordldToScreen(pictureBox->Width, pictureBox->Height);
		g->DrawLine(Pens::Black, int(t->Display[3].x), int(t->Display[3].y), int(t->Display[i].x), int(t->Display[i].y));
		g->DrawLine(Pens::Black, int(t->Display[i].x), int(t->Display[i].y), int(t->Display[i + 1].x), int(t->Display[i + 1].y));
	}
	g->DrawLine(Pens::Black, int(t->Display[0].x), int(t->Display[0].y), int(t->Display[2].x), int(t->Display[2].y));

	g->DrawEllipse(Pens::Green, (int)t->PivotDisplay.x, (int)t->PivotDisplay.y, 5, 5);
	//g->DrawEllipse(Pens::Magenta, pictureBox->Width / 2, pictureBox->Height / 2, 20, 20);

	pictureBox->Refresh();
}
