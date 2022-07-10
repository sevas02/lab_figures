#include "functions.h"

//считывает все данные из файла в список
void func1(std::ifstream& fin, list<figure*> &figures) {
	// 0 - треугольник, 1 - призма
	int type;
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
		}
		else if (type == 1) {
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
}

//вывод всех фигур из списка
void func2(list<figure*> figures) {
	for (int i = 0; i < figures.get_size(); i++) {
		figures.find_value(i)->print();
		std::cout << std::endl;
	}
}

//находит треугольник с минимальным углом и средний объем призм
void func3(right_triangle* min_triangle, double& vol, list<figure*> figures) {
	for (int i = 0; i < figures.get_size(); i++) {
		//счетчик призм
		int count_pr = 0;
		//общий объём призм
		double general_volume_pr = 0;
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
			//средний объём призм
			vol = general_volume_pr / count_pr;
		}
	}
}