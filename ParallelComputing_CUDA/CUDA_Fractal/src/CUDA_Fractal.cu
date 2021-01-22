#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include "Bitmap.h"

#include <cstdint>
#include <string>

// Function that generates a Bitmap Image with the fractal
void SaveFractal(uint8_t* pMemory, unsigned int width, unsigned int height)
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

// Function that performs the fractal computation using CUDA
__global__ void calculateFractal(uint8_t* pMemory, unsigned int width, unsigned int height, unsigned int iterations)
{
	int i = threadIdx.x + blockDim.x * blockIdx.x;

	if (i < width * height)
	{
		const double xScale = (3.0) / width;
		const double yScale = (2.0) / height;

		double cr = 1.0 + (i % width) * xScale;
		double ci = 2.0 + (i / width) * yScale;
		double zr = 0.0;
		double zi = 0.0;

		int n = 0;

		while ((zr * zr + zi * zi) < 4.0 && n < iterations)
		{
			zr = zr * zr - zi * zi + cr;
			zi = zr * zi * 2.0 + ci;
			n++;
		}

		if (n < iterations)
		{
			pMemory[3 * i + 0] = static_cast<uint8_t>(255);
			pMemory[3 * i + 1] = static_cast<uint8_t>(255);
			pMemory[3 * i + 2] = static_cast<uint8_t>(255);
		}
	}
}

int main()
{
	uint8_t* x;
	const unsigned int width = 1280, height = 720;
	const unsigned int N = width * height, iterations = 128;

	// Allocate Unified Memory
	cudaMallocManaged(&x, N * 3 * sizeof(uint8_t));
	
	// Calculate Fractal
	calculateFractal <<<1, N>>> (x, width, height, iterations);
	cudaDeviceSynchronize();

	// Save Fractal to a Bitmap
	SaveFractal(x, width, height);

	// Free Memory
	cudaFree(x);
	
	return 0;
}