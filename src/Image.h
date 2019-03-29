#ifndef IMAGE_H_
#define IMAGE_H_
#include <string>

class Image {
private:
	char* colorData;
public:
	const int width;
	const int height;

	Image(int width, int height) : width(width), height(height) {
		colorData = new char[width*height*3];
	};
	~Image() {
		delete colorData;
	}

	bool setPixel(int x, int y, char r, char g, char b);
	bool writeImage(std::string filename);
};

#endif /* IMAGE_H_ */
