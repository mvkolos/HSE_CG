#pragma once
#include "Shape.h"
namespace CG_4_Kolos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form3d
	/// </summary>
	public ref class Form3d : public System::Windows::Forms::Form
	{
	public:
		const float RAD_TO_DEG = 57.2958;
		const float DEG_TO_RAD = 0.0174533;
	public:
		Bitmap ^bm;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::CheckBox^  checkBoxPerspective;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Debug;
	private: System::Windows::Forms::Button^  buttonMirrorX;
	private: System::Windows::Forms::Button^  buttonMirrorY;
	private: System::Windows::Forms::Button^  buttonMirrorZ;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBoxX;
	private: System::Windows::Forms::TextBox^  textBoxY;
	private: System::Windows::Forms::TextBox^  textBoxZ;
	private: System::Windows::Forms::Button^  button4;


	public:
		Tetrahedron* tetr;
		void Rotate();
		void reDraw(Graphics^ g,Tetrahedron* t);
		//Shape cube;
		Form3d(void)
		{
			InitializeComponent();
			bm = gcnew Bitmap(pictureBox->Width, pictureBox->Height);
			pictureBox->Image = bm;
			Graphics ^g = Graphics::FromImage(bm);
			Shape tetrahedron = Shape();
			tetr = new Tetrahedron();
		}
		
		
	protected:
		int axis=0;
		int oldAngle = 0;
		
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form3d()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox;



	private: System::Windows::Forms::TrackBar^  trackBarZ;
	private: System::Windows::Forms::TrackBar^  trackBarR;
	private: System::Windows::Forms::Button^  buttonAxis;

	protected:

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
			this->trackBarZ = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarR = (gcnew System::Windows::Forms::TrackBar());
			this->buttonAxis = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBoxPerspective = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Debug = (gcnew System::Windows::Forms::TextBox());
			this->buttonMirrorX = (gcnew System::Windows::Forms::Button());
			this->buttonMirrorY = (gcnew System::Windows::Forms::Button());
			this->buttonMirrorZ = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBoxX = (gcnew System::Windows::Forms::TextBox());
			this->textBoxY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxZ = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarZ))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarR))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->BackColor = System::Drawing::SystemColors::HighlightText;
			this->pictureBox->Location = System::Drawing::Point(203, 47);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(500, 500);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			this->pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form3d::pictureBox_MouseDown);
			// 
			// trackBarZ
			// 
			this->trackBarZ->Location = System::Drawing::Point(12, 83);
			this->trackBarZ->Minimum = 1;
			this->trackBarZ->Name = L"trackBarZ";
			this->trackBarZ->Size = System::Drawing::Size(168, 45);
			this->trackBarZ->TabIndex = 4;
			this->trackBarZ->Value = 10;
			this->trackBarZ->Scroll += gcnew System::EventHandler(this, &Form3d::trackBarZ_Scroll);
			// 
			// trackBarR
			// 
			this->trackBarR->Location = System::Drawing::Point(2, 177);
			this->trackBarR->Maximum = 180;
			this->trackBarR->Name = L"trackBarR";
			this->trackBarR->Size = System::Drawing::Size(168, 45);
			this->trackBarR->TabIndex = 5;
			this->trackBarR->Value = 10;
			this->trackBarR->Scroll += gcnew System::EventHandler(this, &Form3d::trackBarR_Scroll);
			// 
			// buttonAxis
			// 
			this->buttonAxis->Location = System::Drawing::Point(21, 218);
			this->buttonAxis->Name = L"buttonAxis";
			this->buttonAxis->Size = System::Drawing::Size(26, 23);
			this->buttonAxis->TabIndex = 6;
			this->buttonAxis->Text = L"x";
			this->buttonAxis->UseVisualStyleBackColor = true;
			this->buttonAxis->Click += gcnew System::EventHandler(this, &Form3d::buttonAxis_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(51, 282);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 21);
			this->button1->TabIndex = 7;
			this->button1->Text = L"translate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form3d::button1_Click);
			// 
			// checkBoxPerspective
			// 
			this->checkBoxPerspective->AutoSize = true;
			this->checkBoxPerspective->Location = System::Drawing::Point(51, 38);
			this->checkBoxPerspective->Name = L"checkBoxPerspective";
			this->checkBoxPerspective->Size = System::Drawing::Size(82, 17);
			this->checkBoxPerspective->TabIndex = 8;
			this->checkBoxPerspective->Text = L"Perspective";
			this->checkBoxPerspective->UseVisualStyleBackColor = true;
			this->checkBoxPerspective->CheckedChanged += gcnew System::EventHandler(this, &Form3d::checkBoxPerspective_CheckedChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(75, 218);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(26, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"y";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form3d::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(129, 218);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(26, 23);
			this->button3->TabIndex = 10;
			this->button3->Text = L"z";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form3d::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(72, 161);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Rotate";
			this->label1->Click += gcnew System::EventHandler(this, &Form3d::label1_Click);
			// 
			// Debug
			// 
			this->Debug->Location = System::Drawing::Point(97, 515);
			this->Debug->Name = L"Debug";
			this->Debug->Size = System::Drawing::Size(100, 20);
			this->Debug->TabIndex = 12;
			this->Debug->Visible = false;
			this->Debug->TextChanged += gcnew System::EventHandler(this, &Form3d::Debug_TextChanged);
			// 
			// buttonMirrorX
			// 
			this->buttonMirrorX->Location = System::Drawing::Point(51, 336);
			this->buttonMirrorX->Name = L"buttonMirrorX";
			this->buttonMirrorX->Size = System::Drawing::Size(75, 23);
			this->buttonMirrorX->TabIndex = 13;
			this->buttonMirrorX->Text = L"MirrorX";
			this->buttonMirrorX->UseVisualStyleBackColor = true;
			this->buttonMirrorX->Click += gcnew System::EventHandler(this, &Form3d::buttonMirrorX_Click);
			// 
			// buttonMirrorY
			// 
			this->buttonMirrorY->Location = System::Drawing::Point(51, 365);
			this->buttonMirrorY->Name = L"buttonMirrorY";
			this->buttonMirrorY->Size = System::Drawing::Size(75, 23);
			this->buttonMirrorY->TabIndex = 14;
			this->buttonMirrorY->Text = L"MirrorY";
			this->buttonMirrorY->UseVisualStyleBackColor = true;
			this->buttonMirrorY->Click += gcnew System::EventHandler(this, &Form3d::buttonMirrorY_Click);
			// 
			// buttonMirrorZ
			// 
			this->buttonMirrorZ->Location = System::Drawing::Point(51, 394);
			this->buttonMirrorZ->Name = L"buttonMirrorZ";
			this->buttonMirrorZ->Size = System::Drawing::Size(75, 23);
			this->buttonMirrorZ->TabIndex = 15;
			this->buttonMirrorZ->Text = L"MirrorZ";
			this->buttonMirrorZ->UseVisualStyleBackColor = true;
			this->buttonMirrorZ->Click += gcnew System::EventHandler(this, &Form3d::buttonMirrorZ_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(72, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Zoom";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(715, 24);
			this->menuStrip1->TabIndex = 17;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form3d::aboutToolStripMenuItem_Click);
			// 
			// textBoxX
			// 
			this->textBoxX->Location = System::Drawing::Point(21, 456);
			this->textBoxX->Name = L"textBoxX";
			this->textBoxX->Size = System::Drawing::Size(38, 20);
			this->textBoxX->TabIndex = 18;
			// 
			// textBoxY
			// 
			this->textBoxY->Location = System::Drawing::Point(75, 456);
			this->textBoxY->Name = L"textBoxY";
			this->textBoxY->Size = System::Drawing::Size(38, 20);
			this->textBoxY->TabIndex = 19;
			// 
			// textBoxZ
			// 
			this->textBoxZ->Location = System::Drawing::Point(129, 456);
			this->textBoxZ->Name = L"textBoxZ";
			this->textBoxZ->Size = System::Drawing::Size(38, 20);
			this->textBoxZ->TabIndex = 20;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(51, 482);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 21;
			this->button4->Text = L"Scale";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form3d::button4_Click);
			// 
			// Form3d
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(715, 559);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBoxZ);
			this->Controls->Add(this->textBoxY);
			this->Controls->Add(this->textBoxX);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonMirrorZ);
			this->Controls->Add(this->buttonMirrorY);
			this->Controls->Add(this->buttonMirrorX);
			this->Controls->Add(this->Debug);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->checkBoxPerspective);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->buttonAxis);
			this->Controls->Add(this->trackBarR);
			this->Controls->Add(this->trackBarZ);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form3d";
			this->Text = L"Form3d";
			this->Load += gcnew System::EventHandler(this, &Form3d::Form3d_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarZ))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarR))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void updButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 Rotate();
	}
