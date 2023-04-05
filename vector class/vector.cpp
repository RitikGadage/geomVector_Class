#include "vector.h"

//template<typename coordinate_type, size_t dimensions>



jmk::Vector2f jmk::scalerproduct2D(float x, Vector2f v1) 
{	float x_, y_;
	x_ = v1[X] * x; 
	y_ = v1[Y] * x; 
	return Vector2f(x_, y_); 
} 
jmk::Vector3f jmk::scalerproduct3D(float x, Vector3f v1) 
{	float x_, y_,z_; 
	x_ = v1[X] * x; 
	y_ = v1[Y] * x;
	z_ = v1[Z] * x; 
	return Vector3f(x_, y_,z_); 
}

/*
    u(u1,u2,u3), v(v1,v2,v3)
          x  y  z
        | u1 u2 u3 |
        | v1 v2 v3 |
        Cross product (u X v) = (u2 * v3 - u3 * v2)x + (u3 * v1 - u1 * v3)y + (u1 * v2 - u2 * v1)z;
 */

float jmk::crossProduct2d(Vector2f a, Vector2f b)
{
	float x_;
	x_ = a[X] * b[Y] - b[X] * a[Y];


	return (x_);
}

jmk::Vector3f jmk::crossProduct3d(Vector3f a, Vector3f b)
{
	float x_, y_, z_;
	x_ = a[Y] * b[Z] - b[Y] * a[Z];
	y_ = -(b[Z] * a[X] - a[Z] * b[X]);
	z_ = a[X] * b[Y] - b[X] * a[Y];

	return Vector3f(x_, y_, z_);
}




float jmk::scalerTripleProduct(Vector3f a, Vector3f b, Vector3f c)
{
	Vector3f b_cross_c = crossProduct3d(b, c);
	float value = dotProduct(a, b_cross_c);
	return value;
}

bool jmk::orthogonal(Vector3f a, Vector3f b)
{
	float value = dotProduct(a, b);
	return isEqualD(value, 0.0);
}

jmk::Vector2f jmk::prependicluar(Vector2f& vec)
{
	return Vector2f(vec[Y], -vec[X]);
}