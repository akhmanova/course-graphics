#pragma once

namespace Akhmanova {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	float default_lines[] = {
		// ������
		0.5f,3.f,1.f,4.5f, // �� ����� ���� ����� �� ���
		1.f,4.5f,0.5f,6.f, // ����� ��� ����� ����� �����
		0.5f,6.f,0.5f, 7.5f, // ����� ��� �����
		0.5f, 7.5f,1.f,8.f, // ����� ��� ���� �����
		1.f,8.f,1.5f,8.f, // ����� ��� ���� ��������
		1.5f,8.f,2.f,7.5f, // ����� ��� ���� ������
		2.f,7.5f,1.5f, 6.f, // ����� ��� ������ ������ ����
		1.5f, 6.f,1.5f,4.5f, // ����� ��� ������ �� �������
		1.5f,4.5f,3.f,4.5f, // �������
		3.f,4.5f,3.f,6.f, // ������ ��� ����� ����� �����
		3.f,6.f,2.5f,7.5f, // ������ ��� �����
		2.5f,7.5f,3.f,8.f, // ������ ��� ���� �����
		3.f,8.f,3.5f,8.f, // ������ ��� ���� ��������
		3.5f,8.f,4.f,7.5f, // ������ ��� ���� ������
		4.f,7.5f,4.f,6.f, // ������ ��� ������ ����
		4.f,6.f,3.5f,4.5f, // ������ ��� ������
		3.5f,4.5f,4.f,3.f, // �� ������� ��� ���� �� ����
		4.f,3.f,3.5f,1.5f, // ������ �����
		3.5f,1.5f,2.5f,1.f, // ���������� ������
		2.5f,1.f,2.f,1.f, // ���������� �����
		2.f,1.f,1.f,1.5f, // ���������� �����
		1.f,1.5f,0.5f,3.f, // ����� �����
		// ��������
		4.f,3.f,5.5f,3.5f, // ����� �� ������ ������
		5.5f,3.5f,7.f,3.5f, // ����� ����
		7.f,3.5f,7.5f,2.5f, // ����� ������ �� ������
		7.5f,2.5f,8.f,2.5f, // ����� ������
		8.f,2.5f,8.f,2.f, // ����� ������
		8.f,2.f,7.5f,2.f, // ����� ��� ������ ������
		7.5f,2.f,7.5f,0.5f, // ������ ���� ������ ������ ����
		7.5f,0.5f,6.5f,0.5f, // ������ ���� ���
		6.5f,0.5f,6.5f,1.f, // ������ ���� �����
		6.5f,1.f,6.f,1.f, // ����� ������ ���
		6.f,1.f,6.f,0.5f, // ����� ������ ���� ������
		6.f,0.5f,5.f,0.5f, // ����� ������ ���� ���
		5.f,0.5f,5.f,1.f, // ����� ������ ���� �����
		5.f,1.f,4.f,1.f, // ����� ������� � ��������� ������
		4.f,1.f,4.f,0.5f, // ������ �������� ���� ������
		4.f,0.5f,3.f,0.5f, // ������ �������� ���� ���
		3.f,0.5f,3.f,1.f, // ������ �������� ���� �����
		3.f,1.f,2.5f,1.f, // ����� �������� ���
		2.5f,1.f,2.5f,0.5f, // �������� ���� ������
		2.5f,0.5f,1.5f,0.5f, // �������� ���� ���
		1.5f,0.5f,1.5f,1.25f, // �������� ���� �����
		// ����� ����
		1.5f,3.5f,1.5f,3.f, // ����� ���� ����� ������ ����
		1.5f,3.f,2.f,3.f, // ����� ���� ���
		2.f, 3.f,2.f,3.5f, // ����� ���� ������
		2.f,3.5f,1.5f,3.5f, // ����� ���� ����
		// ������ ����
		2.5f,3.5f,2.5f,3.f, // ������ ���� �����
		2.5f,3.f,3.f, 3.f, // ������ ���� �����
		3.f,3.f,3.f,3.5f, // ������ ���� ������
		3.f,3.5f,2.5f,3.5f, // ������ ���� ������
		// ����� ��������
		1.f,5.5f,1.f,7.f, // ����� ����� ��������
		3.5f,5.5f,3.5f,7.f, // ������ ����� ��������
		// ���
		2.f,2.5f,2.5f,2.5f, // ��� ������
		2.5f,2.5f,2.25f,2.f, // ��� ������
		2.25f,2.f,2.f,2.5f // ��� �����
	};
	unsigned int default_arrayLength = sizeof(default_lines) / sizeof(float); // ����� �������
	float default_Vx = 8.5f; // ������ ������� �� �����������
	float default_Vy = 8.5f; // ������ ������� �� ���������
	// ����������� ������ �������
	float default_aspectFig = default_Vx / default_Vy;	float cat_lines[] = {
		//�����
		//������ �������
		4.5f,1.f,5.f,0.5f,
		5.f,0.5f,5.5f,0.5f,
		5.5f,0.5f,6.f,1.f,
		//������
		4.75f,1.f,5.f,0.75f,
		5.f,0.75f,5.5f,0.75f,
		5.5f,0.75f,5.75f,1.f,
		//����
		6.f,1.f,4.f,1.f,
		4.f,1.f,3.f,1.5f,
		//������ ���
		3.8f,1.89f,3.5f,2.5f,
		3.5f,2.5f,4.f,3.f,
		4.f,3.f,4.5f,2.5f,
		//���
		3.5f,1.75f,3.5f,1.25f,
		//����
		3.f,1.5f,4.f,2.f,
		4.f,2.f,5.f,3.f,
		//����
		//�����
		5.f,3.5f,5.f,2.5f,
		5.f,2.5f,5.5f,2.5f,
		5.5f,2.5f,5.5f,3.5f,
		//�����
		4.5f,3.5f,6.f,3.5f,
		6.f,3.5f,6.5f,4.f,
		6.5f,4.f,6.f,4.5f,
		6.f,4.5f,5.5f,4.f,
		5.5f,4.f,5.f,4.f,
		5.f,4.f,4.5f,4.5f,
		4.5f,4.5f,4.f,4.f,
		4.f,4.f,4.5f,3.5f,
		//����
		5.5f,3.f,6.5f,2.5f,
		//�����
		6.5f,2.5f,7.f,4.f,
		//����
		6.5f,2.5f,6.5f,2.f,
		//����
		4.f,2.f,4.5f,2.f,
		4.5f,2.f,4.5f,1.5f,
		4.5f,1.5f,4.f,1.5f,
		4.f,1.5f,4.f,2.f,
		//����� ���
		5.f,1.5f,5.5f,1.f,
		5.5f,1.f,6.f,2.f,
		6.f,2.f,5.5f,2.5f,
		5.5f,2.5f,4.85f,2.2f,
		//�����
		//�������� ������ ����
		1.f,1.f,0.5f,1.f,
		0.5f,1.f,0.5f,1.5f,
		0.5f,1.5f,1.5f,2.5f,
		1.5f,2.5f,2.5f,4.f,
		//������
		1.5f,1.5f,1.f,1.5f,
		1.f,1.5f,1.7f,2.f,
		//�������� ����� ����
		4.f,4.5f,2.5f,1.5f,
		2.5f,1.5f,2.5f,0.5f,
		2.5f,0.5f,1.f,0.5f,
		1.f,0.5f,1.f,1.f,
		1.f,1.f,1.5f,1.5f,
		1.5f,1.5f,2.5f,4.f,
		2.5f,4.f,2.5f,4.66f,
		//������
		2.5f,1.f,1.5f,1.f,
		1.5f,1.f,2.5f,1.5f,
		2.75f,2.f,2.f,2.f,
		2.f,2.f,3.f,2.5f,
		3.25f,3.f,2.5f,3.f,
		2.5f,3.f,3.5f,3.5f,
		3.75f,4.f,2.5f,3.5f,
		2.5f,3.5f,4.f,4.5f,
		//�����
		4.f,4.5f,4.5f,5.f,
		4.5f,5.f,5.5f,5.5f,
		5.5f,5.5f,6.f,5.5f,
		6.f,5.5f,7.f,5.f,
		//������ ������ ����
		7.f,5.f,7.5f,3.5f,
		7.5f,3.5f,7.f,2.f,
		7.f,2.f,6.5f,2.f,
		6.5f,2.f,6.f,1.5f,
		6.f,1.5f,6.f,1.f,
		6.f,1.f,6.5f,1.f,
		//������
		7.85f,2.5f,7.5f,2.5f,
		7.5f,2.5f,8.f,3.f,
		//������ ����� ����
		7.f,5.f,7.5f,4.5f,
		7.5f,4.5f,8.f,3.f,
		8.f,3.f,7.5f,1.5f,
		7.5f,1.5f,7.f,1.5f,
		7.f,1.5f,6.5f,1.f,
		6.5f,1.f,6.5f,0.5f,
		6.5f,0.5f,8.5f,0.5f,
		8.5f,0.5f,8.5f,1.5f,
		8.5f,1.5f,9.f,3.f,
		9.f,3.f,8.5f,6.5f,
		8.5f,6.5f,8.f,7.5f,
		//������
		8.5f,1.5f,8.f,1.5f,
		8.f,1.5f,8.66f,2.f,
		8.84f,2.5f,8.f,2.5f,
		8.f,2.5f,9.f,3.f,
		8.94f,3.5f,8.f,3.5f,
		8.f,3.5f,8.86f,4.f,
		8.78f,4.5f,8.f,4.5f,
		8.f,4.5f,8.71f,5.f,
		8.71f,5.f,7.5f,5.5f,
		7.5f,5.5f,8.64f,5.5f,
		8.56f,6.f,7.f,6.f,
		7.f,6.f,8.5f,6.5f,
		8.25f,7.f,7.f,7.f,
		7.f,7.f,8.f,7.5f,
		//�����
		8.f,7.5f,9.f,9.f,
		9.f,9.f,8.5f,11.f,
		8.5f,11.f,8.f,12.f,
		8.f,12.f,7.f,12.5f,
		7.f,12.5f,5.5f,13.f,
		5.5f,13.f,5.f,13.f,
		5.f,13.f,3.5f,12.f,
		3.5f,12.f,4.f,11.5f,
		4.f,11.5f,5.f,12.f,
		5.f,12.f,6.f,12.f,
		6.f,12.f,7.f,11.5f,
		7.f,11.5f,7.5f,11.f,
		7.5f,11.f,8.f,9.f,
		8.f,9.f,7.5f,8.5f,
		//������
		9.f,9.f,8.f,8.5f,
		8.f,8.5f,8.88f,9.5f,
		8.62f,10.5f,8.f,10.f,
		8.f,10.f,8.5f,11.f,
		8.f,12.f,8.f,11.f,
		8.f,11.f,7.5f,12.25f,
		7.f,12.5f,7.f,12.f,
		7.f,12.f,6.5f,12.66f,
		5.5f,13.f,6.f,12.f,
		6.f,12.f,5.f,13.f,
		4.f,12.33f,5.f,12.f,
		5.f,12.f,3.5f,12.f,
		//�����
		7.5f,8.5f,6.5f,9.5f,
		6.5f,9.5f,4.5f,9.5f,
		4.5f,9.5f,3.5f,8.5f,
		3.5f,8.5f,3.f,7.5f,
		//������
		7.5f,8.5f,7.f,8.f,
		7.f,8.f,6.5f,7.f,
		6.5f,7.f,6.5f,8.f,
		6.5f,8.f,7.f,9.f,
		6.5f,9.5f,6.f,7.f,
		6.f,7.f,6.f,9.5f,
		5.5f,9.5f,5.5f,6.5f,
		5.5f,6.5f,5.f,9.5f,
		4.5f,9.5f,5.f,7.f,
		5.f,7.f,4.f,9.f,
		3.5f,8.5f,4.f,8.f,
		4.f,8.f,4.5f,7.f,
		4.5f,7.f,4.f,7.5f,
		4.f,7.5f,3.25f,8.f,
		//������
		3.5f,5.f,2.f,4.5f,
		2.f,4.5f,1.5f,4.5f,
		1.5f,4.5f,1.f,5.f,
		1.f,5.f,1.f,5.5f,
		1.f,5.5f,1.5f,6.5f,
		1.5f,6.5f,2.f,7.f,
		2.f,7.f,3.f,7.5f,
		3.f,7.5f,3.5f,7.5f,
		3.5f,7.5f,4.f,7.f,
		4.f,7.f,4.f,6.5f,
		4.f,6.5f,3.5f,5.f,
		//����� ���
		1.f,5.5f,0.5f,7.f,
		0.5f,7.f,1.5f,6.5f,
		//����� ��������
		1.5f,6.5f,1.f,6.5f,
		1.f,6.5f,1.f,5.5f,
		//������ ���
		2.f,7.f,1.5f,8.f,
		1.5f,8.f,3.f,7.5f,
		//����� ��������
		3.f,7.5f,2.f,7.5f,
		2.f,7.5f,2.f,7.f,
		//����� ����
		1.5f,5.5f,1.5f,6.f,
		1.5f,6.f,2.f,6.f,
		2.f,6.f,2.f,5.5f,
		2.f,5.5f,1.5f,5.5f,
		//������
		1.5f,6.f,1.75,5.5f,
		1.5f,6.f,2.f,5.75f,
		//������ ����
		2.5f,6.5f,2.5f,7.f,
		2.5f,7.f,3.f,7.f,
		3.f,7.f,3.f,6.5f,
		3.f,6.5f,2.5f,6.5f,
		//������
		2.5f,7.f,2.75f,6.5f,
		2.5f,7.f,3.f,6.75f,
		//���
		2.5f,5.5f,3.f,6.f,
		3.f,6.f,3.f,5.5f,
		3.f,5.5f,2.5f,5.5f,
		//��� ����
		2.5f,5.5f,0.5f,4.5f,
		2.5f,5.5f,1.f,4.f,
		2.5f,5.5f,1.5f,3.5f,
		//��� �����
		3.f,6.f,4.f,8.f,
		3.f,6.f,4.5f,7.5f,
		3.f,6.f,5.f,7.f,
		//���
		2.5f,5.f,3.f,5.f,
		3.f,5.f,3.f,5.5f,
		3.f,5.5f,3.5f,5.5f,
		3.5f,5.5f,3.5f,6.f,
		//������
		1.f,5.f,1.5f,5.5f,
		1.5f,5.5f,1.f,5.5f,
		1.5f,6.5f,2.f,6.f,
		2.f,6.f,2.f,6.5f,
		2.f,6.5f,2.5f,6.5f,
		2.5f,6.5f,2.f,7.f,
		3.5f,7.5f,3.f,7.f,
		3.f,7.f,3.f,7.5f,
	};
	unsigned int cat_arrayLength = sizeof(cat_lines) / sizeof(float); // ����� �������
	float cat_Vx = 9.5f; // ������ ������� �� �����������
	float cat_Vy = 13.5f; // ������ ������� �� ���������
					 // ����������� ������ �������
	float cat_aspectFig = cat_Vx / cat_Vy;
	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->DoubleBuffered = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: bool keepAspectRatio; // �������� - ��������� �� ����������� ������ �������?
			 bool image = true;
			 float *lines, arrayLength, Vx, Vy, aspectFig;
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::DarkKhaki);

		Pen^ blackPen = gcnew Pen(Color::Black, 2);

		float Wx = ClientRectangle.Width; // ������ ���� �� �����������
		float Wy = ClientRectangle.Height; // ������ ���� �� ���������

		float aspectForm = Wx / Wy; // ����������� ������ ���� ���������
		float Sx, Sy;
		if (keepAspectRatio) {
			// �����������s ���������� ��� ���������� ��������� ����������� ������
			Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
		}
		else {
			Sx = Wx / Vx; // ����������� ���������� �� ��� Ox
			Sy = Wy / Vy; // ����������� ���������� �� ��� Oy
		}
		float Ty = Sy * Vy; // �������� � ������������� ������� �� ��� Oy ����� ����� �����
		for (int i = 0; i < arrayLength; i += 4) {
			g->DrawLine(blackPen, Sx * lines[i], Ty - Sy * lines[i + 1], Sx * lines[i + 2], Ty - Sy * lines[i + 3]);
		}
	}
	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		Refresh();
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		keepAspectRatio = true; // ��������� ��������: ��������� ����������� ������ �������
		//����� ������������� �����������
		Vx = default_Vx;
		Vy = default_Vy;
		arrayLength = default_arrayLength;
		lines = default_lines;
		aspectFig = default_aspectFig;
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode) {
		case Keys::M:
			keepAspectRatio = !keepAspectRatio;
			break;
		case Keys::N: {
			if (image) {
				Vx = cat_Vx;
				Vy = cat_Vy;
				arrayLength = cat_arrayLength;
				lines = cat_lines;
				aspectFig = cat_aspectFig;
				image = !image;
			}
			else {
				Vx = default_Vx;
				Vy = default_Vy;
				arrayLength = default_arrayLength;
				lines = default_lines;
				aspectFig = default_aspectFig;
				image = !image;
			}
			break;
		}
		default:
			break;
		}
		Refresh();
	}
	};
}
