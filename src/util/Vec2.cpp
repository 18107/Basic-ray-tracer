#include "Vec2.h"

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vec2 Vec2::operator +(const Vec2 vec) const {
	return Vec2(this->x + vec.x, this->y + vec.y);
}

Vec2 Vec2::operator +(const float f) const {
	return Vec2(this->x + f, this->y + f);
}

Vec2 Vec2::operator -(const Vec2 vec) const {
	return Vec2(this->x - vec.x, this->y - vec.y);
}

Vec2 Vec2::operator -(const float f) const {
	return Vec2(this->x - f, this->y - f);
}

Vec2 Vec2::operator *(const Vec2 vec) const {
	return Vec2(this->x * vec.x, this->y * vec.y);
}

Vec2 Vec2::operator *(const float f) const {
	return Vec2(this->x * f, this->y * f);
}

Vec2 Vec2::operator /(const Vec2 vec) const {
	return Vec2(this->x / vec.x, this->y / vec.y);
}

Vec2 Vec2::operator /(const float f) const {
	return Vec2(this->x / f, this->y / f);
}

std::ostream& operator <<(std::ostream& stream, const Vec2 vec) {
	return stream << "[" << vec.x << ", " << vec.y << "]";
}
