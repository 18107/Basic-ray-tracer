#include "Spherical.h"
#include <cmath>

Vec3 Spherical::rotate(const Vec2 camera, const Vec3 ray) {
	Vec3 rotated =  Vec3(0);
	rotated.x = ray.x;
	rotated.y = cos(camera.x)*ray.y - sin(camera.x)*ray.z;
	rotated.z = cos(camera.x)*ray.z + sin(camera.x)*ray.y;
	rotated.x = cos(camera.y)*ray.x - sin(camera.y)*rotated.z;
	rotated.z = cos(camera.y)*rotated.z + sin(camera.y)*ray.x;
	return rotated;
}

PsuedoRay Spherical::getRay(const Vec2 screenPos, int chunkBits, const Vec3 position, const Vec2 direction) {
	Vec2 pos = Vec2((screenPos.x*2-1)*M_PI, (screenPos.y*2-1)*M_PI/2);
	Vec3 rayDir = Vec3(sin(pos.x)*cos(pos.y), sin(pos.y), -cos(pos.x)*cos(pos.y));
	rayDir = rotate(direction, rayDir);
	return PsuedoRay(chunkBits, position, rayDir);
}