private: System::Void trackBarZ_Scroll(System::Object^  sender, System::EventArgs^  e) 
{
	 Rotate();
}
private: System::Void trackBarR_Scroll(System::Object^  sender, System::EventArgs^  e) {
	 Rotate();
}
private: System::Void trackBarRUp_Scroll(System::Object^  sender, System::EventArgs^  e) {
	 Rotate();
}
private: System::Void buttonAxis_Click(System::Object^  sender, System::EventArgs^  e) 
{
	axis = 0;
}
private: System::Void Form3d_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	tetr->translate = !tetr->translate;
}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void checkBoxPerspective_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	tetr->perspective = checkBoxPerspective->Checked;
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	axis = 1;
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	axis = 2;
}
private: System::Void pictureBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
	Debug->Text = "vv";
	if (tetr->translate)
	{
		Graphics ^g = Graphics::FromImage(bm);
		Point pos = pictureBox->PointToClient(Cursor->Position);
		Vector3d location = Vector3d(pos.X, pos.Y, 0).ScreenToWorld(pictureBox->Width, pictureBox->Height);
		tetr->transform.Translate(location);
		tetr->ApplyTranslation();
		tetr->RecomputeProjection(trackBarZ->Value, pictureBox->Width, pictureBox->Height);
		reDraw(g, tetr);
		
	}
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Debug_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void buttonMirrorX_Click(System::Object^  sender, System::EventArgs^  e) 
{
	tetr->transform.MirrorX();
	tetr->ApplyMirror();
	tetr->RecomputeProjection(trackBarZ->Value, pictureBox->Width, pictureBox->Height);
	Graphics ^g = Graphics::FromImage(bm);
	reDraw(g, tetr);
}
private: System::Void buttonMirrorY_Click(System::Object^  sender, System::EventArgs^  e) {
	tetr->transform.MirrorY();
	tetr->ApplyMirror();
	tetr->RecomputeProjection(trackBarZ->Value, pictureBox->Width, pictureBox->Height);
	Graphics ^g = Graphics::FromImage(bm);
	reDraw(g, tetr);
}
private: System::Void buttonMirrorZ_Click(System::Object^  sender, System::EventArgs^  e) {
	tetr->transform.MirrorZ();
	tetr->ApplyMirror();
	tetr->RecomputeProjection(trackBarZ->Value, pictureBox->Width, pictureBox->Height);
	Graphics ^g = Graphics::FromImage(bm);
	reDraw(g, tetr);
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	String ^text = "Колос Мария Владимировна, БПИ141\n25.10.17" +
		"\nПроект 4. Тетраэдр" +
		"\nVisual Studio 2017 Community, Windows 10" +
		"\nРеализация представления 3D-фигуры";
	MessageBox::Show(text, "О программе", MessageBoxButtons::OK,
		MessageBoxIcon::Asterisk);
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	int x = System::Int32::Parse(textBoxX->Text);
	int y = System::Int32::Parse(textBoxY->Text);
	int z = System::Int32::Parse(textBoxZ->Text);

	tetr->transform.Scale(Vector3d(x, y, z));
	tetr->ApplyScale();
	tetr->RecomputeProjection(trackBarZ->Value, pictureBox->Width, pictureBox->Height);
	Graphics ^g = Graphics::FromImage(bm);
	reDraw(g, tetr);
}
};
}
