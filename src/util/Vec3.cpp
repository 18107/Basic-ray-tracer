#include "Vec3.h"
#include "IVec3.h"
#include <math.h>

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

Vec3& Vec3::operator +=(const Vec3 vec) {
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;
	return *this;
}

Vec3& Vec3::operator +=(float f) {
	this->x += f;
	this->y += f;
	this->z += f;
	return *this;
}

Vec3& Vec3::operator -=(const Vec3 vec) {
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.z;
	return *this;
}

Vec3& Vec3::operator -=(float f) {
	this->x -= f;
	this->y -= f;
	this->z -= f;
	return *this;
}

Vec3& Vec3::operator *=(const Vec3 vec) {
	this->x *= vec.x;
	this->y *= vec.y;
	this->z *= vec.z;
	return *this;
}

Vec3& Vec3::operator *=(float f) {
	this->x *= f;
	this->y *= f;
	this->z *= f;
	return *this;
}

Vec3& Vec3::operator /=(const Vec3 vec) {
	this->x /= vec.x;
	this->y /= vec.y;
	this->z /= vec.z;
	return *this;
}

Vec3& Vec3::operator /=(float f) {
	this->x /= f;
	this->y /= f;
	this->z /= f;
	return *this;
}

IVec3 Vec3::floor() const {
	return IVec3((int)std::floor(this->x), (int)std::floor(this->y), (int)std::floor(this->z));
}

IVec3 Vec3::ceil() const {
	return IVec3((int)std::ceil(this->x), (int)std::ceil(this->y), (int)std::ceil(this->z));
}

Vec3 Vec3::abs() const {
	return Vec3(std::abs(this->x), std::abs(this->y), std::abs(this->z));
}

Vec3 operator +(float f, const Vec3 vec) {
	return Vec3(f + vec.x, f + vec.y, f + vec.z);
}

Vec3 operator -(float f, const Vec3 vec) {
	return Vec3(f - vec.x, f - vec.y, f - vec.z);
}

Vec3 operator *(float f, const Vec3 vec) {
	return Vec3(f * vec.x, f * vec.y, f * vec.z);
}

Vec3 operator /(float f, const Vec3 vec) {
	return Vec3(f / vec.x, f / vec.y, f / vec.z);
}

std::ostream& operator <<(std::ostream& stream, const Vec3 vec) {
	return stream << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]";
}
