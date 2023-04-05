#include "vector.h"
#include "plane.h"
#include "intersection.h"
#include "geoUtils.h"
#include "core.h"
#include "line.h"
#include "point.h"
#include<iostream>

int main()
{
	//defining two dimenstion vectors
	jmk::Vector<float, 2> vec1(1.0f, 2.0f);
	jmk::Vector<float, 2> vec2(3.0f, 4.0f);
	jmk::Vector<float, 3> vec5(3.0f, 4.0f , 5.0f);
	jmk::Vector<float, 3> vec6(1.0f, 2.0f, 3.0f);

	//displaying stored value
	std::cout << vec1[0] << std::endl;

	//adding two vectors
	auto vec3 = vec1 + vec2;
	std::cout << vec3[0] << std::endl;

	//subtraction of teo vectors
	auto vec4 = vec1 - vec2;
	std::cout << vec4[0] << std::endl;

	//scaler 2D product
	jmk::Vector2f out = jmk::scalerproduct2D(2, vec1);
	std::cout << out[1] << std::endl;

	//scaler 3D product
	jmk::Vector3f out1 = jmk::scalerproduct3D(2, vec5); 
	std::cout << out1[1] << std::endl;

	//2D dot product 
	auto v2 = jmk::dotProduct(vec1, vec2);
	std::cout << v2 << std::endl;

	//3D dot product
	auto v3 = jmk::dotProduct(vec5, vec6);
	std::cout << v3 << std::endl;

	//2D cross product
	auto v4 = jmk::crossProduct2d(vec1, vec2);
	std::cout << v4 << std::endl;

	auto mag = vec1.magnitude();
	std::cout << mag << std::endl;

	vec1.normalize();
	std::cout << vec1[0] << std::endl;

	//creating plane object
	jmk::Plane<float> plane1(vec5, 12);
	
	//intersection of line check
	jmk::Point2d In1 = { 1,1 }; 
	jmk::Point2d In2 = { 6,5 }; 
	jmk::Point2d In3 = { 1,7 }; 
	jmk::Point2d In4 = { 6,1 }; 

	if (jmk::intersect(In1, In2, In3, In4)) 
	{ 
		std::cout << "Lines are intersecting" << std::endl; 
	}

	jmk::Point2d a(1, 2);
	jmk::Point2d b(2, 5);
	jmk::Point2d c(7, 8);

	//jmk::Vector3f a(1, 2, 3);
	//jmk::Vector3f b(4, 5, 6);
	//jmk::Vector3f c(7, 8, 9);
	double area = jmk::areaTriangle2d(a, b, c);
	std::cout << "The area of the triangle " << area << std::endl;
	

	jmk::Point2d In10 = { 1,1 };
	jmk::Point2d In20 = { 6,5 };
	jmk::Point2d In30 = { 1,7 };
	jmk::Point2d In40 = { 6,1 };
	jmk::Point2d In50;

	if (jmk::intersect(In10, In20, In30, In40, In50))
	{
		std::cout << "Interecting at point " << In50[0] << " " << In50[1] << std::endl;
	}

	jmk::Point2d In11 = { 1,1 };
	jmk::Point2d In22 = { 6,5 };
	jmk::Point2d In33 = { 1,7 };
	jmk::Point2d In44 = { 6,1 };
	jmk::Point2d In60;

	jmk::Line<float, 2> l1(In11, In22);
	jmk::Line<float, 2> l2(In33, In44);
	jmk::intersect(l1, l2, In60);

	return 0;

}
	