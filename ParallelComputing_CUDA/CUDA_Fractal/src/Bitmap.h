#pragma once

#include "BitmapHeader.h"
#include <memory>
#include <string>
#include <fstream>

class Bitmap
{
public:
	Bitmap(const int width, const int height) : 
		m_Width(width), m_Height(height),
		m_pPixels(std::make_unique<uint8_t[]>(3 * static_cast<int64_t>(width) * static_cast<int64_t>(height))),
		m_FileHeader(0),
		m_InfoHeader(width, height)
	{
		m_FileHeader.fileSize = m_FileHeader.dataOffset + 3 * m_Width * m_Height;
	}

	~Bitmap() = default;

	void SetPixel(uint64_t x, uint64_t y, uint8_t red, uint8_t green, uint8_t blue)
	{
		auto pPixel{ m_pPixels.get() };
		pPixel += 3 * y * m_Width + 3 * x;
		pPixel[0] = blue; pPixel[1] = green; pPixel[2] = red;
	}

	bool Write(std::string filename)
	{
		static const char* fileHeader{ reinterpret_cast<char*>(&m_FileHeader) };
		static const char* infoHeader{ reinterpret_cast<char*>(&m_InfoHeader) };

		std::ofstream file;
		file.open(filename, std::ios::out | std::ios::binary);

		if (!file) return false;

		file.write(fileHeader, sizeof(m_FileHeader));
		file.write(infoHeader, sizeof(m_InfoHeader));
		file.write(reinterpret_cast<char*>(m_pPixels.get()),
			3 * static_cast<int64_t>(m_Width) * static_cast<int64_t>(m_Height));
		file.close();

		if (!file) return false;

		return true;
	}

public:
	static void SaveFractal(uint8_t* pMemory, unsigned int width, unsigned int height)
	{
		static uint8_t index{ 0 };

		Bitmap image(width, height);
		for (size_t y = 0; y < height; ++y)
			for (size_t x = 0; x < width; ++x)
			{
				uint8_t* pPixel = &pMemory[3 * (y * static_cast<int64_t>(width) + x)];
				image.SetPixel(x, y, pPixel[0], pPixel[1], pPixel[2]);
			}

		std::string fileName("Fractal_Screenshot_");
		fileName.append(std::to_string(index++));
		fileName.append(".bmp");

		image.Write(fileName);
	}

private:
	const int m_Width, m_Height;
	std::unique_ptr<uint8_t[]> m_pPixels;
	BitmapFileHeader m_FileHeader;
	BitmapInfoHeader m_InfoHeader;
};
