#pragma once
#include <cmath>
using namespace std;
class Punto2D {
private:
	//zdouble x, y, z;

public:
	double x, y, z;
	Punto2D()
	{
		x = y = z = 0;
	}

	Punto2D(double x,double y)
	{
		this->x = x;
		this->y = y;
		this->z = 0;
	}

	double GetX()
	{
		return x;
	}

	void SetX(double x)
	{
		this->x = x;
	}

	double GetY()
	{
		return y;
	}

	void SetY(double y)
	{
		this->y = y;
	}

	const Punto2D & operator=(const Punto2D &rPunto2D)
	{
		x = rPunto2D.x;
		y = rPunto2D.y;
		z = rPunto2D.z;
		return *this;
	}


	void Trasladar(double dx, double dy)
	{
		x = dx + x;
		y = dy + y;
		/*return this;*/
	}

	void Escalar(double sx, double sy)
	{
		x = sx * x;
		y = sy * y;
		/*return this;*/
	}

	void Escalar(Punto2D* base, double sx, double sy)
	{
		Trasladar(-base->GetX(), -base->GetY());
		Escalar(sx, sy);
		Trasladar(base->GetX(), base->GetY());
		//return this;
	}

	void Rotar(double a)
	{
		double ca, sa, xp;

		ca = cos(a);
		sa = sin(a);
		xp = x*ca - y*sa;
		y = x*sa + y*ca;
		x = xp;
		/*return this;*/
	}

	Punto2D* Rotar(Punto2D* base, double a)
	{
		Trasladar(-base->GetX(), -base->GetY());
		Rotar(a);
		Trasladar(base->GetX(), base->GetY());
		return this;
	}


};