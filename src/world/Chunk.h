#ifndef WORLD_CHUNK_H_
#define WORLD_CHUNK_H_
#include "../util/IVec3.h"

class Chunk {
private:
	const int chunkSize;

	int getIndex(IVec3 blockPos);
public:
	int *blocks;

	Chunk(int *blocks, int chunkSize) : chunkSize(chunkSize), blocks(blocks) {};
	Chunk(int chunkSize) : chunkSize(chunkSize) {
		std::cout << "creating chunk" << std::endl;
		this->blocks = (int*)calloc(this->chunkSize*this->chunkSize*this->chunkSize, sizeof(int));
	};
	~Chunk() {
		std::cout << "deleting chunk" << std::endl;
		free(blocks);
	};

	int getBlock(const IVec3 blockPos);
};

#endif /* WORLD_CHUNK_H_ */
