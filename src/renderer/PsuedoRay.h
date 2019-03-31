#ifndef RENDERER_PSUEDORAY_H_
#define RENDERER_PSUEDORAY_H_
#include "../util/Vec3.h"
#include "../util/IVec3.h"
#include "../world/World.h"
#include <math.h>

class PsuedoRay {
public:
	const int chunkBits;
	IVec3 current;
	Vec3 nearestCube;
	Vec3 inc;
	IVec3 iinc;
	int steps = 0;

	PsuedoRay(int chunkBits, const Vec3 position, const Vec3 direction) :
		chunkBits(chunkBits),
		current(position.floor()%(1<<chunkBits)),
		nearestCube(((Vec3)position.ceil() - position - Vec3(direction.x >= 0 ? 0 : 1, direction.y >= 0 ? 0 : 1, direction.z >= 0 ? 0 : 1))/direction),
		inc(Vec3(direction.x == 0 ? 0 : 1/direction.x, direction.y == 0 ? 0 : 1/direction.y, direction.z == 0 ? 0 : 1/direction.z).abs()),
		iinc(IVec3(direction.x > 0 ? 1 : -1, direction.y > 0 ? 1 : -1, direction.z > 0 ? 1 : -1)) {
		if (isnan(nearestCube.x)) nearestCube.x = 1.0/0.0;
		if (isnan(nearestCube.y)) nearestCube.y = 1.0/0.0;
		if (isnan(nearestCube.z)) nearestCube.z = 1.0/0.0;
	};
	PsuedoRay(int chunkBits, const IVec3 current, const Vec3 nearestCube, const Vec3 inc, const IVec3 iinc) :
		chunkBits(chunkBits), current(current), nearestCube(nearestCube), inc(inc), iinc(iinc) {};

	void next();
};

#endif /* RENDERER_PSUEDORAY_H_ */
