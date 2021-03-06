#include "PsuedoRay.h"

//returns true if chunkPos changed
void PsuedoRay::next() {
	steps++;
	IVec3 mask = IVec3(0);
	if (nearestCube.x <= nearestCube.y) {
		if (nearestCube.x < nearestCube.z) {
			mask.x = 1;
		} else {
			mask.z = 1;
		}
	} else {
		if (nearestCube.y < nearestCube.z) {
			mask.y = 1;
		} else {
			mask.z = 1;
		}
	}
	nearestCube += inc*mask;
	current += iinc*mask;
}
