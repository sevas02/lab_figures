#ifndef RIGHT_TRIANGLE 
#define RIGHT_TRIANGLE 

#include "Figure.h"
#include "text_color.h"

//������������� �����������
class right_triangle : public figure {
public:
	//����������� �� ���������
	right_triangle();

	//����������� ������������ ����� ��� ������
	right_triangle(double a, double b, double angl);

	//������ ���������� �������������� ������������
	void print() override;

	//���������� ���������
	double perimeter();

	//���������� �������
	double square();

	//���������� ������������ ����
	double minimal_angle() const;

	//����������
	~right_triangle();

	//�������
	double get_leg_a() { return leg_a; }
	double get_leg_b() { return leg_b; }
	double get_hypotenuse() { return hypotenuse; }
	double get_angle_a() { return angle_a; }
	double get_angle_b() { return angle_b; }
	double get_angle_c() { return angle_c; }

	//���������� ��������
	void operator =(const right_triangle& tr);
	bool operator <(const right_triangle& tr);

protected:
	//������
	double leg_a;
	double leg_b;
	//����������
	double hypotenuse;
	//����
	double angle_a;
	double angle_b;
	double angle_c;
};

#endif // RIGHT_TRIANGLE
