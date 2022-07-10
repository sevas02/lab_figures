#ifndef ISOSCELES_TRIANGLE 
#define ISOSCELES_TRIANGLE 

#include "Figure.h"

//прямоугольный треугольник
class Isoscelec_triangle : public Figure {
public:
	//конструктор по умолчанию
	Isoscelec_triangle();

	//конструктор треугольника через два катета
	Isoscelec_triangle(double a, double b, double ang_c);

	//печать параметров прямоугольного треугольника
	void print() override;

	//нахождение периметра
	double perimeter();

	//нахождение площади
	double square();

	//деструктор
	~Isoscelec_triangle();

	//геттеры
	double get_side_a() { return side_a; }
	double get_side_b() { return side_b; }
	double get_base() { return base; }
	double get_angle_a() { return angle_a; }
	double get_angle_b() { return angle_b; }
	double get_angle_c() { return angle_c; }
protected:
	//стороны
	double side_a;
	double side_b;
	double base;
	//углы
	double angle_a;
	double angle_b;
	double angle_c;
};

#endif // RIGHT_TRIANGLE
