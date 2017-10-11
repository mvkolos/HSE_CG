/*Колос Мария
БПИ 141
Проект 3. Сплайны
Visual Studio 2017 Community, Windows 10
Реализация кривых Безье (n-мерной, кубической, составной)
Реализация алгоритма Костельжо*/


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
	/// Сводка для SplinesForm
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SplinesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonClose;
	private: System::Windows::Forms::CheckBox^  checkBoxAlg;
	protected:

	private: System::Windows::Forms::Button^  buttonClear;
	private: System::Windows::Forms::CheckBox^  checkBoxComposed;
	private: System::Windows::Forms::Button^  buttonBezier;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;




	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox;
	protected:
		void NBezier(System::Drawing::Graphics ^g);
		void Bezier(System::Drawing::Graphics ^g);
		void CubicBezier(System::Drawing::Graphics ^g, int offset);
		void ComposedBezier(System::Drawing::Graphics ^g);
		void ContinueLine();
		void CloseBezier(System::Drawing::Graphics ^ g);
		void drawBezier(System::Drawing::Graphics ^ g);
		void BezierDeCasteljau(System::Drawing::Graphics^ g);
		void clear();
		

		float deCasteljauX(int i, int j, float t);
		float deCasteljauY(int i, int j, float t);

		System::Collections::Generic::List<Point> points;
		System::Collections::Generic::List<Point> closure;
		System::Collections::Generic::List<Point> bezier;
		
		Bitmap ^bm;	
		int pointCount = 0;
		bool deCasteljau = false;
		bool composed = false;
		float** CubicMatrix = new float*[4]{
			new float[4]{ 1,-3,3,-1 },
			new float[4]{ 0,3,-6,3 },
			new float[4]{ 0,0,3,-3 },
			new float[4]{ 0,0,0,1 } };
		
	private:
		
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->checkBoxAlg = (gcnew System::Windows::Forms::CheckBox());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->checkBoxComposed = (gcnew System::Windows::Forms::CheckBox());
			this->buttonBezier = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox->Location = System::Drawing::Point(12, 55);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(450, 450);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			this->pictureBox->Click += gcnew System::EventHandler(this, &SplinesForm::pictureBox_Click);
			this->pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &SplinesForm::pictureBox_MouseDown);
			// 
			// buttonClose
			// 
			this->buttonClose->Location = System::Drawing::Point(481, 136);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(100, 23);
			this->buttonClose->TabIndex = 1;
			this->buttonClose->Text = L"close";
			this->buttonClose->UseVisualStyleBackColor = true;
			this->buttonClose->Click += gcnew System::EventHandler(this, &SplinesForm::button1_Click);
			// 
			// checkBoxAlg
			// 
			this->checkBoxAlg->AutoSize = true;
			this->checkBoxAlg->Location = System::Drawing::Point(481, 175);
			this->checkBoxAlg->Name = L"checkBoxAlg";
			this->checkBoxAlg->Size = System::Drawing::Size(69, 17);
			this->checkBoxAlg->TabIndex = 2;
			this->checkBoxAlg->Text = L"Casteljau";
			this->checkBoxAlg->UseVisualStyleBackColor = true;
			this->checkBoxAlg->CheckedChanged += gcnew System::EventHandler(this, &SplinesForm::checkBoxAlg_CheckedChanged);
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(481, 55);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(100, 23);
			this->buttonClear->TabIndex = 3;
			this->buttonClear->Text = L"clear";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &SplinesForm::buttonClear_Click);
			// 
			// checkBoxComposed
			// 
			this->checkBoxComposed->AutoSize = true;
			this->checkBoxComposed->Location = System::Drawing::Point(481, 212);
			this->checkBoxComposed->Name = L"checkBoxComposed";
			this->checkBoxComposed->Size = System::Drawing::Size(75, 17);
			this->checkBoxComposed->TabIndex = 4;
			this->checkBoxComposed->Text = L"composed";
			this->checkBoxComposed->UseVisualStyleBackColor = true;
			this->checkBoxComposed->CheckedChanged += gcnew System::EventHandler(this, &SplinesForm::checkBoxComposed_CheckedChanged);
			// 
			// buttonBezier
			// 
			this->buttonBezier->Location = System::Drawing::Point(481, 98);
			this->buttonBezier->Name = L"buttonBezier";
			this->buttonBezier->Size = System::Drawing::Size(100, 23);
			this->buttonBezier->TabIndex = 5;
			this->buttonBezier->Text = L"bezier";
			this->buttonBezier->UseVisualStyleBackColor = true;
			this->buttonBezier->Click += gcnew System::EventHandler(this, &SplinesForm::buttonBezier_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(608, 24);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->aboutToolStripMenuItem->Text = L"about";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &SplinesForm::aboutToolStripMenuItem_Click);
			// 
			// SplinesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(608, 517);
			this->Controls->Add(this->buttonBezier);
			this->Controls->Add(this->checkBoxComposed);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->checkBoxAlg);
			this->Controls->Add(this->buttonClose);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"SplinesForm";
			this->Text = L"SplinesForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Graphics^ g = Graphics::FromImage(bm);
		if (pointCount > 3)
		{
			CloseBezier(g);
		}
		/*
		BezierDeCasteljau(g);
		pictureBox->Invalidate();*/
	}
	private: System::Void pictureBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		pointCount++;
		Point p = pictureBox->PointToClient(Cursor->Position);
		points.Add(p);
		Graphics^ g = Graphics::FromImage(bm);
		g->DrawEllipse(Pens::Gray, p.X, p.Y, 3, 3);
		if (composed)
		{
			if (pointCount > 3 && pointCount % 2 == 0)
			{
				ContinueLine();
				ComposedBezier(g);
			}
			
		}
		
		
		//textBoxDebug->Text = (readyToClose).ToString();
		pictureBox->Invalidate();
	}

private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e) 
{
	clear();
}
		 
private: System::Void checkBoxAlg_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	deCasteljau = !deCasteljau;
}
private: System::Void checkBoxComposed_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	composed = !composed;
}
private: System::Void buttonBezier_Click(System::Object^  sender, System::EventArgs^  e) {
	clear();
	NBezier(Graphics::FromImage(bm));
}

private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	String ^text = "Колос Мария Владимировна, БПИ141\n11.10.17" +
		"\nПроект 3. Сплайны" +
		"\nVisual Studio 2017 Community, Windows 10" +
		"\nРеализация кривых Безье (n-мерной, кубической, составной)" +
		"\nРеализация алгоритма Костельжо";
	MessageBox::Show(text, "О программе", MessageBoxButtons::OK,
		MessageBoxIcon::Asterisk);
}
};
}
