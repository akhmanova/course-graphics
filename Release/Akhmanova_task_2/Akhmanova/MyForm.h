#pragma once

namespace Akhmanova {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	float default_lines[] = {
		// голова
		0.5f,3.f,1.f,4.5f, // от левой щеки вверх до уха
		1.f,4.5f,0.5f,6.f, // левое ухо слева снизу вверх
		0.5f,6.f,0.5f, 7.5f, // левое ухо слева
		0.5f, 7.5f,1.f,8.f, // левое ухо верх слева
		1.f,8.f,1.5f,8.f, // левое ухо верх середина
		1.5f,8.f,2.f,7.5f, // левое ухо верх справа
		2.f,7.5f,1.5f, 6.f, // левое ухо справа сверху вниз
		1.5f, 6.f,1.5f,4.5f, // левое ухо справа до макушки
		1.5f,4.5f,3.f,4.5f, // макушка
		3.f,4.5f,3.f,6.f, // правое ухо слева снизу вверх
		3.f,6.f,2.5f,7.5f, // правое ухо слева
		2.5f,7.5f,3.f,8.f, // правое ухо верх слева
		3.f,8.f,3.5f,8.f, // правое ухо верх середина
		3.5f,8.f,4.f,7.5f, // правое ухо верх справа
		4.f,7.5f,4.f,6.f, // правое ухо сверху вниз
		4.f,6.f,3.5f,4.5f, // правое ухо справа
		3.5f,4.5f,4.f,3.f, // от правого уха вниз до щеки
		4.f,3.f,3.5f,1.5f, // правая скула
		3.5f,1.5f,2.5f,1.f, // подбородок справа
		2.5f,1.f,2.f,1.f, // подбородок снизу
		2.f,1.f,1.f,1.5f, // подбородок слева
		1.f,1.5f,0.5f,3.f, // левая скула
		// туловище
		4.f,3.f,5.5f,3.5f, // спина от головы вправо
		5.5f,3.5f,7.f,3.5f, // спина верх
		7.f,3.5f,7.5f,2.5f, // спина сверху до хвоста
		7.5f,2.5f,8.f,2.5f, // хвост сверху
		8.f,2.5f,8.f,2.f, // хвост справа
		8.f,2.f,7.5f,2.f, // хвост низ справа налево
		7.5f,2.f,7.5f,0.5f, // задняя нога справа сверху вниз
		7.5f,0.5f,6.5f,0.5f, // задняя нога низ
		6.5f,0.5f,6.5f,1.f, // задняя нога слева
		6.5f,1.f,6.f,1.f, // между задних ног
		6.f,1.f,6.f,0.5f, // левая задняя нога справа
		6.f,0.5f,5.f,0.5f, // левая задняя нога низ
		5.f,0.5f,5.f,1.f, // левая задняя нога слева
		5.f,1.f,4.f,1.f, // между задними и передними ногами
		4.f,1.f,4.f,0.5f, // правая передняя нога справа
		4.f,0.5f,3.f,0.5f, // правая передняя нога низ
		3.f,0.5f,3.f,1.f, // правая передняя нога слева
		3.f,1.f,2.5f,1.f, // между передних ног
		2.5f,1.f,2.5f,0.5f, // передняя нога справа
		2.5f,0.5f,1.5f,0.5f, // передняя нога низ
		1.5f,0.5f,1.5f,1.25f, // передняя нога слева
		// левый глаз
		1.5f,3.5f,1.5f,3.f, // левый глаз слева сверху вниз
		1.5f,3.f,2.f,3.f, // левый глаз низ
		2.f, 3.f,2.f,3.5f, // левый глаз справа
		2.f,3.5f,1.5f,3.5f, // левый глаз верх
		// правый глаз
		2.5f,3.5f,2.5f,3.f, // правый глаз слева
		2.5f,3.f,3.f, 3.f, // правый глаз снизу
		3.f,3.f,3.f,3.5f, // правый глаз справа
		3.f,3.5f,2.5f,3.5f, // правый глаз сверху
		// ушные раковины
		1.f,5.5f,1.f,7.f, // левая ушная раковина
		3.5f,5.5f,3.5f,7.f, // правая ушная раковина
		// нос
		2.f,2.5f,2.5f,2.5f, // нос сверху
		2.5f,2.5f,2.25f,2.f, // нос справа
		2.25f,2.f,2.f,2.5f // нос слева
	};
	unsigned int default_arrayLength = sizeof(default_lines) / sizeof(float); // длина массива
	float default_Vx = 8.5f; // размер рисунка по горизонтали
	float default_Vy = 8.5f; // размер рисунка по вертикали
	// соотношение сторон рисунка
	float default_aspectFig = default_Vx / default_Vy;	float cat_lines[] = {
		//мышка
		//колесо снаружи
		4.5f,1.f,5.f,0.5f,
		5.f,0.5f,5.5f,0.5f,
		5.5f,0.5f,6.f,1.f,
		//внутри
		4.75f,1.f,5.f,0.75f,
		5.f,0.75f,5.5f,0.75f,
		5.5f,0.75f,5.75f,1.f,
		//тело
		6.f,1.f,4.f,1.f,
		4.f,1.f,3.f,1.5f,
		//правое ухо
		3.8f,1.89f,3.5f,2.5f,
		3.5f,2.5f,4.f,3.f,
		4.f,3.f,4.5f,2.5f,
		//нос
		3.5f,1.75f,3.5f,1.25f,
		//тело
		3.f,1.5f,4.f,2.f,
		4.f,2.f,5.f,3.f,
		//ключ
		//ножка
		5.f,3.5f,5.f,2.5f,
		5.f,2.5f,5.5f,2.5f,
		5.5f,2.5f,5.5f,3.5f,
		//ручка
		4.5f,3.5f,6.f,3.5f,
		6.f,3.5f,6.5f,4.f,
		6.5f,4.f,6.f,4.5f,
		6.f,4.5f,5.5f,4.f,
		5.5f,4.f,5.f,4.f,
		5.f,4.f,4.5f,4.5f,
		4.5f,4.5f,4.f,4.f,
		4.f,4.f,4.5f,3.5f,
		//тело
		5.5f,3.f,6.5f,2.5f,
		//хвост
		6.5f,2.5f,7.f,4.f,
		//тело
		6.5f,2.5f,6.5f,2.f,
		//глаз
		4.f,2.f,4.5f,2.f,
		4.5f,2.f,4.5f,1.5f,
		4.5f,1.5f,4.f,1.5f,
		4.f,1.5f,4.f,2.f,
		//левое ухо
		5.f,1.5f,5.5f,1.f,
		5.5f,1.f,6.f,2.f,
		6.f,2.f,5.5f,2.5f,
		5.5f,2.5f,4.85f,2.2f,
		//кошка
		//передняя правая лапа
		1.f,1.f,0.5f,1.f,
		0.5f,1.f,0.5f,1.5f,
		0.5f,1.5f,1.5f,2.5f,
		1.5f,2.5f,2.5f,4.f,
		//полосы
		1.5f,1.5f,1.f,1.5f,
		1.f,1.5f,1.7f,2.f,
		//передняя левая лапа
		4.f,4.5f,2.5f,1.5f,
		2.5f,1.5f,2.5f,0.5f,
		2.5f,0.5f,1.f,0.5f,
		1.f,0.5f,1.f,1.f,
		1.f,1.f,1.5f,1.5f,
		1.5f,1.5f,2.5f,4.f,
		2.5f,4.f,2.5f,4.66f,
		//полосы
		2.5f,1.f,1.5f,1.f,
		1.5f,1.f,2.5f,1.5f,
		2.75f,2.f,2.f,2.f,
		2.f,2.f,3.f,2.5f,
		3.25f,3.f,2.5f,3.f,
		2.5f,3.f,3.5f,3.5f,
		3.75f,4.f,2.5f,3.5f,
		2.5f,3.5f,4.f,4.5f,
		//живот
		4.f,4.5f,4.5f,5.f,
		4.5f,5.f,5.5f,5.5f,
		5.5f,5.5f,6.f,5.5f,
		6.f,5.5f,7.f,5.f,
		//задняя правая лапа
		7.f,5.f,7.5f,3.5f,
		7.5f,3.5f,7.f,2.f,
		7.f,2.f,6.5f,2.f,
		6.5f,2.f,6.f,1.5f,
		6.f,1.5f,6.f,1.f,
		6.f,1.f,6.5f,1.f,
		//полосы
		7.85f,2.5f,7.5f,2.5f,
		7.5f,2.5f,8.f,3.f,
		//задняя левая лапа
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
		//полосы
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
		//хвост
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
		//полосы
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
		//спина
		7.5f,8.5f,6.5f,9.5f,
		6.5f,9.5f,4.5f,9.5f,
		4.5f,9.5f,3.5f,8.5f,
		3.5f,8.5f,3.f,7.5f,
		//полосы
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
		//голова
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
		//левое ухо
		1.f,5.5f,0.5f,7.f,
		0.5f,7.f,1.5f,6.5f,
		//ушная раковина
		1.5f,6.5f,1.f,6.5f,
		1.f,6.5f,1.f,5.5f,
		//правое ухо
		2.f,7.f,1.5f,8.f,
		1.5f,8.f,3.f,7.5f,
		//ушная раковина
		3.f,7.5f,2.f,7.5f,
		2.f,7.5f,2.f,7.f,
		//левый глаз
		1.5f,5.5f,1.5f,6.f,
		1.5f,6.f,2.f,6.f,
		2.f,6.f,2.f,5.5f,
		2.f,5.5f,1.5f,5.5f,
		//зрачок
		1.5f,6.f,1.75,5.5f,
		1.5f,6.f,2.f,5.75f,
		//правый глаз
		2.5f,6.5f,2.5f,7.f,
		2.5f,7.f,3.f,7.f,
		3.f,7.f,3.f,6.5f,
		3.f,6.5f,2.5f,6.5f,
		//зрачок
		2.5f,7.f,2.75f,6.5f,
		2.5f,7.f,3.f,6.75f,
		//нос
		2.5f,5.5f,3.f,6.f,
		3.f,6.f,3.f,5.5f,
		3.f,5.5f,2.5f,5.5f,
		//усы лево
		2.5f,5.5f,0.5f,4.5f,
		2.5f,5.5f,1.f,4.f,
		2.5f,5.5f,1.5f,3.5f,
		//усы право
		3.f,6.f,4.f,8.f,
		3.f,6.f,4.5f,7.5f,
		3.f,6.f,5.f,7.f,
		//рот
		2.5f,5.f,3.f,5.f,
		3.f,5.f,3.f,5.5f,
		3.f,5.5f,3.5f,5.5f,
		3.5f,5.5f,3.5f,6.f,
		//полосы
		1.f,5.f,1.5f,5.5f,
		1.5f,5.5f,1.f,5.5f,
		1.5f,6.5f,2.f,6.f,
		2.f,6.f,2.f,6.5f,
		2.f,6.5f,2.5f,6.5f,
		2.5f,6.5f,2.f,7.f,
		3.5f,7.5f,3.f,7.f,
		3.f,7.f,3.f,7.5f,
	};
	unsigned int cat_arrayLength = sizeof(cat_lines) / sizeof(float); // длина массива
	float cat_Vx = 9.5f; // размер рисунка по горизонтали
	float cat_Vy = 13.5f; // размер рисунка по вертикали
					 // соотношение сторон рисунка
	float cat_aspectFig = cat_Vx / cat_Vy;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
	private: bool keepAspectRatio; // значение - сохранять ли соотношение сторон рисунка?
			 bool image = true;
			 float *lines, arrayLength, Vx, Vy, aspectFig;
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::DarkKhaki);

		Pen^ blackPen = gcnew Pen(Color::Black, 2);

		float Wx = ClientRectangle.Width; // размер окна по горизонтали
		float Wy = ClientRectangle.Height; // размер окна по вертикали

		float aspectForm = Wx / Wy; // соотношение сторон окна рисования
		float Sx, Sy;
		if (keepAspectRatio) {
			// коэффициентs увеличения при сохранении исходного соотношения сторон
			Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
		}
		else {
			Sx = Wx / Vx; // коэффициент увеличения по оси Ox
			Sy = Wy / Vy; // коэффициент увеличения по оси Oy
		}
		float Ty = Sy * Vy; // смещение в положительную сторону по оси Oy после смены знака
		for (int i = 0; i < arrayLength; i += 4) {
			g->DrawLine(blackPen, Sx * lines[i], Ty - Sy * lines[i + 1], Sx * lines[i + 2], Ty - Sy * lines[i + 3]);
		}
	}
	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		Refresh();
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		keepAspectRatio = true; // начальное значение: сохранять соотношение сторон рисунка
		//вывод страндартного изображения
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
