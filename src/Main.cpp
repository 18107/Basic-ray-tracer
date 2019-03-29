#include <iostream>
#include "util/Vec3.h"
#include "util/IVec3.h"
#include "world/World.h"
#include "renderer/PsuedoRay.h"
#include "projection/Spherical.h"
#include "Image.h"
#include <cmath>

World* createWorld() {
	World* world = new World(IVec3(3, 1, 3));
	Chunk* chunk = new Chunk(world->chunkBits);
	for (int y = 0; y < 1<<world->chunkBits; y++) {
		for (int x = 0; x < 1<<world->chunkBits; x++) {
			chunk->blocks[y*(1<<world->chunkBits) + x] = 1;
		}
	}
	world->addChunk(IVec3(0, 0, 0), chunk);
	chunk = new Chunk(world->chunkBits);
	for (int y = 0; y < 1<<world->chunkBits; y++) {
		for (int x = 0; x < 1<<world->chunkBits; x++) {
			chunk->blocks[y*(1<<world->chunkBits) + x] = 2;
		}
	}
	world->addChunk(IVec3(1, 0, 0), chunk);
	return world;
}

int main(int argc, char **argv) {
	int width = 1600;
	int height = 800;
	Image image = Image(width, height);
	World* world = createWorld();
	Spherical projection = Spherical();
	for (int y = -height/2; y < height/2; y++) {
		if (y % 100 == 0) {
			std::cout << y << std::endl;
		}
		for (int x = -width/2; x < width/2; x++) {
			PsuedoRay ray = projection.getRay(Vec2(0.5, 0.5), 4, Vec3(10, 10, 10), Vec2(y*M_PI/height, x*M_PI/height));
			Chunk* chunk = world->getChunk(ray.chunkPos);
			int block = 0;
			while(chunk != 0) {
				block = chunk->getBlock(ray.current);
				if (block) break;
				if (ray.next()) {
					chunk = world->getChunk(ray.chunkPos);
				}
			}
			image.setPixel(x+width/2, y+height/2, block*127, block*127, block*127);
		}
	}
	image.writeImage("test");
	std::cout << "done" << std::endl;
	delete world;
}
