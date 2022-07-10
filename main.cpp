#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Figure.h"
#include "right_triangle.h"
#include "right_triangle_prism.h"
#include "List.h"

int main() {
	setlocale(0, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	// 0 - треугольник, 1 - призма
	int type;
	list<figure*> figures;
	
	while (!fin.eof()) {
		fin >> type;
		if (type == 0) {
			int a, b;
			fin >> a >> b;
			right_triangle* temp_tr = new right_triangle(a, b);
		    figures.push_back(temp_tr);
		}
		if (type == 1) {
			int a, b, h;
			fin >> a >> b >> h;
			right_triangle* temp_tr = new right_triangle(a, b);
			right_triangle_prism* temp_pr = new right_triangle_prism(*temp_tr, h);
			figures.push_back(temp_pr);
		}
		else
			std::cout << "Unrecognized type of figure!\n";
	}


	/*right_triangle my_tr(3, 4);
	my_tr.print();

	right_triangle_prism my_pr(my_tr, 4);
	my_pr.print();*/

	return 0;
} 