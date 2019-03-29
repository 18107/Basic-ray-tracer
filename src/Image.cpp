#include "Image.h"
#include <iostream>
#include <fstream>

bool Image::setPixel(int x, int y, char r, char g, char b) {
	if (x >= width || y >= height) {
		return false;
	}
	colorData[y*width*3 + x*3] = b;
	colorData[y*width*3 + x*3 + 1] = g;
	colorData[y*width*3 + x*3 + 2] = r;
	return true;
}

bool Image::writeImage(std::string fileName) {
	int rowPadding = (4-(width*3)%4)%4;
	int fileSize = (width*3+rowPadding)*height*4 + 54;
	char fileHeader[14];
	fileHeader[0] = 'B'; //'BM' (little-endian)
	fileHeader[1] = 'M';
	fileHeader[2] = fileSize&0xFF; //size of the file in bytes
	fileHeader[3] = (fileSize>>8)&0xFF;
	fileHeader[4] = (fileSize>>16)&0xFF;
	fileHeader[5] = (fileSize>>24)&0xFF;
	fileHeader[6] = 0; //reserved
	fileHeader[7] = 0;
	fileHeader[8] = 0; //reserved
	fileHeader[9] = 0;
	fileHeader[10] = 54; //bitmap start address
	fileHeader[11] = 0;
	fileHeader[12] = 0;
	fileHeader[13] = 0;
	char bitHeader[40];
	bitHeader[0] = 40; //header size
	bitHeader[1] = 0;
	bitHeader[2] = 0;
	bitHeader[3] = 0;
	bitHeader[4] = width&0xFF; //bitmap width in pixels
	bitHeader[5] = (width>>8)&0xFF;
	bitHeader[6] = (width>>16)&0xFF;
	bitHeader[7] = (width>>24)&0xFF;
	bitHeader[8] = height&0xFF; //bitmap height in pixels
	bitHeader[9] = (height>>8)&0xFF;
	bitHeader[10] = (height>>16)&0xFF;
	bitHeader[11] = (height>>24)&0xFF;
	bitHeader[12] = 1; //color panes (must be 1)
	bitHeader[13] = 0;
	bitHeader[14] = 24; //bits per pixel
	bitHeader[15] = 0;
	for (int i = 16; i < 40; i++) {
		bitHeader[i] = 0;
	}
	std::ofstream file;
	file.open(fileName + ".bmp", std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);
	if (!file.is_open()) {
		return false;
	}
	file.write(fileHeader, 14);
	file.write(bitHeader, 40);
	for (int i = 0; i < height; i++) {
		file.write(colorData + i*width*3, width*3);
		if (rowPadding > 0) {
			file.write(fileHeader+6, rowPadding); //pad with zeros to a multiple of 4
		}
	}
	file.close();
	return true;
}
