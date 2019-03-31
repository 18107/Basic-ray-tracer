#ifndef WORLD_CHUNK_H_
#define WORLD_CHUNK_H_
#include "../util/IVec3.h"

class Chunk {
private:
	const int chunkBits;

	int getIndex(IVec3 blockPos);
public:
	const int *blocks;

	Chunk(int *blocks, int chunkBits) : chunkBits(chunkBits), blocks(blocks) {};
	Chunk(int chunkBits) : chunkBits(chunkBits) {
		this->blocks = (int*)calloc(1<<this->chunkBits*3, sizeof(int));
	};
	~Chunk() {
		free((int*)blocks);
		blocks = 0;
	};

	int getBlock(const IVec3 blockPos);
};

#endif /* WORLD_CHUNK_H_ */
