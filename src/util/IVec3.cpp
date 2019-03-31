#include "IVec3.h"
#include "Vec3.h"
#include <math.h>

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
	if (vec3.x < 0) vec3.x += vec.x;
	if (vec3.y < 0) vec3.y += vec.y;
	if (vec3.z < 0) vec3.z += vec.z;
	return vec3;
}

IVec3 IVec3::operator %(const int i) const {
	IVec3 vec3 = IVec3(this->x % i, this->y % i, this->z % i);
	if (vec3.x < 0) vec3.x += i;
	if (vec3.y < 0) vec3.y += i;
	if (vec3.z < 0) vec3.z += i;
	return vec3;
}

IVec3 IVec3::operator &(const IVec3 vec) const {
	return IVec3(this->x & vec.x, this->y & vec.y, this->z & vec.z);
}

IVec3 IVec3::operator &(const int i) const {
	return IVec3(this->x & i, this->y & i, this->z & i);
}

IVec3 IVec3::operator |(const IVec3 vec) const {
	return IVec3(this->x | vec.x, this->y | vec.y, this->z | vec.z);
}

IVec3 IVec3::operator |(const int i) const {
	return IVec3(this->x | i, this->y | i, this->z | i);
}

IVec3 IVec3::operator ^(const IVec3 vec) const {
	return IVec3(this->x ^ vec.x, this->y ^ vec.y, this->z ^ vec.z);
}

IVec3 IVec3::operator ^(const int i) const {
	return IVec3(this->x ^ i, this->y ^ i, this->z ^ i);
}

IVec3 IVec3::operator <<(const IVec3 vec) const {
	return IVec3(this->x << vec.x, this->y << vec.y, this->z << vec.z);
}

IVec3 IVec3::operator <<(const int i) const {
	return IVec3(this->x << i, this->y << i, this->z << i);
}

IVec3 IVec3::operator >>(const IVec3 vec) const {
	return IVec3(this->x >> vec.x, this->y >> vec.y, this->z >> vec.z);
}

IVec3 IVec3::operator >>(const int i) const {
	return IVec3(this->x >> i, this->y >> i, this->z >> i);
}

IVec3& IVec3::operator +=(const IVec3 vec) {
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;
	return *this;
}

IVec3& IVec3::operator +=(int i) {
	this->x += i;
	this->y += i;
	this->z += i;
	return *this;
}

IVec3& IVec3::operator -=(const IVec3 vec) {
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.z;
	return *this;
}

IVec3& IVec3::operator -=(int i) {
	this->x -= i;
	this->y -= i;
	this->z -= i;
	return *this;
}

IVec3& IVec3::operator *=(const IVec3 vec) {
	this->x *= vec.x;
	this->y *= vec.y;
	this->z *= vec.z;
	return *this;
}

IVec3& IVec3::operator *=(int i) {
	this->x *= i;
	this->y *= i;
	this->z *= i;
	return *this;
}

IVec3& IVec3::operator /=(const IVec3 vec) {
	this->x /= vec.x;
	this->y /= vec.y;
	this->z /= vec.z;
	return *this;
}

IVec3& IVec3::operator /=(int i) {
	this->x /= i;
	this->y /= i;
	this->z /= i;
	return *this;
}

IVec3& IVec3::operator &=(const IVec3 vec) {
	this->x &= vec.x;
	this->y &= vec.y;
	this->z &= vec.z;
	return *this;
}

IVec3& IVec3::operator &=(int i) {
	this->x &= i;
	this->y &= i;
	this->z &= i;
	return *this;
}

IVec3& IVec3::operator |=(const IVec3 vec) {
	this->x |= vec.x;
	this->y |= vec.y;
	this->z |= vec.z;
	return *this;
}

IVec3& IVec3::operator |=(int i) {
	this->x |= i;
	this->y |= i;
	this->z |= i;
	return *this;
}

IVec3& IVec3::operator ^=(const IVec3 vec) {
	this->x ^= vec.x;
	this->y ^= vec.y;
	this->z ^= vec.z;
	return *this;
}

IVec3& IVec3::operator ^=(int i) {
	this->x ^= i;
	this->y ^= i;
	this->z ^= i;
	return *this;
}

IVec3& IVec3::operator <<=(const IVec3 vec) {
	this->x <<= vec.x;
	this->y <<= vec.y;
	this->z <<= vec.z;
	return *this;
}

IVec3& IVec3::operator <<=(int i) {
	this->x <<= i;
	this->y <<= i;
	this->z <<= i;
	return *this;
}

IVec3& IVec3::operator >>=(const IVec3 vec) {
	this->x >>= vec.x;
	this->y >>= vec.y;
	this->z >>= vec.z;
	return *this;
}

IVec3& IVec3::operator >>=(int i) {
	this->x >>= i;
	this->y >>= i;
	this->z >>= i;
	return *this;
}

IVec3 IVec3::abs() const {
	return IVec3(std::abs(this->x), std::abs(this->y), std::abs(this->z));
}

IVec3 operator +(int i, const IVec3 vec) {
	return IVec3(i + vec.x, i + vec.y, i + vec.z);
}

IVec3 operator -(int i, const IVec3 vec) {
	return IVec3(i - vec.x, i - vec.y, i - vec.z);
}

IVec3 operator *(int i, const IVec3 vec) {
	return IVec3(i * vec.x, i * vec.y, i * vec.z);
}

IVec3 operator /(int i, const IVec3 vec) {
	return IVec3(i / vec.x, i / vec.y, i / vec.z);
}

IVec3 operator &(int i, const IVec3 vec) {
	return IVec3(i & vec.x, i & vec.y, i & vec.z);
}

IVec3 operator |(int i, const IVec3 vec) {
	return IVec3(i | vec.x, i | vec.y, i | vec.z);
}

IVec3 operator ^(int i, const IVec3 vec) {
	return IVec3(i ^ vec.x, i ^ vec.y, i ^ vec.z);
}

IVec3 operator <<(int i, const IVec3 vec) {
	return IVec3(i << vec.x, i << vec.y, i << vec.z);
}

IVec3 operator >>(int i, const IVec3 vec) {
	return IVec3(i >> vec.x, i >> vec.y, i >> vec.z);
}

std::ostream& operator <<(std::ostream& stream, const IVec3 vec) {
	return stream << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]";
}
