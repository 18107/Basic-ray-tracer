#ifndef UTIL_VEC3_H_
#define UTIL_VEC3_H_
#include <iostream>

class Vec3{
public:
	float x;
	float y;
	float z;

	Vec3(float x, float y, float z);

	Vec3 operator +(const Vec3 vec) const;
	Vec3 operator +(const float f) const;

	Vec3 operator -(const Vec3 vec) const;
	Vec3 operator -(const float f) const;

	Vec3 operator *(const Vec3 vec) const;
	Vec3 operator *(const float f) const;

	Vec3 operator /(const Vec3 vec) const;
	Vec3 operator /(const float f) const;
};

std::ostream& operator <<(std::ostream& stream, const Vec3 vec);

#endif /* UTIL_VEC3_H_ */
