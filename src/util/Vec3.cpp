#include "Vec3.h"

Vec3::Vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3 Vec3::operator +(const Vec3 vec) const {
	return Vec3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

Vec3 Vec3::operator +(float f) const {
	return Vec3(this->x + f, this->y + f, this->z + f);
}

Vec3 Vec3::operator -(const Vec3 vec) const {
	return Vec3(this->x - vec.x, this->y - vec.y, this->z - vec.z);
}

Vec3 Vec3::operator -(const float f) const {
	return Vec3(this->x - f, this->y - f, this->z - f);
}

Vec3 Vec3::operator *(const Vec3 vec) const {
	return Vec3(this->x * vec.x, this->y * vec.y, this->z * vec.z);
}

Vec3 Vec3::operator *(const float f) const {
	return Vec3(this->x * f, this->y * f, this->z * f);
}

Vec3 Vec3::operator /(const Vec3 vec) const {
	return Vec3(this->x / vec.x, this->y / vec.y, this->z / vec.z);
}

Vec3 Vec3::operator /(const float f) const {
	return Vec3(this->x / f, this->y / f, this->z / f);
}

std::ostream& operator <<(std::ostream& stream, const Vec3 vec) {
	return stream << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]";
}
