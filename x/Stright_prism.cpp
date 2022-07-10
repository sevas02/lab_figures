#include "Stright_prism.h"

//конструктор с параметром для призмы, передаётся треуг-ник в основании и высота призмы
Stright_prism::Stright_prism(Isoscelec_triangle triangle, double h) {
	height = h;
	side_a = triangle.get_side_a();
	side_b = triangle.get_side_b();
	base = triangle.get_base();
	angle_a = triangle.get_angle_a();
	angle_b= triangle.get_angle_b();
	angle_c = triangle.get_angle_c();
}

//вычисление площади пов-ти призмы
double Stright_prism::square() {
	double s_bok = Isoscelec_triangle::perimeter() * height;
	return s_bok + (2 * 0.5 * side_a * side_b);;
}

//вычисление объёма призмы
double Stright_prism::volume() {
	return Isoscelec_triangle::square() * height;
}

//вывод параметров призмы
void Stright_prism::print() {
	std::cout << "\n\nТреугольник в основании:\n";
	Isoscelec_triangle::print();
	std::cout << "\n";
	std::cout << "\nВысота призмы: " << std::fixed
		<< std::setprecision(1) << height;
	std::cout << "\nПлощадь пов-ти призмы: " << square();
	std::cout << "\nОбъём призмы: " << volume();
}

//деструктор
Stright_prism::~Stright_prism() {
	side_a = 0;
	side_b = 0;
	base = 0;
	angle_a = 0;
	angle_b = 0;
	angle_c = 0;
	height = 0;
}