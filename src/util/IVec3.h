#ifndef UTIL_IVEC3_H_
#define UTIL_IVEC3_H_
#include <iostream>

class Vec3;
class IVec3 {
public:
	int x;
	int y;
	int z;

	IVec3(int x, int y, int z) : x(x), y(y), z(z) {};
	IVec3(int i) : x(i), y(i), z(i) {};

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

	IVec3 operator &(const IVec3 vec) const;
	IVec3 operator &(const int i) const;

	IVec3 operator |(const IVec3 vec) const;
	IVec3 operator |(const int i) const;

	IVec3 operator ^(const IVec3 vec) const;
	IVec3 operator ^(const int i) const;

	IVec3 operator <<(const IVec3 vec) const;
	IVec3 operator <<(const int i) const;

	IVec3 operator >>(const IVec3 vec) const;
	IVec3 operator >>(const int i) const;

	IVec3& operator +=(const IVec3 vec);
	IVec3& operator +=(int i);

	IVec3& operator -=(const IVec3 vec);
	IVec3& operator -=(int i);

	IVec3& operator *=(const IVec3 vec);
	IVec3& operator *=(int i);

	IVec3& operator /=(const IVec3 vec);
	IVec3& operator /=(int i);

	IVec3& operator &=(const IVec3 vec);
	IVec3& operator &=(int i);

	IVec3& operator |=(const IVec3 vec);
	IVec3& operator |=(int i);

	IVec3& operator ^=(const IVec3 vec);
	IVec3& operator ^=(int i);

	IVec3& operator <<=(const IVec3 vec);
	IVec3& operator <<=(int i);

	IVec3& operator >>=(const IVec3 vec);
	IVec3& operator >>=(int i);

	IVec3 abs() const;
};

IVec3 operator +(int i, const IVec3 vec);
IVec3 operator -(int i, const IVec3 vec);
IVec3 operator *(int i, const IVec3 vec);
IVec3 operator /(int i, const IVec3 vec);

IVec3 operator &(int i, const IVec3 vec);
IVec3 operator |(int i, const IVec3 vec);
IVec3 operator ^(int i, const IVec3 vec);

IVec3 operator <<(int i, const IVec3 vec);
IVec3 operator >>(int i, const IVec3 vec);

std::ostream& operator <<(std::ostream& stream, const IVec3 vec);

#endif /* UTIL_IVEC3_H_ */
