#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <cstdint>

__global__
void calculateFractal(uint8_t* pMemory, unsigned int width, unsigned int height, unsigned int iterations)
{
	int i = threadIdx.x + blockDim.x * blockIdx.x;

	if (i < width * height)
	{
		const double xScale = (1.0 + 2.0) / width;
		const double yScale = (1.0 + 1.0) / height;

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

		pMemory[3 * i + 0] = static_cast<uint8_t>(256);
		pMemory[3 * i + 1] = static_cast<uint8_t>(256);
		pMemory[3 * i + 2] = static_cast<uint8_t>(256);
	}
}

int main()
{
	uint8_t* x;
	cudaMallocManaged(&x, 1280 * 720 * 3 * sizeof(uint8_t));
	
	calculateFractal <<<1, 1280 * 720>>> (x, 1280, 720, 64);
	cudaDeviceSynchronize();

	cudaFree(x);
	
	return 0;
}