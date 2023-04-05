#include "core.h" 
#include "intersection.h" 
#include "point.h"
#include "geoUtils.h" 

bool jmk::intersect(const jmk::Point2d& a, const jmk::Point2d& b, const jmk::Point2d& c, const jmk::Point2d& d) 
{ 
	auto ab_c = jmk::orientation2d(a, b, c); 
	auto ab_d = jmk::orientation2d(a, b, d); 
	auto cd_a = jmk::orientation2d(c, d, a); 
	auto cd_b = jmk::orientation2d(c, d, b); 

	if (	ab_c == BETWEEN || ab_c == ORIGIN || ab_c == DESTINATION || 
			ab_d == BETWEEN || ab_d == ORIGIN || ab_d == DESTINATION ||
			cd_a == BETWEEN || cd_a == ORIGIN || cd_a == DESTINATION ||
			cd_b == BETWEEN || cd_b == ORIGIN || cd_b == DESTINATION  ) 
	{ 
		return true; 
	} 
	return (_xor(ab_c==LEFT,ab_d==LEFT) && _xor(cd_a== LEFT,cd_b== LEFT));
 }



bool jmk::intersect(const jmk::Point2d& a, const jmk::Point2d& b, const jmk::Point2d& c, const jmk::Point2d& d,jmk::Point2d& intersection)
{
	Vector2f AB = b - a;
	Vector2f CD = d - c;

	Vector2f n(CD[Y], -CD[X]);

	auto deno = dotProduct(n, AB);

	if (!isEqualD(deno, ZERO))
	{
		auto AC = c - a;
		auto numo = dotProduct(n, AC);

		auto t = numo / deno;

		auto x = a[X] + t * AB[X];
		auto y = a[X] + t * AB[Y];

		intersection.assign(X, x);
		intersection.assign(Y, y);

		return true;

	}
	else
	{
		return false;
	}
	return false;
}

bool jmk::intersect(const jmk::Line2d& l1, const jmk::Line2d& l2, jmk::Point2d& intersection)
{
	auto l1_start = l1.getPoint();
	auto l1_end = l1_start + l1.getDir();
	auto l2_start = l2.getPoint();
	auto l2_end = l2_start + l2.getPoint();
	return intersect(l1_start, l1_end, l2_start, l2_end, intersection);
}
