#ifndef PROJECTION_SPHERICAL_H_
#define PROJECTION_SPHERICAL_H_
#include "../renderer/PsuedoRay.h"
#include "../util/Vec2.h"
#include "../util/Vec3.h"

class Spherical {
private:
	Vec3 rotate(const Vec2 camera, const Vec3 ray);
public:
	PsuedoRay getRay(const Vec2 screenPos, int chunkBits, const Vec3 position, const Vec2 direction);
};

#endif /* PROJECTION_SPHERICAL_H_ */
