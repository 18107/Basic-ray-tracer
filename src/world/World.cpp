#include "World.h"

void World::addChunk(const IVec3 chunkPos, Chunk *chunk) {
	chunks.insert({getKey(chunkPos), chunk});
}

Chunk* World::getChunk(const IVec3 chunkPos) {
	return chunks.at(getKey(chunkPos));
}

inline std::string World::getKey(const IVec3 chunkPos) {
	return std::to_string(chunkPos.x) + "," + std::to_string(chunkPos.y) + "," + std::to_string(chunkPos.y);
}
