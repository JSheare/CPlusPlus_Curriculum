#ifndef POINT2D_H
#define POINT2D_H

class Point2d
{
private:
	double m_x{};
	double m_y{};

public:
	Point2d(double x = 0.0, double y = 0.0);

	void print() const;

	double distanceTo(const Point2d& p) const;

	friend double distanceFrom(const Point2d& p1, const Point2d p2);
};
#endif