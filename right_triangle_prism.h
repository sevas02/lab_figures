#ifndef RIGHT_TRIANGLE_PRISM
#define RIGHT_TRIANGLE_PRISM
#include "right_triangle.h"
#include "text_color.h"

class right_triangle_prism : public right_triangle {
public:
	//����������� � ���������� ��� ������, ��������� �����-��� � ��������� � ������ ������
	right_triangle_prism(right_triangle triangle, double h);

	//���������� ������� ���-�� ������
	double square();
	
	//���������� ������ ������
	double volume();

	//����� ���������� ������
	void print() override;

	//����������
	~right_triangle_prism();
private:
	double height;
};

#endif // RIGHT_TRIANGLE_PRISM

