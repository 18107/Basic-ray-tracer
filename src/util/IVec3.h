#ifndef UTIL_IVEC3_H_
#define UTIL_IVEC3_H_
#include <iostream>
#include "Vec3.h"

class IVec3 {
public:
	int x;
	int y;
	int z;

	IVec3(int x, int y, int z);

	operator Vec3() const;

	IVec3 operator +(const IVec3 vec) const;
	IVec3 operator +(const int i) const;

	IVec3 operator -(const IVec3 vec) const;
	IVec3 operator -(const int i) const;

	IVec3 operator *(const IVec3 vec) const;
	IVec3 operator *(const int i) const;

	IVec3 operator /(const IVec3 vec) const;
	IVec3 operator /(const int i) const;

	IVec3 operator %(const IVec3 vec) const;
	IVec3 operator %(const int i) const;
};

std::ostream& operator <<(std::ostream& stream, const IVec3 vec);

#endif /* UTIL_IVEC3_H_ */
