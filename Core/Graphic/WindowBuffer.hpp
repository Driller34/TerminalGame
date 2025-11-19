#pragma once
#include <string>
#include "Image.hpp"
#include "../Utils/Vec.hpp"
#include "../Utils/Color.hpp"

class WindowBuffer
{
public:
	WindowBuffer(const size_t width,
		const size_t height,
		const Color& backgroundColor = {0, 0, 0, 255});

	void setColor(const Vec2i& position,
		const Color& color);
	
	void clear();

	void updateBuffer();

	std::string toString() const;

private:
	void setInBuffer(const Vec2i& position,
		const Color& color);

private:
	Image mViewImage;
	std::string mBuffer;
};