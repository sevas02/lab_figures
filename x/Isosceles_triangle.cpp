#include "Isosceles_triangle.h"
#define PI 3.14159265   

//конструктор по умолчанию
Isoscelec_triangle::Isoscelec_triangle() {
	side_a = 0;
	side_b = 0;
	base = 0;
	angle_a = 0;
	angle_b = 0;
	angle_c = 0;
}

//конструктор треугольника через боковые стороны и угол между ними
Isoscelec_triangle::Isoscelec_triangle(double a, double b, double ang_c) {
	side_a = a;
	side_b = b;	
	if (side_a != side_b)
		throw "error: Triangle does not meet the construction condition!\n";
	angle_c = ang_c;
	base = sqrt(side_a * side_a + side_b * side_b - 2 * side_a * side_b * cos(angle_c * PI / 180));
	angle_a = (180 - angle_c) / 2;
	angle_b = angle_a;

	if (angle_a + angle_b + angle_c < 0 || angle_a + angle_b + angle_c > 180)
		throw "error: Triangle sum of angles theorem!\n";
}

//печать параметров прямоугольного треугольника
void Isoscelec_triangle::print() {
	std::cout << "Основание: " << std::fixed
		<< std::setprecision(1) << base;
	std::cout << "\nБоковая сторона a: " << std::fixed
		<< std::setprecision(1) << side_a;
	std::cout << "\nБоковая сторона b: " << std::fixed
		<< std::setprecision(1) << side_b;
	std::cout << "\nУгол a: " << std::fixed
		<< std::setprecision(1) << angle_a;
	std::cout << "\nУгол b: " << std::fixed
		<< std::setprecision(1) << angle_b;
	std::cout << "\nУгол c: " << std::fixed
		<< std::setprecision(1) << angle_c;
	std::cout << "\n";
	std::cout << "\nПериметр треугольника: " << std::fixed
		<< std::setprecision(1) << perimeter();
	std::cout << "\nПлощадь треугольника: " << std::fixed
		<< std::setprecision(1) << square();
}

//нахождение периметра
double Isoscelec_triangle::perimeter() {
	return side_a + side_b + base;
}

//нахождение площади
double Isoscelec_triangle::square() {
	//полупериметр
	double p = perimeter() / 2;
	return sqrt(p * (p - side_a) * (p - side_b) * (p - base));
}

//деструктор
Isoscelec_triangle::~Isoscelec_triangle() {
	side_a = 0;
	side_b = 0;
	base = 0;
	angle_a = 0;
	angle_b = 0;
	angle_c = 0;
}
