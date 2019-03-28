#ifndef RENDERER_PSUEDORAY_H_
#define RENDERER_PSUEDORAY_H_
#include "../util/Vec3.h"
#include "../util/IVec3.h"
#include "../world/World.h"

class PsuedoRay {
public:
	const int chunkBits;
	const int chunkSize;
	IVec3 chunkPos;
	IVec3 current;
	Vec3 nearestCube;
	Vec3 inc;
	IVec3 iinc;

	PsuedoRay(const IVec3 worldSize, int chunkBits, const Vec3 position, const Vec3 direction) :
		chunkBits(chunkBits),
		chunkSize(1<<chunkBits),
		chunkPos((position/chunkSize).floor()),
		current(position.floor()%chunkSize),
		nearestCube(((Vec3)position.ceil() - position - Vec3(direction.x >= 0 ? 0 : 1, direction.y >= 0 ? 0 : 1, direction.z >= 0 ? 0 : 1))/direction),
		inc(Vec3(direction.x == 0 ? 0 : 1/direction.x, direction.y == 0 ? 0 : 1/direction.y, direction.z == 0 ? 0 : 1/direction.z).abs()),
		iinc(IVec3(direction.x > 0 ? 1 : -1, direction.y > 0 ? 1 : -1, direction.z > 0 ? 1 : -1)) {};
	PsuedoRay(int chunkBits, const IVec3 chunkPos, const IVec3 current, const Vec3 nearestCube, const Vec3 inc, const IVec3 iinc) :
		chunkBits(chunkBits), chunkSize(1<<chunkBits), chunkPos(chunkPos), current(current), nearestCube(nearestCube), inc(inc), iinc(iinc) {};

	bool next();
};

#endif /* RENDERER_PSUEDORAY_H_ */
