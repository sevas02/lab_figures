#ifndef FUNCTIONS
#define FUNCTIONS
#include "Figure.h"
#include "List.h"
#include "right_triangle.h"
#include "right_triangle_prism.h"
#include <fstream>

//считывает все данные из файла в список
void func1(std::ifstream& fin, list<figure*> &figures);

//вывод всех фигур из списка
void func2(list<figure*> figures);

//находит треугольник с минимальным углом и средний объем призм
void func3(right_triangle* min_triangle, double& vol, list<figure*> figures);

#endif // FUNCTIONS

