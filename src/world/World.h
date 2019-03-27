#ifndef WORLD_WORLD_H_
#define WORLD_WORLD_H_
#include "../util/IVec3.h"
#include <unordered_map>
#include "Chunk.h"

class World {
public:
	const IVec3 worldSize;
	const int chunkSize = 16;

	std::unordered_map<std::string, Chunk*> chunks;

	World(const IVec3 worldSize) : worldSize(worldSize) {};
	World(const IVec3 worldSize, const int chunkSize) : worldSize(worldSize), chunkSize(chunkSize) {};
	~World() {
		for (auto const& pair: chunks) {
			delete pair.second;
		}
	}

	void addChunk(const IVec3 chunkPos, Chunk *chunk);
	Chunk* getChunk(const IVec3 chunkPos);

private:
	inline std::string getKey(const IVec3 chunkPos);
};

#endif /* WORLD_WORLD_H_ */
