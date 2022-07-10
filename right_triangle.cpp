#include "right_triangle.h"
#include <string>
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
		throw std::string("Error! The angle value exceeds the allowable!\n");
	if (angl == 90) {
		angle_c = angl;
		leg_a = a;
		leg_b = b;
		hypotenuse = sqrt(leg_a * leg_a + leg_b * leg_b - 2 * leg_a * leg_b * cos(angle_c * PI / 180));
		angle_b = atan(leg_b / leg_a) * 180 / PI;
		angle_a = angle_c - angle_b;
	}
	else {
		angle_a = angl;
		angle_c = 90;
		hypotenuse = a;
		leg_b = b;
		leg_a = sqrt(hypotenuse * hypotenuse + leg_b * leg_b - 2 * hypotenuse * leg_b * cos(angle_a * PI / 180));
		angle_b = angle_c - angle_a;
	}
	if (hypotenuse <= leg_a || hypotenuse <= leg_b)
		throw std::string("Error! Hypotenuse is not a big side!\n");
	if (leg_a + leg_b < hypotenuse
		|| leg_a + hypotenuse < leg_b
		|| leg_b + hypotenuse < leg_a)
		throw std::string("Error! Еriangle inequality violated!\n");
}

//печать параметров прямоугольного треугольника
void right_triangle::print() {
	SetColor(14, 0);
	std::cout << "Triangle\n";
	SetColor(7, 0);
	std::cout << "Hypotenuse: " << std::fixed
		<< std::setprecision(3) << hypotenuse;
	std::cout << "\nLeg 'a': " << std::fixed
		<< std::setprecision(3) << leg_a;
	std::cout << "\nLeg 'b': " << std::fixed
		<< std::setprecision(3) << leg_b;
	std::cout << "\nAngle 'c': " << std::fixed
		<< std::setprecision(3) << angle_c;
	std::cout << "\nAngle 'a': " << std::fixed
		<< std::setprecision(3) << angle_a;
	std::cout << "\nAngle 'b': " << std::fixed
		<< std::setprecision(3) << angle_b;
	std::cout << "\n";
	std::cout << "\nTriangle perimeter: " << perimeter();
	std::cout << "\nTriangle square: " << square() << "\n";
}

//нахождение периметра
double right_triangle::perimeter() {
	return leg_a + leg_b + hypotenuse;
}

//нахождение площади
double right_triangle::square() {
	return 0.5 * leg_a * leg_b;
}

//нахождение минимального угла
double right_triangle::minimal_angle() const {
	if (angle_a > angle_b)
		return angle_b;
	else
		return angle_a;
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

bool right_triangle::operator <(const right_triangle& tr) {
	if (minimal_angle() < tr.minimal_angle())
		return true;
	return false;
}

void right_triangle::operator =(const right_triangle& tr) {
	angle_a = tr.angle_a;
	angle_b = tr.angle_b;
	angle_c = tr.angle_c;
	leg_a = tr.leg_a;
	leg_b = tr.leg_b;
	hypotenuse = tr.hypotenuse;
}

