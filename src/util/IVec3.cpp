#include "IVec3.h"

IVec3::IVec3(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

IVec3::operator Vec3() const {
	return Vec3(this->x, this->y, this->z);
}

IVec3 IVec3::operator +(const IVec3 vec) const {
	return IVec3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

IVec3 IVec3::operator +(const int i) const {
	return IVec3(this->x + i, this->y + i, this->z + i);
}

IVec3 IVec3::operator -(const IVec3 vec) const {
	return IVec3(this->x - vec.x, this->y - vec.y, this->z - vec.z);
}

IVec3 IVec3::operator -(const int i) const {
	return IVec3(this->x - i, this->y - i, this->z - i);
}

IVec3 IVec3::operator *(const IVec3 vec) const {
	return IVec3(this->x * vec.x, this->y * vec.y, this->z * vec.z);
}

IVec3 IVec3::operator *(const int i) const {
	return IVec3(this->x * i, this->y * i, this->z * i);
}

IVec3 IVec3::operator /(const IVec3 vec) const {
	return IVec3(this->x / vec.x, this->y / vec.y, this->z / vec.z);
}

IVec3 IVec3::operator /(const int i) const {
	return IVec3(this->x / i, this->y / i, this->z / i);
}

IVec3 IVec3::operator %(const IVec3 vec) const {
	IVec3 vec3 = IVec3(this->x % vec.x, this->y % vec.y, this->z % vec.z);
	if (vec3.x < 0) vec3.x = (vec3.x + vec.x) % vec.x;
	if (vec3.y < 0) vec3.y = (vec3.y + vec.y) % vec.y;
	if (vec3.z < 0) vec3.z = (vec3.z + vec.z) % vec.z;
	return vec3;
}

IVec3 IVec3::operator %(const int i) const {
	IVec3 vec3 = IVec3(this->x % i, this->y % i, this->z % i);
	if (vec3.x < 0) vec3.x = (vec3.x + i) % i;
	if (vec3.y < 0) vec3.y = (vec3.y + i) % i;
	if (vec3.z < 0) vec3.z = (vec3.z + i) % i;
	return vec3;
}

std::ostream& operator <<(std::ostream& stream, const IVec3 vec) {
	return stream << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]";
}
