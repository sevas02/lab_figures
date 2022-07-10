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
	
	//считывание данных из файла
	while (!fin.eof()) {
		fin >> type;
		if (type == 0) {
			int a, b, angle;
			fin >> a >> b >> angle;
			try {
				right_triangle* temp_tr = new right_triangle(a, b, angle);
				figures.push_back(temp_tr);
			}
			catch (std::string exception) {
				std::cout << exception << std::endl;
			}
		} else if (type == 1) {
			int a, b, angle, h;
			fin >> a >> b >> angle >> h;
			try {
				right_triangle* temp_tr = new right_triangle(a, b, angle);
				right_triangle_prism* temp_pr = new right_triangle_prism(*temp_tr, h);
				figures.push_back(temp_pr);
			}
			catch (std::string exception) {
				std::cout << exception << std::endl;
			}
		}
		else
			std::cout << "Unrecognized type of figure!\n";
	}

	//вывод всех фигур из списка
	for (int i = 0; i < figures.get_size(); i++) {
		figures.find_value(i)->print();
		std::cout << std::endl;
	}
	right_triangle* min_triangle = new right_triangle();
	double avg_value_pr = 0;
	//третья функция
	for (int i = 0; i < figures.get_size(); i++) {
		//счетчик призм
		int count_pr = 0;
		//общий объём призм
		double general_volume_pr = 0;
		//треугольник с минимальным углом
	//	right_triangle* min_triangle = new right_triangle();
		//переменная для инициализации миним-ого треугольника
		bool first_tr = true;
		if (typeid(*(figures.find_value(i))) == typeid(right_triangle)) {
			if (first_tr)
				min_triangle = dynamic_cast<right_triangle*>(figures.find_value(i));
			else if (dynamic_cast<right_triangle*>(figures.find_value(i)) < min_triangle)
				min_triangle = dynamic_cast<right_triangle*>(figures.find_value(i));
		}
		else if (typeid(*(figures.find_value(i))) == typeid(right_triangle_prism)) {
			count_pr++;
			general_volume_pr += dynamic_cast<right_triangle_prism*>(figures.find_value(i))->volume();
			//средний объём призм сраных
			avg_value_pr = general_volume_pr / count_pr;
		}
		
	}
	std::cout << std::endl << std::endl;
	min_triangle->print();
	std::cout << avg_value_pr << std::endl;

	/*right_triangle my_tr(3, 4);
	my_tr.print();

	right_triangle_prism my_pr(my_tr, 4);
	my_pr.print();*/
	fin.close();
	fout.close();
	return 0;
} 