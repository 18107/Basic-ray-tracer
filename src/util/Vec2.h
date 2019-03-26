#ifndef UTIL_VEC2_H_
#define UTIL_VEC2_H_
#include <iostream>

class Vec2 {
public:
	float x;
	float y;

	Vec2(float x, float y);

	Vec2 operator +(const Vec2 vec) const;
	Vec2 operator +(const float f) const;

	Vec2 operator -(const Vec2 vec) const;
	Vec2 operator -(const float f) const;

	Vec2 operator *(const Vec2 vec) const;
	Vec2 operator *(const float f) const;

	Vec2 operator /(const Vec2 vec) const;
	Vec2 operator /(const float f) const;
};

std::ostream& operator <<(std::ostream& stream, const Vec2 vec);

#endif /* UTIL_VEC2_H_ */
