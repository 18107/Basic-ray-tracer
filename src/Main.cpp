#include <iostream>
#include "util/Vec3.h"
#include "util/IVec3.h"
#include "world/World.h"
#include "renderer/PsuedoRay.h"
#include "projection/Spherical.h"
#include "Image.h"
#include <cmath>

int getRandomColor(bool transparancy) {
	int colors[] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0x00FFFF, 0xFF00FF};
	int color = colors[rand()%6];
	if (transparancy && rand()%16) {
		color = 0;
	}
	return color;
}

World* createWorld() {
	World* world = new World(IVec3(3, 1, 3));
	int * blocks = (int*) calloc(1<<world->chunkBits*3, sizeof(int));
	for (int z = 0; z < 1<<world->chunkBits; z++) {
		for (int y = 0; y < 1<<world->chunkBits; y++) {
			for (int x = 0; x < 1<<world->chunkBits; x++) {
				blocks[z*(1<<world->chunkBits*2) + y*(1<<world->chunkBits) + x] = getRandomColor(true);
			}
		}
	}
	Chunk* chunk = new Chunk(blocks, world->chunkBits);
	world->addChunk(IVec3(0, 0, -1), chunk);
	blocks = (int*) calloc(1<<world->chunkBits*3, sizeof(int));
	for (int z = 0; z < 1<<world->chunkBits; z++) {
		for (int y = 0; y < 1<<world->chunkBits; y++) {
			for (int x = 0; x < 1<<world->chunkBits; x++) {
				blocks[z*(1<<world->chunkBits*2) + y*(1<<world->chunkBits) + x] = getRandomColor(true)&0xB2B2B2;
			}
		}
	}
	chunk = new Chunk(blocks, world->chunkBits);
	world->addChunk(IVec3(0, 0, 1), chunk);
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
			PsuedoRay ray = projection.getRay(Vec2(0.5, 0.5), 4, Vec3(8, 8, 8), Vec2(y*M_PI/height, x*M_PI/height));
			Chunk* chunk = world->getChunk(ray.current>>world->chunkBits);
			int block = 0;
			while(chunk != 0) {
				block = chunk->getBlock(ray.current & world->chunkBitMask);
				if (block) break;
				ray.next();
				chunk = world->getChunk(ray.current>>world->chunkBits);
			}
			image.setPixel(x+width/2, y+height/2, (block>>16)&0xFF, (block>>8)&0xFF, block&0xFF);
		}
	}
	image.writeImage("test");
	std::cout << "done" << std::endl;
	delete world;
}
