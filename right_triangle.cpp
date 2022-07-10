#include "right_triangle.h"
#define PI 3.14159265   

//конструктор по умолчанию
right_triangle::right_triangle() : angle_c(90) {
	leg_a = 0;
	leg_b = 0;
	hypotenuse = 0;
	angle_b = 0;
	angle_a = 0;
}

//конструктор треугольника через два катета
right_triangle::right_triangle(double a, double b, double angl) {
	if (angl > 90)
		throw "Error! The angle value exceeds the allowable!\n";
	if (angl == 90) {
		angle_c = angl;
		leg_a = a;
		leg_b = b;
		hypotenuse = sqrt(leg_a * leg_a + leg_b * leg_b - 2 * leg_a * leg_b * cos(angle_c * PI / 180));
		angle_b = atan(leg_b / leg_a) * 180 / PI;
		angle_a = angle_c - angle_b;
	}
	else {

	}
}

//печать параметров прямоугольного треугольника
void right_triangle::print() {
	std::cout << "Гипотенуза: " << std::fixed
		<< std::setprecision(3) << hypotenuse;
	std::cout << "\nПервый катет 'a': " << std::fixed
		<< std::setprecision(3) << leg_a;
	std::cout << "\nВторой катет 'b': " << std::fixed
		<< std::setprecision(3) << leg_b;
	std::cout << "\nУгол 'c': " << std::fixed
		<< std::setprecision(3) << angle_c;
	std::cout << "\nУгол 'a': " << std::fixed
		<< std::setprecision(3) << angle_a;
	std::cout << "\nУгол 'b': " << std::fixed
		<< std::setprecision(3) << angle_b;
	std::cout << "\n";
	std::cout << "\nПериметр треугольника: " << perimeter();
	std::cout << "\nПлощадь треугольника: " << square();
}

//нахождение периметра
double right_triangle::perimeter() {
	return leg_a + leg_b + hypotenuse;
}

//нахождение площади
double right_triangle::square() {
	return 0.5 * leg_a * leg_b;
}

//деструктор
right_triangle::~right_triangle() {
	leg_a = 0;
	leg_b = 0;
	hypotenuse = 0;
	angle_a = 0;
	angle_b = 0;
	angle_c = 0;
}
