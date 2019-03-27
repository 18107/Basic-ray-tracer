#include "Chunk.h"

int Chunk::getBlock(IVec3 blockPos) {
	return blocks[getIndex(blockPos)];
};

int Chunk::getIndex(const IVec3 blockPos) {
	int index = blockPos.z*this->chunkSize*this->chunkSize + blockPos.y*this->chunkSize + blockPos.x;
	if (index < 0 || index >= chunkSize*chunkSize*chunkSize) {
		throw std::invalid_argument("Index " + std::to_string(index) + " out of range.");
	}
	return index;
}
