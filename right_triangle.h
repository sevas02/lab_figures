#ifndef RIGHT_TRIANGLE 
#define RIGHT_TRIANGLE 

#include "Figure.h"

//прямоугольный треугольник
class right_triangle : public figure {
public:
	//конструктор по умолчанию
	right_triangle();

	//конструктор треугольника через два катета
	right_triangle(double a, double b, double angl);

	//печать параметров прямоугольного треугольника
	void print() override;

	//нахождение периметра
	double perimeter();

	//нахождение площади
	double square();

	//деструктор
	~right_triangle();

	//геттеры
	double get_leg_a() { return leg_a; }
	double get_leg_b() { return leg_b; }
	double get_hypotenuse() { return hypotenuse; }
	double get_angle_a() { return angle_a; }
	double get_angle_b() { return angle_b; }
	double get_angle_c() { return angle_c; }
protected:
	//катеты
	double leg_a;
	double leg_b;
	//гипотенуза
	double hypotenuse;
	//углы
	double angle_a;
	double angle_b;
	double angle_c;
};

#endif // RIGHT_TRIANGLE
