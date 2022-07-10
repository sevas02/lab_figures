#include <iostream>
#include "Figure.h"
#include "Isosceles_triangle.h"
#include "Stright_prism.h"

int main() {
	setlocale(0, "RUS");

	Isoscelec_triangle triangle(2, 2, 50);
	triangle.print();

	Stright_prism prism(triangle, 4);
	prism.print();

	return 0;
}