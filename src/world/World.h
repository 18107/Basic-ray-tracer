#ifndef WORLD_WORLD_H_
#define WORLD_WORLD_H_
#include "../util/IVec3.h"
#include "../util/Vec3.h"
#include <unordered_map>
#include "Chunk.h"

class World {
public:
	const Vec3 worldSize;
	const int chunkBits = 4;
	const int chunkBitMask;
	Chunk * emptyChunk;

	std::unordered_map<std::string, Chunk*> chunks;

	World(const IVec3 worldSize) : worldSize(worldSize), chunkBitMask((1<<chunkBits)-1), emptyChunk(new Chunk(chunkBits)) {};
	World(const IVec3 worldSize, const int chunkBits) : worldSize(worldSize), chunkBits(chunkBits), chunkBitMask((1<<chunkBits)-1), emptyChunk(new Chunk(chunkBits)) {};
	~World() {
		for (auto const& pair: chunks) {
			delete pair.second;
		}
		delete emptyChunk;
	}

	void addChunk(const IVec3 chunkPos, Chunk *chunk);
	Chunk* getChunk(const IVec3 chunkPos);

private:
	inline std::string getKey(const IVec3 chunkPos);
};

#endif /* WORLD_WORLD_H_ */
