#pragma once

namespace Akhmanova {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	vec3 Vc; // координаты дальнего левого нижнего угла
	vec3 V; // размеры параллелепипеда в пространстве графика
	vec3 Vc_work, V_work; // рабочие параметры параллелепипеда
	mat4 T; // матрица, в которой накапливаются все преобразования
	mat4 initT; // матрица начального преобразования

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
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
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
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->MinimumSize = System::Drawing::Size(155, 120);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: float left = 30, right = 100, top = 20, bottom = 50; // расстояния до границ окна
			 float minX = left, maxX; // диапазон изменения координат x
			 float minY = top, maxY; // диапазон изменения координат y
			 float Wcx = left, Wcy; // координаты левого нижнего угла прямоугольника
			 float Wx, Wy; // ширина и высота прямоугольника
			 float Wx_work, Wy_work; // ширина и высота области вывода одной линии графика
			 float Wx_part = 0.6, Wy_part = 0.6; // доля Wx_work, Wy_work от Wx, Wy соответственно
			 float Wcx_work, Wcy_work; // координаты левого нижнего угла самого дальнего прямоугольника
			 float Wz_work; // количество рабочих прямоугольников
			 int numXsect = 5, numYsect = 5, numZsect = 5; // количество секций координатной сетки по осям
			 float Wx_coefficient = 0.05f, Wy_coefficient = 0.05f; // коэффициент увеличения / уменьшения размеров рабочего прямоугольника
	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; // диапазон изменения координат x
		maxY = ClientRectangle.Height - bottom; // диапазон изменения координат y
		Wcy = maxY; // координаты левого нижнего угла прямоугольника
		Wx = maxX - left; // ширина прямоугольника
		Wy = maxY - top; // ширина и высота прямоугольника
		Wx_work = Wx_part * Wx; // вычисление ширины и высоты
		Wy_work = Wy_part * Wy; // рабочего прямоугольника
		Wcx_work = maxX - Wx_work; // вычисление координат нижнего левого
		Wcy_work = minY + Wy_work; // угла самого дальнего рабочего прямоугольника
		Wz_work = Wcy - Wcy_work; // количество рабочих прямоугольников
	}
	private: System::Void worldRectCalc() {
		Vc_work = normalize(T * vec4(Vc, 1.f));
		V_work = mat3(T) * V;
	}
	private: float f(float x, float z) {
		return x * sin(sqrtf(x * x + z * z));
	}
	private: bool f_exists(float x, float z, float delta) {
		return true;
	}
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::DarkKhaki);

		Pen^ rectPen = gcnew Pen(Color::Black, 2);
		g->DrawRectangle(rectPen, left, top, Wx, Wy);

		// ВЫЧЕРЧИВАНИЕ КООРДИНАТНОЙ СЕТКИ
		Pen^ gridPen = gcnew Pen(Color::Black, 1);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 8);

		// координатная сетка по x
		float gridStep_x = Wx_work / numXsect; // расстояние между линиями сетки по x
		float grid_dX = V_work.x / numXsect; // расстояние между линиями сетки по x в мировых координатах
		float tick_x = Vc_work.x; // значение соответствующее первой линии сетки
		for (int i = 0; i <= numXsect; i++) { // цикл по количеству линий
			float tmpXCoord_d = Wcx + i * gridStep_x; // нижняя координата x i-й диагональной линии
			float tmpXCoord_v = Wcx_work + i * gridStep_x; // координата x i-й вертикальной линии
														   // i-я диагональная линия
			g->DrawLine(gridPen, tmpXCoord_d, Wcy, tmpXCoord_v, Wcy_work);
			// i-я вертикальная линия
			g->DrawLine(gridPen, tmpXCoord_v, Wcy_work, tmpXCoord_v, minY);
			if (i > 0 && i < numXsect) // если линия не крайняя
				// выводим текст в нижней точке диагональной линии
				g->DrawString(tick_x.ToString("F4"), drawFont, drawBrush, tmpXCoord_d, Wcy);
			tick_x += grid_dX; // вычисляем значение, соответствующее следующей линии
		}

		// координатная сетка по z
		gridStep_x = (Wx - Wx_work) / numZsect; // расстояние между вертикальными линиями сетки по горизонтали
		float gridStep_y = Wz_work / numZsect; // расстояние между горизонтальными линиями сетки по вертикали
		float grid_dZ = V_work.z / numZsect; // расстояние между линиями сетки по $z$ в мировых координатах
		float tick_z = Vc_work.z; // значение, соответствующее первой линии сетки
		for (int i = 0; i <= numZsect; i++) { // цикл по количеству линий
			float tmpXCoord_v = Wcx_work - i * gridStep_x; // координата x вертикальных линий
			float tmpYCoord_g = Wcy_work + i * gridStep_y; // координата y горизонтальных линий
			float tmpXCoord_g = tmpXCoord_v + Wx_work; // вторая координата x горизонтальных линий
			// i-я вертикальная линия
			g->DrawLine(gridPen, tmpXCoord_v, tmpYCoord_g, tmpXCoord_v, tmpYCoord_g - Wy_work);
			// i-я горизонтальная линия
			g->DrawLine(gridPen, tmpXCoord_v, tmpYCoord_g, tmpXCoord_g, tmpYCoord_g);
			if (i > 0 && i < numZsect) // если линия не крайняя
									   // выводим текст в правой точке горизонтальной линии
				g->DrawString(tick_z.ToString("F4"), drawFont, drawBrush, tmpXCoord_g, tmpYCoord_g);
			tick_z += grid_dZ; // вычисляем значение, соответствующее следующей линии
		}		// координатная сетка по y
		float gridStep_z = Wy_work / numYsect; // расстояние между горизонтальными линиями сетки по вертикали
		float grid_dY = V_work.y / numYsect; // расстояние между линиями сетки по $y$ в мировых координатах
		float tick_y = Vc_work.y; // значение, соответствующее первой линии сетки
		for (int i = 0; i <= numYsect; i++) { // цикл по количеству линий
			float tmpXCoord_d = Wcy - i * gridStep_z; // нижняя координата y i-й диагональной линии
			float tmpXCoord_v = Wcy_work - i * gridStep_z; // координата y i-й горизонтальной линии
			// i-я диагональная линия
			g->DrawLine(gridPen, Wcx, tmpXCoord_d, Wcx_work, tmpXCoord_v);
			// i-я горизонтальная линия
			g->DrawLine(gridPen, Wcx_work, tmpXCoord_v, maxX, tmpXCoord_v);
			if (i > 0 && i < numYsect) // если линия не крайняя
									   // выводим текст в правой точке горизонтальной линии
				g->DrawString(tick_y.ToString("F4"), drawFont, drawBrush, maxX, tmpXCoord_v);
			tick_y += grid_dY; // вычисляем значение, соответствующее следующей линии
		}		/*ВЫЧИСЛЕНИЕ РАЗМЕРОВ РАБОЧЕГО ПРЯМОУГОЛЬНИКА*/		float Wx_work_resize = Wx_work * Wx_coefficient;		float Wy_work_resize = Wy_work * Wy_coefficient;		/*границы рабочего прямоугольнкиа*/		float minX_resize = Wcx_work + Wx_work_resize;
		float minY_resize = minY + Wy_work_resize;
		float maxX_resize = maxX - Wx_work_resize;
		float maxY_resize = Wcy_work - Wy_work_resize;
		// ОТРИСОВКА ГРАФИКА
		Pen^ pen = gcnew Pen(Color::Blue, 1);
		float deltaX = V_work.x / Wx_work; // шаг по x в мировых координатах
		float deltaZ = V_work.z / Wz_work; // шаг по z в мировых координатах

		float deltaWcx = (Wcx_work - Wcx) / Wz_work; // шаг прямоугольников по x в координатах экрана

		bool hasStart;

		// цикл по прямоугольникам
		float z = Vc_work.z; // координата z наиболее удаленных точек графика
		// координаты левого нижнего угла рабочего прямоугольника (инициализация)
		float Wcx_w = Wcx_work, Wcy_w = Wcy_work;
		while (Wcy_w <= Wcy) { // пока не перебрали все прямоугольники
			vec2 start, end; // точка начала отрезка в координатах экрана
			float x, y; // переменные для координат точки в мировой СК
			start.x = Wcx_w; // для начальной точки первого отрезка устанавливаем координату x
			x = Vc_work.x; // координата x начальной точки первого отрезка в мировых координатах
			hasStart = f_exists(x, z, deltaX);
			if (hasStart) {
				y = f(x, z); // координата y начальной точки в мировых координатах
						  // вычисляем соответствующее значение в координатах экрана
				start.y = Wcy_w - (y - Vc_work.y) / V_work.y * Wy_work;
			}			float maxX = Wcx_w + Wx_work; 			while (start.x < maxX) {
				vec2 end;// точка конца отрезка в координатах экрана
				bool hasEnd;
				float deltaY; // высота точки в прямоугольнике (доля общей высоты)
				float red, green, blue; // компоненты цвета отрезка
				end.x = start.x + 1.f; // координата x отличается на единицу
				x += deltaX; // координата x конечной точки отрезка в мировых координатах
				hasEnd = f_exists(x, z, deltaX);
				if (hasEnd) {
					y = f(x, z); // координата y начальной точки в мировых координатах
							  // вычисляем соответствующее значение в координатах экрана
							  // вычисляем соответствующее значение в координатах экрана
					deltaY = (y - Vc_work.y) / V_work.y;
					end.y = Wcy_w - deltaY * Wy_work;
				}
				vec2 tmpEnd = end;
				bool visible = hasStart && hasEnd && clip(start, end, minX_resize, minY_resize, maxX_resize, maxY_resize);
				if (visible) { // если отрезок видим
							   // после отсечения, start и end - концы видимой части отрезка
					// ВЫЧИЧЛЕНИЕ ЦВЕТА ОТРЕЗКА
					if (deltaY > 1.f) deltaY = 1.f; // нормализуем значение высоты точки
					if (deltaY < 0.f) deltaY = 0.f; // на случай, если отрезок отсекался
					green = 510.f * deltaY; // предварительное вычисление произведения
					if (deltaY < 0.5) { // если точка ниже середины области видимости
										// компонента зеленого уже вычислена
						blue = 255.f - green; // синий дополняет зеленый
						red = 0.f; // красный равен нулю
					}
					else { // если точка не ниже середины
						blue = 0.f; // синий равен нулю
						red = green - 255.f; // вычисляем красный и зеленый
						green = 510.f - green; // с использованием вычисленного произведения
					}
					pen->Color = Color::FromArgb(red, green, blue); // меняем цвет пера
					// отрисовка отрезка
					g->DrawLine(pen, start.x, start.y, end.x, end.y); // отрисовка видимых частей
				}
				// конечная точка неотсеченного отрезка становится начальной точкой следующего
				start = tmpEnd;				hasStart = hasEnd;
			}
			Wcy_w += 1.f; // переходим к следующему прямоугольнику, он будет ниже на один пиксел
			Wcx_w -= deltaWcx; // и левее на некоторое значение
			z += deltaZ; // вычисляем соответствующее значение z для очередного прямоугольника
			// смещение рабочего прямоугольника
			minX_resize -= deltaWcx;
			minY_resize += 1.f;
			maxX_resize -= deltaWcx;
			maxY_resize += 1.f;
		}
	}
	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		rectCalc();
		Refresh();
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		Vc = vec3(-2.f, -2.f, -2.f);
		V = vec3(4.f, 4.f, 4.f);
		initT = mat4(1.f);
		T = initT;
		rectCalc();
		worldRectCalc();
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		float centerX = Vc_work.x + V_work.x / 2; // координаты центра прямоугольника
		float centerY = Vc_work.y + V_work.y / 2; // в мировой системе координат
		float centerZ = Vc_work.z + V_work.z / 2;
		switch (e->KeyCode) {
		case Keys::Escape:
			T = initT;
			break;
		case Keys::A:
			T = translate(-V_work.x / Wx, 0.f, 0.f) * T; // сдвиг графика вправо на один пиксел
			break;
		case Keys::D:
			T = translate(V_work.x / Wx, 0.f, 0.f) * T; // сдвиг графика вправо на один пиксел
			break;
		case Keys::W:
			T = translate(0.f, 0.f, -V_work.x / Wx) * T; // сдвиг графика назад на один пиксел
			break;
		case Keys::S:
			T = translate(0.f, 0.f, V_work.x / Wx) * T; // сдвиг графика вперед на один пиксел
			break;
		case Keys::R:
			T = translate(0.f, -V_work.x / Wx, 0.f) * T; // сдвиг графика вниз на один пиксел
			break;
		case Keys::F:
			T = translate(0.f, V_work.x / Wx, 0.f) * T; // сдвиг графика вверх на один пиксел
			break;
		case Keys::Z:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1.1, 1.1, 1.1) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::X:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(0.9, 0.9, 0.9) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::Q:
			if (Wx_coefficient > 0.1) {
				Wx_coefficient -= 0.05;
			}
			break;
		case Keys::E:
			if (Wx_coefficient < 0.4) {
				Wx_coefficient += 0.05;
			}
			break;
		case Keys::C:
			if (Wy_coefficient > 0.1) {
				Wy_coefficient -= 0.05;
			}
			break;
		case Keys::V:
			if (Wy_coefficient < 0.4) {
				Wy_coefficient += 0.05;
			}
			break;
		case Keys::T:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1.1, 1, 1) * T; // масштабирование Ox
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::G:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(0.9, 1, 1) * T; // масштабирование Ox
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::Y:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1, 1.1, 1) * T; // масштабирование Oy
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::H:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1, 0.9, 1) * T; // масштабирование Oy
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::U:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1, 1, 1.1) * T; // масштабирование Oz
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::J:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1, 1, 0.9) * T; // масштабирование Oz
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;
		case Keys::D1:
			numXsect++; //увеличение количества секций координатной сетки по оси Ox
			break;
		case Keys::D2:
			if (numXsect > 2) //уменьшение количества секций координатной сетки по оси Ox
				numXsect--;
			break;
		case Keys::D3:
			numYsect++; //увеличение количества секций координатной сетки по оси Oy
			break;
		case Keys::D4:
			if (numYsect > 2) //уменьшение количества секций координатной сетки по оси Oy
				numYsect--;
			break;
		case Keys::D5:
			numZsect++; //увеличение количества секций координатной сетки по оси Oz
			break;
		case Keys::D6:
			if (numZsect > 2) //уменьшение количества секций координатной сетки по оси Oz
				numZsect--;
			break;
		default:
			break;
		}
		worldRectCalc();
		Refresh();
	}
};
}
