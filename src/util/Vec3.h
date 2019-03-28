#ifndef UTIL_VEC3_H_
#define UTIL_VEC3_H_
#include <iostream>

class IVec3;
class Vec3{
public:
	float x;
	float y;
	float z;

	Vec3(float x, float y, float z) : x(x), y(y), z(z) {};
	Vec3(float f) : x(f), y(f), z(f) {};

	Vec3 operator +(const Vec3 vec) const;
	Vec3 operator +(const float f) const;

	Vec3 operator -(const Vec3 vec) const;
	Vec3 operator -(const float f) const;

	Vec3 operator *(const Vec3 vec) const;
	Vec3 operator *(const float f) const;

	Vec3 operator /(const Vec3 vec) const;
	Vec3 operator /(const float f) const;

	Vec3& operator +=(const Vec3 vec);
	Vec3& operator +=(float f);

	Vec3& operator -=(const Vec3 vec);
	Vec3& operator -=(float f);

	Vec3& operator *=(const Vec3 vec);
	Vec3& operator *=(float f);

	Vec3& operator /=(const Vec3 vec);
	Vec3& operator /=(float f);

	IVec3 floor() const;
	IVec3 ceil() const;

	Vec3 abs() const;
};

Vec3 operator +(float f, const Vec3 vec);
Vec3 operator -(float f, const Vec3 vec);
Vec3 operator *(float f, const Vec3 vec);
Vec3 operator /(float f, const Vec3 vec);
std::ostream& operator <<(std::ostream& stream, const Vec3 vec);

#endif /* UTIL_VEC3_H_ */
