#include "Chunk.h"

int Chunk::getBlock(IVec3 blockPos) {
	return blocks[getIndex(blockPos)];
};

int Chunk::getIndex(const IVec3 blockPos) {
	int index = blockPos.z*(1 << this->chunkBits*2) + blockPos.y*(1 << this->chunkBits) + blockPos.x;
	if (index < 0 || index >= (1 << chunkBits*3)) {
		throw std::invalid_argument("Index " + std::to_string(index) + " out of range.");
	}
	return index;
}
