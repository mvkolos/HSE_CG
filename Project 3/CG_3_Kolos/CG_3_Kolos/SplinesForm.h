#pragma once
#include "Utils.h"
namespace CG_3_Kolos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	/// <summary>
	/// —водка дл€ SplinesForm
	/// </summary>
	public ref class SplinesForm : public System::Windows::Forms::Form
	{
	public:
		SplinesForm(void)
		{
			InitializeComponent();
			bm = gcnew Bitmap(pictureBox->Width, pictureBox->Height);
			pictureBox->Image = bm;
			pictureBox->Invalidate();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~SplinesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBoxDebug;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox;
	protected:
		void Bezier(System::Drawing::Graphics ^g);
		void CubicBezier(System::Drawing::Graphics ^g, int offset);
		void ComposedBezier(System::Drawing::Graphics ^g);
		void ContinueLine();

		

		System::Collections::Generic::List<Point> points;
		System::Collections::Generic::List<Point> bezier;
		Bitmap ^bm;	
		int pointCount = 0;;
		float** CubicMatrix = new float*[4]{
			new float[4]{ 1,-3,3,-1 },
			new float[4]{ 0,3,-6,3 },
			new float[4]{ 0,0,3,-3 },
			new float[4]{ 0,0,0,1 } };
		
	private:
		
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBoxDebug = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(16, 5);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(450, 450);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			this->pictureBox->Click += gcnew System::EventHandler(this, &SplinesForm::pictureBox_Click);
			this->pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &SplinesForm::pictureBox_MouseDown);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(494, 92);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SplinesForm::button1_Click);
			// 
			// textBoxDebug
			// 
			this->textBoxDebug->Location = System::Drawing::Point(481, 150);
			this->textBoxDebug->Name = L"textBoxDebug";
			this->textBoxDebug->Size = System::Drawing::Size(100, 20);
			this->textBoxDebug->TabIndex = 2;
			// 
			// SplinesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 461);
			this->Controls->Add(this->textBoxDebug);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox);
			this->Name = L"SplinesForm";
			this->Text = L"SplinesForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Graphics^ g = Graphics::FromImage(bm);
		
		
		pictureBox->Invalidate();
	}
	private: System::Void pictureBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		pointCount++;
		Point p = pictureBox->PointToClient(Cursor->Position);
		points.Add(p);
		Graphics^ g = Graphics::FromImage(bm);
		g->DrawEllipse(Pens::Gray, p.X, p.Y, 3, 3);
		if (pointCount > 3 && pointCount % 2 == 0)
		{
			ContinueLine();
		}
		if (pointCount % 4 == 0) {
			ComposedBezier(g);
		}
		
		textBoxDebug->Text = (pointCount%4).ToString();
		pictureBox->Invalidate();
	}
};
}
