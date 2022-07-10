#include "right_triangle_prism.h"

//конструктор с параметром для призмы, передаётся треуг-ник в основании и высота призмы
right_triangle_prism::right_triangle_prism(right_triangle triangle, double h) {
	height = h;
	leg_a = triangle.get_leg_a();
	leg_b = triangle.get_leg_b();
	hypotenuse = triangle.get_hypotenuse();
	angle_a = triangle.get_angle_a();
	angle_b= triangle.get_angle_b();
	angle_c = triangle.get_angle_c();
}

//вычисление площади пов-ти призмы
double right_triangle_prism::square() {
	double s_bok = right_triangle::perimeter() * height;
	return s_bok + (2 * 0.5 * leg_a * leg_b);;
}

//вычисление объёма призмы
double right_triangle_prism::volume() {
	return right_triangle::square() * height;
}

//вывод параметров призмы
void right_triangle_prism::print() {
	SetColor(3, 0);
	std::cout << "\nPrism\n";
	SetColor(7, 0);
	std::cout << "Triangle at the base:\n";
	right_triangle::print();
	std::cout << "\nHeight: " << std::fixed
		<< std::setprecision(3) << height;
	std::cout << "\nPrism surface area: " << square();
	std::cout << "\nPrism volume: " << volume();
}

//деструктор
right_triangle_prism::~right_triangle_prism() {
	leg_a = 0;
	leg_b = 0;
	hypotenuse = 0;
	angle_a = 0;
	angle_b = 0;
	angle_c = 0;
	height = 0;
}