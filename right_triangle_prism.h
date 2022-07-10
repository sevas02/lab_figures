#ifndef RIGHT_TRIANGLE_PRISM
#define RIGHT_TRIANGLE_PRISM
#include "right_triangle.h"
#include "text_color.h"

class right_triangle_prism : public right_triangle {
public:
	//конструктор с параметром для призмы, передаётся треуг-ник в основании и высота призмы
	right_triangle_prism(right_triangle triangle, double h);

	//вычисление площади пов-ти призмы
	double square();
	
	//вычисление объёма призмы
	double volume();

	//вывод параметров призмы
	void print() override;

	//деструктор
	~right_triangle_prism();
private:
	double height;
};

#endif // RIGHT_TRIANGLE_PRISM

